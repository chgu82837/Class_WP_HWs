/***************************
4101056017 邱冠喻 第二次作業 10/22
4101056017 Chiu Guan-Yu TheSecondHomework 10/22
***************************/

#include "stdafx.h"
#include "Auction.h"
#include "helper.h"

using namespace System::Collections::Generic;

ref struct AucDB{
	List<Auction^>^ auctions;
};

AucDB^ read_auction();
AucDB^ init_auction();
void write_auction(AucDB^);
void add_auction(AucDB^);

void show_auction(AucDB^);
void show_auction(AucDB^,array<UInt32^>^,Boolean^);
void auction_console(AucDB^);

void test();

int main(array<System::String ^> ^args)
{
	Console::WriteLine("<<< Welcome to my auction system! >>>");
	Char^ action_n = gcnew Char(0);

	while(*action_n != '0')
	{
		Console::Write("\nPlease choose an action:\n\t1.read actions from file\n\t2.create auctions to file\n\t3.add auctions to existing file\n\n\t0.exit\nYour choise:");
		*action_n = Console::ReadKey().KeyChar;
		AucDB^ a;

		switch (*action_n)
		{
		case '1':
			Console::Write("\nPreparing to read auction...");
			a = read_auction();
			auction_console(a);
			break;
		case '2':
			Console::Write("\nPreparing to create auction...");
			a = init_auction();
			add_auction(a);
			auction_console(a);
			break;
		case '3':
			Console::Write("\nPreparing to add auction...");
			a = read_auction();
			show_auction(a);
			add_auction(a);
			auction_console(a);
			break;
		case '0':
			Console::Write("\nExiting...\n");
			break;
		default:
			Console::Write("\nUnknown option\n");
			break;
		}
	}

	Console::Write("Program ended. Press enter to continue...");
	Console::ReadKey();
	return 0;
}

AucDB^ read_auction(){
	IO::FileStream^ f = prompt_file("\nPlease input a filename to open:",IO::FileMode::Open,true);
	String^ d = (gcnew IO::StreamReader(f))->ReadToEnd();
	f->Close();
	return JsonConvert::DeserializeAnonymousType<AucDB^>(d,gcnew AucDB);
}

AucDB^ init_auction(){
	AucDB^ a = gcnew AucDB();
	a->auctions = gcnew List<Auction^>();
	return a;
}

void write_auction(AucDB^ a){
	String^ d;
	IO::StreamWriter^ s;
	IO::FileStream^ f;

	try{
		f = prompt_file("\nPlease input a filename to save (Or press enter to skip):",IO::FileMode::Truncate);
	}catch(Exception^ e){
		Console::WriteLine(e->Message);
		return;
	}
	
	try{
		d = JsonConvert::SerializeObject(a,Formatting::Indented);
		s = gcnew IO::StreamWriter(f);
		s->Write(d);
		s->Close();
		f->Close();
	}catch(Exception^ e){
		Console::WriteLine("There is an error writing the file!");
	}
}

void add_auction(AucDB^ a){
	Auction^ a_tmp;

	while(true){
		Console::WriteLine("\nStart to create a auction item:");
		try{
		a_tmp = Auction::promt_new();
		}catch(Exception^ e){
			Console::WriteLine(e->Message);
			continue;
		}
		Console::Write("==You_entered===============\n");
		a_tmp->printHeader();
		a_tmp->print();
		Console::Write("============================\nIs this correct? [Yn]:");
		if(Console::ReadKey().KeyChar != 'Y')
			continue;
		a->auctions->Add(a_tmp);

		Console::Write("\nAuction saved.\nDo you want to enter more auction? [Yn]:");
		if(Console::ReadKey().KeyChar != 'Y')
			break;
	}

	write_auction(a);
}

void show_auction(AucDB^ a)
{
	Console::WriteLine(Auction::headerStr());
	for each(Auction^ auction in a->auctions){
		auction->print();
	} 
}

void show_auction(AucDB^ a,array<UInt32^>^ seq,Boolean^ reaversed)
{
	Console::WriteLine(Auction::headerStr());
	Int32^ i;
	if(*reaversed)
		for (i = gcnew Int32(a->auctions->Count - 1); *i >= 0; (*i)--)
			a->auctions[*seq[*i]]->print();
	else
		for (i = gcnew Int32(0); *i < a->auctions->Count; (*i)++)
			a->auctions[*seq[*i]]->print();
}

