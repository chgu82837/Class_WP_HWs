#include "stdafx.h"

AucAdd::AucAdd(AucSeller^ s)
{
	this->s = s;
	this->p = gcnew AucProduct();
}
void AucAdd::prompt()
{
	p->name = ConsoleView::prompt_str("\nPlease input the name of the product:");
	p->quantity = ConsoleView::prompt_uint("Please input the quantity of the product:");
	p->init_bid = ConsoleView::prompt_uint("Please input the init_bid of the product:");
	p->winning_bid = ConsoleView::prompt_uint("Please input the winning_bid of the product:");
	p->shipping_cost = ConsoleView::prompt_uint("Please input the shipping_cost of the product:");
	p->setDeadline(ConsoleView::promt_date("Please input the deadline of the product"));
}

void AucAdd::check()
{
	if(*(p->winning_bid) <= *(p->init_bid))
		throw gcnew Exception("winning_bid is less than or same as init_bid!");

	if((*(p->getDeadline()) - DateTime::Now) < TimeSpan::Zero)
		throw gcnew Exception(String::Format("deadline [{0}] already passed!",p->getDeadline()->ToString()));

	p->bid = gcnew UInt32(*(p->init_bid));
}

AucProduct^ AucAdd::getProduct()
{
	return p;
}

void AucAdd::save(AucSys^ a)
{
	p->bid = gcnew UInt32(*(p->init_bid));
	p->remaining = gcnew UInt32(*(p->quantity));
	p->bids_times = gcnew UInt32(0);
	AucRela^ r = gcnew AucRela(s->key,gcnew UInt32(a->products->Count));
	p->owner = r;
	p->key = gcnew UInt32(a->products->Count);
	p->bids = gcnew List<AucRela^>();
	s->products->Add(r);
	a->products->Add(p);
}
