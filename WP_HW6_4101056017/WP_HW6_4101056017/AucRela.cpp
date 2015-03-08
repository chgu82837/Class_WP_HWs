#include "stdafx.h"

ASys AucBase::sys;

AucRela::AucRela(Json::Value* Json)
{
	#define json (*Json)
	if(!json.isObject())
		throw new CString("Json for AucRela not valid!");

	#define addint(X) if(!json[#X].isInt()) throw new CString("Json for AucRela not valid!"); this->X = json[#X].asInt();
	addint(src)
	addint(target)

	/*
		{
			"src": 0,
			"target": 0
		}
	*/
}

AucRela::AucRela(int src_index,int target_index)
{
	this->src = src_index;
	this->target = target_index;
}

AucRela::~AucRela(void)
{
}

AProduct AucRela::getTargetAsProduct()
{
	return (*(sys->products))[target];
}

ABid AucRela::getTargetAsBid()
{
	return (*(sys->bids))[target];
}

ARole AucRela::getSrcAsRole()
{
	return (*(sys->users))[src];
}

AProduct AucRela::getSrcAsProduct()
{
	return (*(sys->products))[src];
}

Json::Value* AucRela::toJson()
{
	Json::Value* r = new Json::Value();

	#define R (*r)
	R["src"] = this->src;
	R["target"] = this->target;

	return r;
}