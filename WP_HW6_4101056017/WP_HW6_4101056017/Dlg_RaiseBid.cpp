// Dlg_RaiseBid.cpp : 實作檔
//

#include "stdafx.h"

// Dlg_RaiseBid 對話方塊

IMPLEMENT_DYNAMIC(Dlg_RaiseBid, CDialogEx)

Dlg_RaiseBid::Dlg_RaiseBid(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dlg_RaiseBid::IDD, pParent)
{

}

Dlg_RaiseBid::~Dlg_RaiseBid()
{
}

void Dlg_RaiseBid::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RBID_INPUT, input);
}


BEGIN_MESSAGE_MAP(Dlg_RaiseBid, CDialogEx)
	ON_BN_CLICKED(IDOK, &Dlg_RaiseBid::OnBnClickedOk)
END_MESSAGE_MAP()


// Dlg_RaiseBid 訊息處理常式


void Dlg_RaiseBid::OnBnClickedOk()
{
	try{
		CString tmp;
		input.GetWindowTextW(tmp);
		if(!tmp.GetLength())
			throw new CString("Please input something!");
		if(((result = _ttoi(tmp)) == 0))
			if(tmp.Compare(_T("0")))
				throw new CString("Please input valid number!");
		CDialogEx::OnOK();
	}catch(String msg){
		AfxMessageBox(*msg);
	}
}
