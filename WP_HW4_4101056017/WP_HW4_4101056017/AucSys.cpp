#include "stdafx.h"

AucSys::AucSys(void)
{
}

AucSys::AucSys(String^ JsonFileName)
{
	AucSys(IO::File::Open(JsonFileName,IO::FileMode::OpenOrCreate));
}

AucSys::AucSys(IO::FileStream^ JsonFile)
{
	JsonFileName = JsonFile->Name;
	products = gcnew Collections::Generic::List<AucProduct^>();
	users = gcnew Collections::Generic::List<AucRole^>();
	bids = gcnew Collections::Generic::List<AucBid^>();

	String^ d = (gcnew IO::StreamReader(JsonFile))->ReadToEnd();
	JsonFile->Close();
	AucSys^ a = gcnew AucSys();
	a = JsonConvert::DeserializeAnonymousType<AucSys^>(d,a);

	try {this->bids = a->bids; } catch (Exception^ e){ this->bids = gcnew List<AucBid^>(); }
	try {this->products = a->products; } catch (Exception^ e){ this->products = gcnew List<AucProduct^>(); }
	try {this->users = a->users; } catch (Exception^ e){ this->users = gcnew List<AucRole^>(); }
}

void AucSys::save()
{
	String^ d = JsonConvert::SerializeObject(this,Formatting::Indented);
	IO::FileStream^ f = IO::File::Open(JsonFileName,IO::FileMode::Truncate);
	IO::StreamWriter^ s = gcnew IO::StreamWriter(f);

	s->Write(d);
	s->Close();
	f->Close();
}

AucRole^ AucSys::getUser(String^ name,Boolean^ orCreate)
{
	for each (AucRole^ u in users)
	{
		if(name->Equals(u->name))
			return u;
	}
	if(!*orCreate)
		throw gcnew Exception("User not found!");
	AucRole^ u = gcnew AucRole(name,gcnew UInt32(users->Count));
	users->Add(u);
	return u;
}

AucRole^ AucSys::getUser(String^ name)
{
	return getUser(name,gcnew Boolean(false));
}
