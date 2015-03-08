#include "stdafx.h"

AucRole::AucRole(void)
{
}

AucRole::AucRole(Json::Value* Json)
{
	#define json (*Json)
	if(!json.isObject())
		throw new CString("Json for AucRole not valid!");

	if(!json["name"].isString())
		throw new CString("Json for AucRole not valid!");
	this->name = new CString(json["name"].asCString());

	if(!json["key"].isInt())
		throw new CString("Json for AucRole not valid!");
	this->key = json["key"].asInt();

	Json::Value tmp = json["products"];
	if(!tmp.isArray())
		throw new CString("Json for AucRole not valid!");
	products = new vector<ARela>();
	for (int i = 0; i < tmp.size(); i++)
		products->push_back(new AucRela(&tmp[i]));

	tmp = json["bids"];
	if(!tmp.isArray())
		throw new CString("Json for AucRole not valid!");
	bids = new vector<ARela>();
	for (int i = 0; i < tmp.size(); i++)
		bids->push_back(new AucRela(&tmp[i]));

	/*
		{
		  "name": "pastleo",
		  "key": 0,
		  "products": [
			{
			  "src": 0,
			  "target": 0
			}
		  ],
		  "bids": [
			{
			  "src": 0,
			  "target": 0
			}
		  ]
		},
	*/
}

AucRole::AucRole(String name,int key)
{
	this->name = name;
	this->key = key;
	this->products = new vector<ARela>();
	this->bids = new vector<ARela>();
}

AucRole::~AucRole(void)
{
}

Json::Value* AucRole::toJson()
{
	Json::Value* r = new Json::Value();
	Json::Value* vec;
	#define R (*r)

	CT2A tmp(*(this->name));
	R["name"] = tmp.m_psz;
	R["key"] = this->key;

#define addArr(X) vec = new Json::Value(Json::arrayValue); for (int i = 0; i < X->size(); i++) vec->append(*(pV(X,i)->toJson())); R[#X] = *vec;
	addArr(products)
	addArr(bids)

	return r;
}