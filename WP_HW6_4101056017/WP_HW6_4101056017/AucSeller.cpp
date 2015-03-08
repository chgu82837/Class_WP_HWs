#include "stdafx.h"

AucSeller::AucSeller(void)
{
}

AucSeller::AucSeller(ARole role)
{
	name = role->name;
	products = role->products;
	key = role->key;
}

AucSeller::~AucSeller(void)
{
}
