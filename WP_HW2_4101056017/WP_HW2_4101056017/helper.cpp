#include "stdafx.h"
#include "helper.h"

DateTime^ UInt2DateTime(UInt64^ tstmp) {
	Double^ tmp = Convert::ToDouble(tstmp);
    return DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind::Utc).AddSeconds(*tmp).Add(DateTime::Now - DateTime::UtcNow);
}
UInt64^ DateTime2UInt(DateTime^ date) {
    TimeSpan^ diff =  %(date->ToUniversalTime() - DateTime(1970, 1, 1));
    return Convert::ToUInt64(diff->TotalSeconds);
}

IO::FileStream^ prompt_file(String^ message,IO::FileMode^ mode){
	return prompt_file(message,mode,false);
}

IO::FileStream^ prompt_file(String^ message,IO::FileMode^ mode,Boolean^ force){
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

String^ prompt_str(String^ message){
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

UInt32^ prompt_uint(String^ message){
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

Char^ prompt_char(String^ message){
	Console::Write(message);
	
	while(true){
		try{
			return Console::ReadKey().KeyChar;
		}catch(Exception^ e){
			Console::Write("Not a valid input!\n{0}",message);
			continue;
		}
	}
}

DateTime^ promt_date(String^ message){
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