#include "stdafx.h"

ConsoleView::ConsoleView(void)
{
}

IO::FileStream^ ConsoleView::prompt_file(String^ message,IO::FileMode^ mode){
	return prompt_file(message,mode,false);
}

IO::FileStream^ ConsoleView::prompt_file(String^ message,IO::FileMode^ mode,Boolean^ force){
	String^ fname;
	IO::FileStream^ f;
	while(true)
	{
		Console::Write(message);
		fname = Console::ReadLine();
		if(! *(force))
			if(fname->Length == 0)
				throw gcnew Exception("You didnt enter a file name.");
		Console::Write("Opening [{0}] in mode [{1}]...\n",fname,mode);
		try{
			f = IO::File::Open(fname,*mode);
			break;
		}catch(Exception^ e){
			Console::Write("Can not open file [{0}] in mode [{1}]!\n",fname,mode);
			continue;
		}
	}
	return f;
}

String^ ConsoleView::prompt_str(String^ message){
	Console::Write(message);
	String^ str;
	
	while(true){
		try{
			str = Console::ReadLine();
			if(str->Length == 0)
				throw gcnew Exception();
			return str;
		}catch(Exception^ e){
			Console::Write("Not a valid input!\n{0}",message);
			continue;
		}
	}
}

UInt32^ ConsoleView::prompt_uint(String^ message){
	Console::Write(message);
	
	while(true){
		try{
			return UInt32::Parse(Console::ReadLine());
		}catch(Exception^ e){
			Console::Write("Not a valid input!\n{0}",message);
			continue;
		}
	}
}

Char^ ConsoleView::prompt_char(String^ message){
	Console::Write("{0} ",message);
	Char^ c;

	while(true){
		try{
			c = Console::ReadKey().KeyChar;
			Console::WriteLine();
			return c;
		}catch(Exception^ e){
			Console::Write("Not a valid input!\n{0}",message);
			continue;
		}
	}
}

DateTime^ ConsoleView::promt_date(String^ message){
	Console::Write("{0} (YYYY-MM-DD HH:mm:ss):",message);

	while(true){
		try{
			return DateTime::Parse(Console::ReadLine());
		}catch(Exception^ e){
			Console::Write("Not a valid input!\n{0} (YYYY-MM-DD HH:mm:ss):",message);
			continue;
		}
	}
}

UInt32^ ConsoleView::select(String^ question,array<String^>^ options)
{
	return select(question,options,gcnew UInt32(0));
}


UInt32^ ConsoleView::select(String^ question,array<String^>^ options,UInt32^ lastCursor){
	UInt32^ cursor = gcnew UInt32(0);
	try{
		*cursor = *lastCursor;
	}catch(Exception^ e){
		*cursor = 0;
	}
	UInt32^ scroll_top = gcnew UInt32(0);
	UInt32^ print_i = gcnew UInt32(0);
	ConsoleColor^ ori_color = gcnew ConsoleColor(Console::BackgroundColor);
	UInt32^ print_max = gcnew UInt32(options->Length);
	String^ divider = "";
	String^ line_format = "{1}";

	for(*print_i = 0 ; *print_i < (Console::WindowWidth - 1) ; (*print_i)++)
		divider+="=";

	if(*cursor < 0)
		*cursor = 0;
	if(*cursor > options->Length - 1)
		*cursor = options->Length - 1;

	while(true)
	{
		Console::Clear();
		Console::WriteLine(question);
		Console::WriteLine(divider);
		*print_i = *scroll_top;

		while(Console::CursorTop != (Console::WindowHeight - 2) && *print_i < *print_max)
		{
			int a = Console::CursorTop;
			int b = Console::WindowHeight;
			if(*print_i == *cursor)
			{
				Console::BackgroundColor = ConsoleColor::Red;
				Console::WriteLine(line_format,print_i,options[*print_i]);
				Console::BackgroundColor = *ori_color;
			}
			else
				Console::WriteLine(line_format,print_i,options[*print_i]);
			(*print_i)++;
		}

		try{
			switch(Console::ReadKey().Key)
			{
			case ConsoleKey::UpArrow:
				if(*cursor <= 0)
					throw gcnew Exception();
				(*cursor)--;
				break;
			case ConsoleKey::DownArrow:
				if(*cursor >= options->Length - 1)
					throw gcnew Exception();
				(*cursor)++;
				break;
			case ConsoleKey::Enter:
				return cursor;
			default:
				throw gcnew Exception();
			}

			if(*cursor >= *print_i)
				(*scroll_top)++;
			else if(*cursor < *scroll_top)
				(*scroll_top)--;
		}catch(Exception^ e){
			Console::Beep();
			continue;
		}
	}
}

void ConsoleView::pause(String^ message)
{
	Console::WriteLine("{0}\nPress any key to continue...",message);
	Console::ReadKey();
}