#pragma once

ref class AucRela :
public AucBase
{
public:
    AucRela(UInt32^ src_index,UInt32^ target_index);

    UInt32^ src;
    UInt32^ target;

	UInt32^ getSrc();
	UInt32^ getTarget();

    AucProduct^ getTargetAsProduct();
    AucBid^ getTargetAsBid();
    AucRole^ getSrcAsRole();
    AucProduct^ getSrcAsProduct();
};
