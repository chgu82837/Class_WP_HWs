#pragma once

ref class AucRole :
public AucBase
{
public:
	AucRole(void);
	AucRole(String^ name,UInt32^ key);

	String^ name;
	UInt32^ key;
	Collections::Generic::List<AucRela^>^ products;
	Collections::Generic::List<AucRela^>^ bids;
};
