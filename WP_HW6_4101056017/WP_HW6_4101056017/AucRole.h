#pragma once

class AucRole :
	public AucBase
{
public:
	AucRole(void);
	AucRole(Json::Value*);
	AucRole(String name,int key);

	~AucRole(void);

	Json::Value* toJson();

	String name;
	int key;

	AucRelas products;
	AucRelas bids;
};

