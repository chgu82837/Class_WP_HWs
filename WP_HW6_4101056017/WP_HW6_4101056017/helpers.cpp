
#include "stdafx.h"

String std_str2_cstring(string* s)
{
	return new CString(s->c_str());
}

/*
string* cstring2std_str(String s)
{
	string* tmp = new string((char*)(LPCTSTR)s);
	return tmp;
}
*/

void clearList(CListCtrl* listView)
{
	listView->DeleteAllItems();

	// Delete all of the columns.
	//int nColumnCount = listView->GetHeaderCtrl()->GetItemCount();
	//for (int i=0; i < nColumnCount; i++)
	//	listView->DeleteColumn(0);
}