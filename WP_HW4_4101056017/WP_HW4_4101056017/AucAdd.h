#pragma once

ref class AucAdd
{
public:
	AucAdd(AucSeller^ s);
	void prompt();
	void check();
	AucProduct^ getProduct();
	void save(AucSys^ a);
private:
	AucSeller^ s;
	AucProduct^ p;
};