#include "stdafx.h"

AucProduct::AucProduct(void)
{
}

void AucProduct::setDeadline(DateTime^ deadline)
{
	this->deadline_ = deadline;
	this->deadline = DateTime2UInt(deadline);
}

DateTime^ AucProduct::getDeadline(){
	try{
	if(deadline_->GetType() != DateTime::typeid)
		deadline_ = UInt2DateTime(deadline);
	}catch(Exception^ e){
		deadline_ = UInt2DateTime(deadline);
	}
	return deadline_;
}

Boolean^ AucProduct::ended()
{
	return gcnew Boolean((*(this->getDeadline()) - DateTime::Now) < TimeSpan::Zero);
}


String^ AucProduct::headerStr(){
	return "name       quantity bid      winning_bid shipping_cost bids_times deadline";
}

void AucProduct::printHeader(){
	Console::WriteLine(AucProduct::headerStr());
}

String^ AucProduct::toString(){
	return String::Format("{0,-10} {1,-8} {2,-8} {3,-11} {4,-13} {5,-10} {6,-10}",this->name,this->quantity,this->bid,this->winning_bid,this->shipping_cost,bids_times,this->getDeadline()->ToString());
};

void AucProduct::print(){
	Console::WriteLine(this->toString());
}

UInt32^ AucProduct::getBid(){
	if(bid->GetType() != UInt32::typeid)
		bid = toUInt32(bid);
	return bid;
}
