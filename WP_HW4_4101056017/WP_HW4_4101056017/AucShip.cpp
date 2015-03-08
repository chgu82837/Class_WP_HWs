#include "stdafx.h"

AucShip::AucShip(AucSeller^ s,AucProduct^ p)
{
	this->s = s;
	this->p = p;
}

Boolean^ AucShip::check()
{
	Boolean^ result = p->ended();
	if(*result){
		array<UInt32^>^ sort_data = gcnew array<UInt32^>(p->bids->Count);
		array<UInt32^>^ seq = gcnew array<UInt32^>(p->bids->Count);
		UInt32^ i = gcnew UInt32(0);

		for each (AucRela^ b in p->bids){
			sort_data[*i] = b->getTargetAsBid()->price;
			seq[*i] = gcnew UInt32(*i);
			(*i)++;
		}

		Array::Sort(sort_data,seq);

		for (*i = 0; *i < *(p->quantity); (*i)++)
			*(p->bids[*seq[*i]]->getTargetAsBid()->got) = true;
	}
	return result;
}

List<String^>^ AucShip::list()
{
	List<String^>^ result = gcnew List<String^>();
	for each (AucRela^ bid in p->bids)
		result->Add(bid->getTargetAsBid()->toString());
	return result;
}

void AucShip::ship(UInt32^ index)
{
	AucBid^ bid = p->bids[*index]->getTargetAsBid();
	if(!*(bid->got))
		throw gcnew Exception("This bid havent won!");
	*(bid->shipped) = true;
}

void AucShip::shipAll()
{
	AucBid^ b;
	for each (AucRela^ bid in p->bids)
	{
		b = bid->getTargetAsBid();
		if(*(b->got))
			*(b->shipped) = true;
	}
}

void AucShip::close()
{
	p->setDeadline(DateTime::Now);
}