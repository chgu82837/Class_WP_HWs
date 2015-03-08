#include "stdafx.h"

AucBid::AucBid(void)
{
}

String^ AucBid::headerStr(){
	return "name       price    total    got   shipped recieved";
}

void AucBid::printHeader(){
	Console::WriteLine(AucBid::headerStr());
}

String^ AucBid::toString(){
	AucProduct^ p = product->getSrcAsProduct();
	p->shipping_cost = toUInt32(p->shipping_cost);
	price = toUInt32(price);
	return String::Format("{0,-10} {1,-8} {2,-8} {3,-5} {4,-7} {5}",p->name,price,*(price) + *(p->shipping_cost),got,shipped,recieved);
};

void AucBid::print(){
	Console::WriteLine(this->toString());
}
