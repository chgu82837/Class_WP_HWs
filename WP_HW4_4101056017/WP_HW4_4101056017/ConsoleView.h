#pragma once

ref class ConsoleView
{
public:
	ConsoleView(void);

	static IO::FileStream^ prompt_file(String^,IO::FileMode^);
	static IO::FileStream^ prompt_file(String^,IO::FileMode^,Boolean^);
	static String^ prompt_str(String^ message);
	static UInt32^ prompt_uint(String^);
	static Char^ prompt_char(String^);
	static DateTime^ promt_date(String^);
	static UInt32^ select(String^ question,array<String^>^ options);
	static UInt32^ select(String^ question,array<String^>^ options,UInt32^ lastCursor);
	static void pause(String^ message);
};
