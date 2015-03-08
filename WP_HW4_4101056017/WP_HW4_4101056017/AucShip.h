#pragma once

ref class AucShip
{
public:
	AucShip(AucSeller^ s,AucProduct^ p);
	Boolean^ check();
	List<String^>^ list();
	void ship(UInt32^ index);
	void shipAll();
	void close();
private:
	AucSeller^ s;
	AucProduct^ p;
	Boolean^ ended;
};

