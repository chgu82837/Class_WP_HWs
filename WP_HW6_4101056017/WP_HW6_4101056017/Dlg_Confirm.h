#pragma once
#include "afxwin.h"

// Dlg_Confirm 對話方塊

class Dlg_Confirm : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Confirm)

public:
	Dlg_Confirm(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~Dlg_Confirm();

// 對話方塊資料
	enum { IDD = IDD_CONFIRM_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	CStatic msg;
	String text;
};
