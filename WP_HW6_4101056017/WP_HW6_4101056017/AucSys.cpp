#include "stdafx.h"

AucSys::AucSys()
{
	this->bids = new vector<ABid>();
	this->products = new vector<AProduct>();
	this->users = new vector<ARole>();
}

AucSys::AucSys(String JsonFileName){ read(JsonFileName); }
void AucSys::read(String JsonFileName){
	CFile f(*JsonFileName,CFile::modeRead | CFile::typeUnicode);
	read(&f);
}

AucSys::AucSys(CFile* JsonFile){ read(JsonFile); }
void AucSys::read(CFile* JsonFile)
{
	long long length = JsonFile->GetLength();
	char* tmp = new char[length];
	JsonFile->Read(tmp,length);
	string src(tmp);
	delete tmp;
	JsonFile->Close();
	
	Json::Reader reader;
    Json::Value rootV;

    if(!reader.parse(src,rootV,false))
		throw new CString("Json File not valid!");
	read(&rootV);
}

AucSys::AucSys(Json::Value* Json){ read(Json); }
void AucSys::read(Json::Value* Json)
{
#define json (*Json)
	Json::Value tmp;
	if(!json.isObject())
		throw new CString("Json for AucSys not valid!");

	tmp = json["users"];
	if(!tmp.isArray())
		throw new CString("Json for AucSys not valid!");
	users = new vector<ARole>();
	for (int i = 0; i < tmp.size(); i++)
		users->push_back(new AucRole(&tmp[i]));

	tmp = json["products"];
	if(!tmp.isArray())
		throw new CString("Json for AucSys not valid!");
	products = new vector<AProduct>();
	for (int i = 0; i < tmp.size(); i++)
		products->push_back(new AucProduct(&tmp[i]));

	tmp = json["bids"];
	if(!tmp.isArray())
		throw new CString("Json for AucSys not valid!");
	bids = new vector<ABid>();
	for (int i = 0; i < tmp.size(); i++)
		bids->push_back(new AucBid(&tmp[i]));
}

AucSys::~AucSys(void)
{
}

ARole AucSys::getUser(String name)
{
	return getUser(name,false);
}

ARole AucSys::getUser(String name,bool* orCreate)
{
	for (int i = 0; i < users->size(); i++)
	{
		if(((*users)[i]->name->Compare(*name)) == 0)
			return (*users)[i];
	}
	if(!(*orCreate))
		throw new CString("User not found!");
	*orCreate = !(*orCreate);
	ARole u = new AucRole(name,users->size());
	users->push_back(u);
	return u;
}

void AucSys::save(String JsonFileName)
{
	CFile f(*JsonFileName,CFile::modeWrite | CFile::modeCreate | CFile::typeUnicode);
	save(&f);
}

void AucSys::save(CFile* JsonFile)
{
	Json::StyledWriter* jwritter = new Json::StyledWriter();
	string buffer = jwritter->write(*(toJson()));
	JsonFile->Write(buffer.c_str(),buffer.size());
	JsonFile->Close();
	delete jwritter;
}

Json::Value* AucSys::toJson()
{
	Json::Value* r = new Json::Value();
	Json::Value* vec;
	#define R (*r)
#define addArr(X) vec = new Json::Value(Json::arrayValue); for (int i = 0; i < X->size(); i++) vec->append(*(pV(X,i)->toJson())); R[#X] = *vec;
	addArr(products)
	addArr(users)
	addArr(bids)

	return r;
}
