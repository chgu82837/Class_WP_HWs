#pragma once

ref class AucBase
{
public:
	AucBase(void);

	static void setAucSys(AucSys^ a);
protected:
	static AucSys^ a;
};
