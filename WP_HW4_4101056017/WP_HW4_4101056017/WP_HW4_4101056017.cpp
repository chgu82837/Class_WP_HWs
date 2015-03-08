/***************************
4101056017 邱冠喻 第四次作業 11/19
4101056017 Chiu Guan-Yu TheFourthHomework 11/19
***************************/

#include "stdafx.h"

int main(array<System::String ^> ^args)
{
	Console::WriteLine("<<< Welcome to my auction system! >>>");
	AucSys^ a;
	AucRole^ u;
	
	try{
		if(args->Length > 1){
			a = gcnew AucSys(args[1]);
			if(args->Length > 2)
				u = a->getUser(args[2]);
			else
				u = a->getUser(ConsoleView::prompt_str("\nPlease input a user to login:"));
		}
		throw gcnew Exception();
	}catch(Exception^ e){
		a = gcnew AucSys(ConsoleView::prompt_file("\nPlease input a json file name as database:",IO::FileMode::OpenOrCreate,true));
		u = a->getUser(ConsoleView::prompt_str("\nPlease input a user to login:"),gcnew Boolean(true));
	}

	AucRole::setAucSys(a);
	AucRela::setAucSys(a);

	UInt32^ action_n = gcnew UInt32(0);
	array<String^>^ main_menu = {"exit","shopping","selling"};
	String^ main_question = String::Format("Hello {0}\mWhich would you like to do?",u->name);

	while(*(action_n = ConsoleView::select(main_question,main_menu)))
	{
		switch(*action_n)
		{
		case 1:
			(gcnew AucBuyer(u))->Console();
			break;
		case 2:
			(gcnew AucSeller(u))->Console();
			break;
		}
	}
	Console::WriteLine("Saving...");
	a->save();
	ConsoleView::pause("Bye. Please come again.");
	return 0;
}

/***************************
4101056017 邱冠喻 第四次作業 11/19
4101056017 Chiu Guan-Yu TheFourthHomework 11/19
***************************/