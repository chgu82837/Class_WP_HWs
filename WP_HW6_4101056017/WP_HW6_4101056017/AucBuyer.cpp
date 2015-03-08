#include "stdafx.h"

AucBuyer::AucBuyer(void)
{
}

AucBuyer::AucBuyer(ARole role)
{
	name = role->name;
	bids = role->bids;
	key = role->key;
}

AucBuyer::~AucBuyer(void)
{
}
