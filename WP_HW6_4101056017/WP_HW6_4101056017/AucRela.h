#pragma once

class AucRela :
	public AucBase
{
public:
	AucRela(Json::Value* Json);
	AucRela(int src_index,int target_index);

	~AucRela(void);

    int src;
    int target;

    AProduct getTargetAsProduct();
    ABid getTargetAsBid();
    ARole getSrcAsRole();
    AProduct getSrcAsProduct();

	Json::Value* toJson();
};