void auction_console(AucDB^ a){

	Char^ action_n = gcnew Char(0);
	Char^ sort_a = gcnew Char(0);
	UInt32^ i;
	UInt32^ na = gcnew UInt32(a->auctions->Count);
	UInt32^ target = gcnew UInt32(0);
	Boolean^ reversed = gcnew Boolean(false);
	String^ message = "";
	String^ prompt;
	
	array<UInt64^>^ sort_data;
	array<UInt32^>^ seq;

	while(*action_n != '0')
	{
		Console::Clear();

		sort_data = gcnew array<UInt64^>(*na);
		seq = gcnew array<UInt32^>(*na);

		for(i = gcnew UInt32(0);*i < *na;(*i)++){
			sort_data[*i] = gcnew UInt64(0);
			seq[*i] = gcnew UInt32(*i);
		}

		switch (*sort_a)
		{
		case '1':
			i = gcnew UInt32(0);
			for each(Auction^ auction in a->auctions)
				sort_data[(*i)++] = Convert::ToUInt64(auction->bid);
			break;
		case '2':
			i = gcnew UInt32(0);
			for each(Auction^ auction in a->auctions)
				sort_data[(*i)++] = Convert::ToUInt64(auction->winning_bid);
			break;
		case '3':
			i = gcnew UInt32(0);
			for each(Auction^ auction in a->auctions)
				sort_data[(*i)++] = Convert::ToUInt64(auction->deadline);
			break;
		case '4':
			i = gcnew UInt32(0);
			for each(Auction^ auction in a->auctions)
				sort_data[(*i)++] = Convert::ToUInt64(auction->number);
			break;
		case '5':
			i = gcnew UInt32(0);
			for each(Auction^ auction in a->auctions)
				sort_data[(*i)++] = Convert::ToUInt64(auction->shipping_cost);
			break;
		default:
			Console::Write("All Auctions:\n===========================\n");
			show_auction(a);
			goto skip_sort;
		}

		Array::Sort(sort_data,seq);
		Console::Write("All Auctions:\n===========================\n");
		show_auction(a,seq,reversed);
		message = "[u] Key to sort upward\n[d] key to sort downward" + message;
		skip_sort:
		
		prompt = String::Format("\n===========================\nPress\n[r] to raise bid for [{0}]\n[n] key to choose next\n[p] key to choose previous\nSpace key choosing a column to sort\n[0] key to exit\n{1}\n",a->auctions[*target]->name,message);
		action_n = prompt_char(prompt);
		message = "";

		switch (*action_n)
		{
		case 'r':
			Console::WriteLine("");
			Auction::printHeader();
			a->auctions[*target]->print();
			try{
				if(*(a->auctions[*target]->raise_bid(prompt_uint("\nHow much:")))){
					message = String::Format("\nYou won [{0}]!",a->auctions[*target]->name);
					a->auctions->RemoveAt(*target);
					a->auctions = gcnew List<Auction^>(a->auctions);
					(*na)--;
				}
				else
					message = String::Format("\n[{0}] has been bidden to [{1}]",a->auctions[*target]->name,a->auctions[*target]->bid);
			}catch(Exception^ e){
				message = e->Message;
			}
			
			break;
		case 'n':
			if(*target >= (*na - 1)){ message ="\nNo next auction!"; continue; }
			(*target)++;
			break;
		case 'p':
			if(*target <= 0){ message = "\nNo previous auction!"; continue; }
			(*target)--;
			break;
		case ' ':
			Console::Clear();
			sort_a = prompt_char("===========================\nPlease choose a field to sort:\n\t1.bid price\n\t2.Winning bid price\n\t3.Deadline\n\t4.Number\n\t5.Shipping cost\n\nYour choise:");
			break;
		case 'u':
			reversed = gcnew Boolean(true);
			break;
		case 'd':
			reversed = gcnew Boolean(false);
			break;
		case '0':
			Console::Write("\nLeaving...\n");
			break;
		default:
			Console::Write("\nUnknown option\n");
			continue;
		}
	}
	write_auction(a);
}

void test()
{
	//Aucs^ a;
	Auction^ b = gcnew Auction();
	String^ d = L"{\"name\":\"win10\",\"number\":100,\"init_bid\":5,\"winning_bid\":100,\"shipping_cost\":1,\"deadline\":1420041567}";

	b = JsonConvert::DeserializeAnonymousType<Auction^>(d,b);
	//a = (Auction^)o;
	Console::WriteLine(b->headerStr());
	Console::WriteLine(b->toString());
    Console::WriteLine(L"Hello World");
}

/***************************
4101056017 邱冠喻 第二次作業 10/22
4101056017 Chiu Guan-Yu TheSecondHomework 10/22
***************************/