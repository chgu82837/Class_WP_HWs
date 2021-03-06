// Dlg_Login.cpp : 實作檔
//

#include "stdafx.h"

// Dlg_Login 對話方塊

IMPLEMENT_DYNAMIC(Dlg_Login, CDialogEx)

Dlg_Login::Dlg_Login(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dlg_Login::IDD, pParent)
{
}

Dlg_Login::~Dlg_Login()
{
}

void Dlg_Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NAME_IPNUT, Input);
}


BEGIN_MESSAGE_MAP(Dlg_Login, CDialogEx)
	ON_BN_CLICKED(ID_LOGIN_OK, &Dlg_Login::OnBnClickedLoginOk)
	ON_BN_CLICKED(ID_LOGIN_CANCEL, &Dlg_Login::OnBnClickedLoginCancel)
END_MESSAGE_MAP()


// LoginDlg 訊息處理常式


void Dlg_Login::OnBnClickedLoginOk()
{
	Input.GetWindowTextW(result);
	this->OnOK();
}


void Dlg_Login::OnBnClickedLoginCancel()
{
	this->OnCancel();
}
