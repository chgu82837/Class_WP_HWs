#include "stdafx.h"

AucRela::AucRela(UInt32^ src_index,UInt32^ target_index)
{
    src = src_index;
    target = target_index;
}

AucProduct^ AucRela::getTargetAsProduct()
{
    return AucRela::a->products[*(this->getTarget())];
}

AucBid^ AucRela::getTargetAsBid()
{
	return AucRela::a->bids[*(this->getTarget())];
}

AucRole^ AucRela::getSrcAsRole()
{
	return AucRela::a->users[*(this->getSrc())];
}

AucProduct^ AucRela::getSrcAsProduct()
{
	return AucRela::a->products[*(this->getSrc())];
}

UInt32^ AucRela::getTarget()
{
	if(target->GetType() != UInt32::typeid)
		target = Convert::ToUInt32(target);
	return target;
}

UInt32^ AucRela::getSrc()
{
	if(src->GetType() != UInt32::typeid)
		src = Convert::ToUInt32(src);
	return src;
}