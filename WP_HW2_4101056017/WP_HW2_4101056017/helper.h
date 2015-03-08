
DateTime^ UInt2DateTime(UInt64^);
UInt64^ DateTime2UInt(DateTime^);
IO::FileStream^ prompt_file(String^,IO::FileMode^);
IO::FileStream^ prompt_file(String^,IO::FileMode^,Boolean^);
String^ prompt_str(String^ message);
UInt32^ prompt_uint(String^);
Char^ prompt_char(String^);
DateTime^ promt_date(String^);