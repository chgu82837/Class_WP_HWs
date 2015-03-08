#include "stdafx.h"

AucProduct::AucProduct(void)
{
	done_end_chk = false;
}

AucProduct::AucProduct(Json::Value* Json)
{
	#define json (*Json)
	if(!json.isObject())
		throw new CString("Json for AucProduct not valid!");
	
	if(!json["name"].isString())
		throw new CString("Json for AucProduct not valid!");
	this->name = new CString(json["name"].asCString());

#define addint(X) if(!json[#X].isInt()) throw new CString("Json for AucProduct not valid!"); X = json[#X].asInt();
	addint(quantity)
	addint(bids_times)
	addint(init_bid)
	addint(bid)
	addint(winning_bid)
	addint(shipping_cost)
	addint(deadline)
	addint(key)

	if(!json["remaining"].isInt()){
		if(json["remaining"].isNull())
			remaining = quantity;
		else
			throw new CString("Json for AucProduct not valid!");
	}
	else
		this->remaining = json["remaining"].asInt();

	this->owner = new AucRela(&json["owner"]);

	Json::Value tmp = json["bids"];
	if(!tmp.isArray())
		throw new CString("Json for AucProduct not valid!");
	bids = new vector<ARela>();
	for (int i = 0; i < tmp.size(); i++)
		bids->push_back(new AucRela(&tmp[i]));

	/*
	    {
		  "name": "qq",
		  "quantity": 123,
		  "remaining": null,
		  "bids_times": 0,
		  "init_bid": 123,
		  "bid": 300,
		  "winning_bid": 200,
		  "shipping_cost": 123,
		  "deadline": 1416459317,
		  "owner": {
			"src": 0,
			"target": 0
		  },
		  "bids": [
			{
			  "src": 0,
			  "target": 0
			}
		  ],
		  "key": 0
		},
	*/

	done_end_chk = false;
}

AucProduct::~AucProduct(void)
{
}

void AucProduct::set_list_head(CListCtrl* listView)
{
	clearList(listView);

#define addcol(X,Y) listView->InsertColumn(0,_T(#X),0,Y);

	addcol(deadline,150)
	addcol(bids_times,70)
	addcol(shipping_cost,80)
	addcol(winning_bid,70)
	addcol(bid,50)
	addcol(quantity,60)
	addcol(name,150)
}

void AucProduct::to_list(CListCtrl* listView)
{
	chkBids();

	int row = listView->GetItemCount();
	listView->InsertItem(row,*(this->name));

	int col = 1;
#define addintcol(X) listView->SetItemText(row,col++,CString(itoa(X,new char[10],10)));
	addintcol(quantity)
	addintcol(bid)
	addintcol(winning_bid)
	addintcol(shipping_cost)
	addintcol(bids_times)

	time_t rawtime = this->deadline;
	struct tm * timeinfo;
	char buffer [80];
	//time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer,80,"%Y-%m-%d %H:%M:%S",timeinfo);
	listView->SetItemText(row,col++,CString(buffer));
}

bool AucProduct::ended_chk()
{
	if(ended())
		throw new CString("deadline already passed!");
	return true;
}

bool AucProduct::ended()
{
	time_t t;
	time(&t);
	return deadline < t;
}

void AucProduct::check()
{
	if(winning_bid <= init_bid)
		throw new CString("winning_bid is less than or same as init_bid!");

	ended_chk();
}

void AucProduct::close()
{
	time(&deadline);
	done_end_chk = false;
}

void AucProduct::chkBids()
{
	if(!ended() || done_end_chk)
		return;

	AucBids pri = new vector<ABid>();
	ABid tmp;
	int j;
#define B(X) pV(bids,X)->getTargetAsBid()

	if(!bids->size())
		return;
	
	for (int i = 0; i < bids->size(); i++)
	{
		tmp = B(i);
		if(!tmp->got){
			for (j = 0; j < pri->size(); j++)
			{
				if(tmp->price > pV(pri,j)->price){
					pri->insert(pri->begin() + j,tmp);
					break;
				}
			}
			pri->insert(pri->begin() + j,tmp);
		}

	}

	for (int i = 0; i < pri->size(); i++)
	{
		if(remaining == 0)
			break;
		pV(pri,i)->got = true;
		remaining--;
	}

	done_end_chk = true;
}

void AucProduct::save(ASys sys,ARole user)
{
	bid = init_bid;
	remaining = quantity;
	bids_times = 0;

	key = sys->products->size();
	ARela r = new AucRela(user->key,key);
	owner = r;
	bids = new vector<ARela>();
	user->products->push_back(r);
	sys->products->push_back(this);
}

ABid AucProduct::raise(int bid)
{
	ended_chk();
	if((bid <= this->bid) && (bid <= this->winning_bid))
		throw new CString("You raised a price lower than original bid!");

	if(this->remaining <= 0)
		throw new CString("This product has sold out.");

	bool got = bid > winning_bid;
	int price = bid;

	ABid b = new AucBid();
	b->got = got;
	b->price = price;
	b->shipped = false;
	b->recieved =  false;

	return b;
}

Json::Value* AucProduct::toJson()
{
	Json::Value* r = new Json::Value();
#define R (*r)
	CT2A tmp(*(this->name));
	R["name"] = tmp.m_psz;
	R["quantity"] = this->quantity;
	R["remaining"] = this->remaining;
	R["bids_times"] = this->bids_times;
	R["init_bid"] = this->init_bid;
	R["bid"] = this->bid;
	R["winning_bid"] = this->winning_bid;
	R["shipping_cost"] = this->shipping_cost;
	R["deadline"] = this->deadline;
	
	R["owner"] = *(this->owner->toJson());

	Json::Value* vec = new Json::Value(Json::arrayValue);
	for (int i = 0; i < bids->size(); i++)
		vec->append(*(pV(bids,i)->toJson()));

	R["bids"] = *vec;
	R["key"] = this->key;

	return r;
}