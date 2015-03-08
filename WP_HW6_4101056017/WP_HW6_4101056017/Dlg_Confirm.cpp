// Dlg_Confirm.cpp : 實作檔
//

#include "stdafx.h"

// Dlg_Confirm 對話方塊

IMPLEMENT_DYNAMIC(Dlg_Confirm, CDialogEx)

Dlg_Confirm::Dlg_Confirm(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dlg_Confirm::IDD, pParent)
{

}

Dlg_Confirm::~Dlg_Confirm()
{
}

void Dlg_Confirm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CONFIRM_MSG, msg);
	msg.SetWindowTextW(*text);
}


BEGIN_MESSAGE_MAP(Dlg_Confirm, CDialogEx)
END_MESSAGE_MAP()


// Dlg_Confirm 訊息處理常式
