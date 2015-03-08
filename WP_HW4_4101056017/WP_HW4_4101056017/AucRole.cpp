#include "stdafx.h"

AucRole::AucRole()
{
}

AucRole::AucRole(String^ name,UInt32^ key)
{
	this->key = key;
	this->name = name;
	products = gcnew Collections::Generic::List<AucRela^>();
	bids = gcnew Collections::Generic::List<AucRela^>();
}