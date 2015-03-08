#pragma once

ref class AucBuyer :
public AucRole
{
public:
	AucBuyer(AucRole^ role);

	void Console();
	List<AucProduct^>^ sort(UInt32^ method);
	List<AucProduct^>^ sort(UInt32^ method,Boolean^ reversed);
	array<String^>^ getSortMethods();
};
