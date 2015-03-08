#include "stdafx.h"

AucBid::AucBid(void)
{
}

AucBid::AucBid(Json::Value* Json)
{
	#define json (*Json)
	if(!json.isObject())
		throw new CString("Json for AucBid not valid!");
	
	#define addint(X) if(!json[#X].isInt()) throw new CString("Json for AucBid not valid!"); this->X = json[#X].asInt();
	#define addbool(X) if(!json[#X].isBool()) throw new CString("Json for AucBid not valid!"); this->X = json[#X].asBool();
	this->product = new AucRela(&json["product"]);
	addint(price)
	addbool(got)
	addbool(shipped)
	addbool(recieved)
	this->owner = new AucRela(&json["owner"]);
	addint(key)

	/*
		{
			"product": {
				"src": 0,
				"target": 0
			},
			"price": 300,
			"got": true,
			"shipped": true,
			"recieved": true,
			"owner": {
				"src": 0,
				"target": 0
			},
			"key": 0
		},
	*/
}

AucBid::~AucBid(void)
{
}

void AucBid::set_list_head(CListCtrl* listView)
{
	clearList(listView);

#define addcol(X,Y) listView->InsertColumn(0,_T(#X),0,Y);

	addcol(recieved,60)
	addcol(shipped,50)
	addcol(got,40)
	addcol(total,40)
	addcol(price,40)
	addcol(name,150)
}

void AucBid::switch_name_col(CListCtrl* listView,bool display_cus)
{
	LV_COLUMN c;
	c.mask = LVCF_TEXT;
	c.pszText = display_cus ? _T("Customer") : _T("Product") ;
	listView->SetColumn( 0, &c ); 
}

void AucBid::to_list(CListCtrl* listView,bool display_cus)
{
	int row = listView->GetItemCount();
	String name = display_cus ? owner->getSrcAsRole()->name : product->getSrcAsProduct()->name ;
	listView->InsertItem(row,*name);

	AucProduct* p = product->getSrcAsProduct();
	int col = 1;
#define addintcol(X) listView->SetItemText(row,col++,CString(itoa(X,new char[10],10)));
#define addboolcol(X) listView->SetItemText(row,col++, X ? CString("YES") : CString("NO"));
	addintcol(price)
	addintcol(price + p->shipping_cost)
	addboolcol(got)
	addboolcol(shipped)
	addboolcol(recieved)
}

void AucBid::to_list(CListCtrl* listView)
{
	to_list(listView,false);
}

void AucBid::save(ASys sys,ARole user,AProduct product)
{
	key = sys->bids->size();

	ARela r = new AucRela(product->key,key);
	product->bids->push_back(r);
	this->product = r;

	r = new AucRela(user->key,key);
	user->bids->push_back(r);
	owner = r;

	sys->bids->push_back(this);
	product->bids_times++;

	if((price > product->bid)){
		if(price < product->winning_bid)
			product->bid = price;
		else
			product->bid = product->winning_bid;
	}
	if(got)
		product->remaining--;
}

void AucBid::ship(bool trying)
{
	if(!got)
		throw new CString(_T("This bid havent won!"));

	if(trying)
		return;
	shipped = true;
}

void AucBid::receive(bool trying)
{
	if(recieved)
		throw new CString(_T("You have already received this product!"));
	if(!got)
		throw new CString(_T("Your order havent won this auction!"));
	if(!shipped)
		throw new CString(_T("Your order havent been shipped!"));

	if(trying)
		return;
	recieved = true;
}

Json::Value* AucBid::toJson()
{
	Json::Value* r = new Json::Value();
	Json::Value* vec;
	#define R (*r)

	R["product"] = *(this->product->toJson());
	R["price"] = this->price;
	R["got"] = this->got;
	R["shipped"] = this->shipped;
	R["recieved"] = this->recieved;
	R["owner"] = *(this->owner->toJson());
	R["key"] = this->key;

	return r;
}