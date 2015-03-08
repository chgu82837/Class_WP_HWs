#include "stdafx.h"

AucOrder::AucOrder(AucBuyer^ buyer,AucProduct^ product)
{
	this->buyer = buyer;
	this->product = product;
	got = gcnew Boolean(false);
	price = Convert::ToUInt32(product->bid);
}

void AucOrder::prompt()
{
	UInt32^ pri;
	pri = ConsoleView::prompt_uint("How much do you want to bid? ");
	if(*(ConsoleView::prompt_char("Are you sure? [Y/n]")) != 'Y')
		throw gcnew Exception("You have changed your mind...");
	raise_bid(pri);
}

Boolean^ AucOrder::raise_bid(UInt32^ bid){
	if(*(product->ended()))
		throw gcnew Exception(String::Format("\nAuction for this product has already ended!"));
	if((*bid <= *(product->getBid())) && (*bid <= Convert::ToUInt32(product->winning_bid)))
		throw gcnew Exception(String::Format("\nYou raised a price [{0}] lower than original bid [{1}]!",bid,product->getBid()));

	if((Convert::ToUInt32(product->remaining)) <= 0)
		throw gcnew Exception("This product is sold out.");

	if(*bid >= Convert::ToUInt32(product->winning_bid))
		*(got) = true;
	
	*price = *bid;

	return got;
}

void AucOrder::save(AucSys^ a)
{
	AucBid^ b = gcnew AucBid();
	b->got = this->got;
	b->price = this->price;
	b->key = gcnew UInt32(a->bids->Count);
	b->shipped = gcnew Boolean(false);
	b->recieved =  gcnew Boolean(false);

	AucRela^ r = gcnew AucRela(product->key,b->key);
	product->bids->Add(r);
	b->product = r;

	r = gcnew AucRela(buyer->key,b->key);
	b->owner = r;
	buyer->bids->Add(r);

	a->bids->Add(b);
	product->bids_times = gcnew UInt32(Convert::ToUInt32(product->bids_times));

	if((*price > *(product->getBid())) && (*price < Convert::ToUInt32(product->winning_bid)))
		*(product->bid) = *price;

	if(*got)
		product->remaining = gcnew UInt32(Convert::ToUInt32(product->remaining));
}