#include "stdafx.h"

AucSeller::AucSeller(AucRole^ role)
{
	name = role->name;
	products = role->products;
	key = role->key;
}

void AucSeller::Console()
{
	UInt32^ action_n = gcnew UInt32(0);
	List<String^>^ menu_preparing = gcnew List<String^>();
	List<String^>^ sub_list;
	String^ question = String::Format("Welcome to the selling console! {0}.\nWhich would you like to do?",name);
	String^ sub_question;
	Boolean^ ended;
	AucProduct^ product;
	AucAdd^ adding;
	AucShip^ shiping;

	while(true)
	{
		menu_preparing->Clear();
		menu_preparing->Add("exit");
		menu_preparing->Add("add a products");


		if(products->Count){
			menu_preparing->Add(AucProduct::headerStr());
			for each (AucRela^ p in products)
				menu_preparing->Add(p->getTargetAsProduct()->toString());
		}
		else{
			menu_preparing->Add("There's no products in your markdet!");
		}

		array<String^>^ menu = menu_preparing->ToArray();

		if(!*(action_n = ConsoleView::select(question,menu,action_n))) break;
		try
		{
			if(*action_n == 1){
				adding = gcnew AucAdd(this);
				adding->prompt();
				Console::WriteLine("Checking...");
				adding->check();
				product = adding->getProduct();
				product->printHeader();
				product->print();
				if(*(ConsoleView::prompt_char("Is this correct? [Y/n]")) != 'Y') throw gcnew Exception();
				adding->save(a);
				ConsoleView::pause("Saved.");
			}
			else if(*action_n > 2){
				product = products[(*action_n) - 3]->getTargetAsProduct();
				shiping = gcnew AucShip(this,product);
				*action_n = 0;
				while(true)
				{
					try{
						menu_preparing->Clear();
						sub_question = String::Format("=== Product ===\n{0}\n{1}\nHere are the bids for this product\nWhat do you like to do?",product->headerStr(),product->toString());
						ended = product->ended();
						sub_list = shiping->list();
						menu_preparing->Add("Exit");

						if(sub_list->Count){
							menu_preparing->Add("Ship all bids that got this product");
							if(!*ended)
								menu_preparing->Add("Close auction for this product");
							menu_preparing->Add(AucBid::headerStr());
							menu_preparing->AddRange(shiping->list());
						}
						else{
							menu_preparing->Add("There's no bids for this product >_<");
						}

						array<String^>^ menu = menu_preparing->ToArray();

						if(!*(action_n = ConsoleView::select(sub_question,menu,action_n))) break;

						if((*action_n == 1) && (sub_list->Count)){
							if(*(ConsoleView::prompt_char("Ship to all buyers winning this product? [Y/n]")) == 'Y'){
								shiping->shipAll();
								ConsoleView::pause("Done");
							}
						}
						else if(!*ended && *action_n == 2){
							if(*(ConsoleView::prompt_char("Are you sure? [Y/n]")) == 'Y'){
								shiping->close();
								ConsoleView::pause("Done");
							}
						}
						else if((*action_n > 3)||(*ended && (*action_n == 3))){
							if(*(ConsoleView::prompt_char("Ship the product to this buyer? [Y/n]")) == 'Y'){
								shiping->ship(*action_n - 4);
								ConsoleView::pause("Done");
							}
						}
					}catch(Exception^ e){
						ConsoleView::prompt_char(e->Message);
						continue;
					}
				}
			}
		}catch(Exception^ e){
			ConsoleView::prompt_char(e->Message);
			continue;
		}
	}

}