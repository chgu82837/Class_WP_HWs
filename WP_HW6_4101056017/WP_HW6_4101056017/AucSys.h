#pragma once
class AucSys
{
public:
	AucSys();
	AucSys(String JsonFileName);
	AucSys(CFile* JsonFile);
	AucSys(Json::Value* Json);
	~AucSys(void);

	void read(String JsonFileName);
	void read(CFile* JsonFile);
	void read(Json::Value* Json);

	AucProducts products;
	AucRoles users;
	AucBids bids;

	ARole getUser(String name);
	ARole getUser(String name,bool* orCreate);

	void save(String JsonFileName);
	void save(CFile* JsonFile);
	Json::Value* toJson();

private:
	//String JsonFileName;
};

