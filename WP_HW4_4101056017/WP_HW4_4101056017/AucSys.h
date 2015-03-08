#pragma once

ref class AucSys
{
public:
	AucSys(void);
	AucSys(IO::FileStream^ JsonFile);
	AucSys(String^ JsonFileName);

	Collections::Generic::List<AucProduct^>^ products;
	Collections::Generic::List<AucRole^>^ users;
	Collections::Generic::List<AucBid^>^ bids;

	void save();
	AucRole^ getUser(String^ name);
	AucRole^ getUser(String^ name,Boolean^ orCreate);

private:
	String^ JsonFileName;
};
