#include "stdafx.h"

AucGet::AucGet(AucBuyer^ buyer,AucBid^ bid)
{
	this->buyer = buyer;
	this->bid = bid;
}

void AucGet::receive()
{
	if(*(bid->recieved))
		throw gcnew Exception("You have already received this product!");
	if(!*(bid->got))
		throw gcnew Exception("Your order havent won this auction!");
	if(!*(bid->shipped))
		throw gcnew Exception("Your order havent been shipped!");
	*(bid->recieved) = true;
}