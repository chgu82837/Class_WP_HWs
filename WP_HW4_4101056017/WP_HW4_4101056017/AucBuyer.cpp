#include "stdafx.h"

AucBuyer::AucBuyer(AucRole^ role)
{
	name = role->name;
	bids = role->bids;
	key = role->key;
}

void AucBuyer::Console()
{
	UInt32^ action_n = gcnew UInt32(0);
	List<String^>^ menu_preparing = gcnew List<String^>();
	String^ question = String::Format("Welcome to the auction market! {0}.\nWhich would you like to do?",name);
	String^ sort_question = String::Format("Which column do you prefer to sort?");
	UInt32^ sort_method = gcnew UInt32(0);
	Boolean^ reversed = gcnew Boolean(false);
	UInt32^ sort_i = gcnew UInt32(0);
	UInt32^ product_i = gcnew UInt32(0);
	UInt32^ cur_i = gcnew UInt32(0);
	List<AucProduct^>^ product_list;

	AucOrder^ ordering;
	AucGet^ getting;

	while(true)
	{
		menu_preparing->Clear();
		menu_preparing->Add("exit");

		if(bids->Count){
			menu_preparing->Add("=== Your bids List ===");
			menu_preparing->Add(AucBid::headerStr());
			*cur_i = 4;

			for each (AucRela^ b in this->bids){
				menu_preparing->Add(b->getTargetAsBid()->toString());
				(*cur_i)++;
			}
		}
		else{
			menu_preparing->Add("You havent bid any auction");
			*cur_i = 3;
		}

		product_list = sort(sort_method,reversed);

		if(product_list->Count){
			menu_preparing->Add("=== Products List ===");

			*sort_i = *cur_i;
			menu_preparing->Add("sort with different column");

			menu_preparing->Add("reverse sort");

			menu_preparing->Add(AucProduct::headerStr());
			(*cur_i)+=2;
			*product_i = *cur_i;

			for each (AucProduct^ p in product_list)
				menu_preparing->Add(p->toString());
		}
		else{
			menu_preparing->Add("There is no products >_<");
			*product_i = -1;
		}

		array<String^>^ menu = menu_preparing->ToArray();

		if(!*(action_n = ConsoleView::select(question,menu,action_n))) break;
		try
		{
			if(*action_n == *sort_i)
				sort_method = ConsoleView::select(sort_question,getSortMethods(),sort_method);
			else if(*action_n == (*sort_i) + 1)
				*reversed = !(*reversed);
			else if(*action_n > *product_i){
				ordering = gcnew AucOrder(this,a->products[(*action_n)-(*product_i) - 1]);
				ordering->prompt();
				ordering->save(a);
			}
			else if(*action_n >= 3 && *action_n < (3 + bids->Count)){
				if(*(ConsoleView::prompt_char("Receive this product? [Y/n]")) == 'Y'){
					getting = gcnew AucGet(this,bids[(*action_n) - 3]->getTargetAsBid());
					getting->receive();
					ConsoleView::pause(String::Format("You received {0}",bids[(*action_n) - 3]->getTargetAsBid()->product->getSrcAsProduct()->name));
				}
			}
		}catch(Exception^ e){
			ConsoleView::prompt_char(e->Message);
			continue;
		}
	}
}

List<AucProduct^>^ AucBuyer::sort(UInt32^ method)
{
	return sort(method,gcnew Boolean(false));
}

List<AucProduct^>^ AucBuyer::sort(UInt32^ method,Boolean^ reversed)
{
	array<UInt64^>^ sort_data = gcnew array<UInt64^>(a->products->Count);
	Int32^ i = gcnew Int32(0);

	array<UInt32^>^ seq = gcnew array<UInt32^>(a->products->Count);
	for(*i = 0;*i < a->products->Count;(*i)++){
		sort_data[*i] = gcnew UInt64(0);
		seq[*i] = gcnew UInt32(*i);
	}

	List<AucProduct^>^ result = gcnew List<AucProduct^>();

	switch (*method)
	{
	case 0:
		break;
	case 1:
		i = gcnew Int32(0);
		for each(AucProduct^ p in a->products)
			sort_data[(*i)++] = Convert::ToUInt64(p->bid);
		break;
	case 2:
		i = gcnew Int32(0);
		for each(AucProduct^ p in a->products)
			sort_data[(*i)++] = Convert::ToUInt64(p->winning_bid);
		break;
	case 3:
		i = gcnew Int32(0);
		for each(AucProduct^ p in a->products)
			sort_data[(*i)++] = Convert::ToUInt64(p->deadline);
		break;
	case 4:
		i = gcnew Int32(0);
		for each(AucProduct^ p in a->products)
			sort_data[(*i)++] = Convert::ToUInt64(p->quantity);
		break;
	case 5:
		i = gcnew Int32(0);
		for each(AucProduct^ p in a->products)
			sort_data[(*i)++] = Convert::ToUInt64(p->shipping_cost);
		break;
	default:
		throw gcnew Exception("Unknown Method!");
	}

	if(*method > 0)
		Array::Sort(sort_data,seq);

	if(*reversed)
		for (i = gcnew Int32(a->products->Count - 1); *i >= 0; (*i)--)
			result->Add(a->products[*seq[*i]]);
	else
		for (i = gcnew Int32(0); *i < a->products->Count; (*i)++)
			result->Add(a->products[*seq[*i]]);
	return result;
}

array<String^>^ AucBuyer::getSortMethods()
{
	array<String^>^ methods = {"None","Current bid","Winning bid","Deadline","Quantity","Shipping cost"};
	return methods;
}