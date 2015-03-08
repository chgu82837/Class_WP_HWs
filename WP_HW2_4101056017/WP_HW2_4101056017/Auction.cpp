#include "stdafx.h"
#include "Auction.h"
#include "helper.h"

Auction::Auction(){
	deadline_ = nullptr;
}

Auction::Auction(JsonTextReader^ r){

}

Auction^ Auction::promt_new(){
	Auction^ a = gcnew Auction();

	a->name = prompt_str("\nPlease input the name of the product:");
	a->number = prompt_uint("Please input the number of the product:");
	a->init_bid = prompt_uint("Please input the init_bid of the product:");
	a->winning_bid = prompt_uint("Please input the winning_bid of the product:");
	a->shipping_cost = prompt_uint("Please input the shipping_cost of the product:");
	a->deadline_ = promt_date("Please input the deadline of the product");

	if(*(a->winning_bid) <= *(a->init_bid))
		throw gcnew Exception("winning_bid is less than or same as init_bid!");

	if((*(a->deadline_) - DateTime::Now) < TimeSpan::Zero)
		throw gcnew Exception(String::Format("deadline [{0}] already passed!",a->deadline_->ToString()));

	a->bid = gcnew UInt32(*(a->init_bid));
	a->deadline = DateTime2UInt(a->deadline_);

	return a;
}

Boolean^ Auction::raise_bid(UInt32^ bid){
	if((*(this->getDeadline()) - DateTime::Now) < TimeSpan::Zero)
		throw gcnew Exception(String::Format("\nDeadline [{0}] already passed!",deadline_->ToString()));
	if(*bid <= Convert::ToUInt32(this->getBid()))
		throw gcnew Exception(String::Format("\nYou raised a price [{0}] lower than init bid [{0}]!",bid,this->bid));
	if(*bid >= Convert::ToUInt32(this->winning_bid))
		return true;
	this->bid = bid;
	return false;
}

String^ Auction::headerStr(){
	return "name       number bid      winning_bid shipping_cost deadline";
}

void Auction::printHeader(){
	Console::WriteLine(Auction::headerStr());
}

String^ Auction::toString(){
	return String::Format("{0,-10} {1,-6} {2,-8} {3,-11} {4,-13} {5,-10}",this->name,this->number,this->getBid(),this->winning_bid,this->shipping_cost,this->getDeadline()->ToString());
};

void Auction::print(){
	Console::WriteLine(this->toString());
}

DateTime^ Auction::getDeadline(){
	try{
		if(deadline_ == nullptr)
			throw gcnew Exception();
	}catch(Exception^ e){
		deadline_ = UInt2DateTime(deadline);
	}
	return deadline_;
}

UInt32^ Auction::getBid(){
	try{
		if(this->bid == nullptr)
			throw gcnew Exception();
	}catch(Exception^ e){
		this->bid = Convert::ToUInt32(this->init_bid);
	}
	return this->bid;
}