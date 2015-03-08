#pragma once
class AucBase
{
public:
	AucBase(void);
	~AucBase(void);

	static void setAucSys(ASys sys);
protected:
	static ASys sys;
};

