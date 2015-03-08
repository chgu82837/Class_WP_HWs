#pragma once

// Dlg_Login 對話方塊

class Dlg_Login : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Login)

public:
	Dlg_Login(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~Dlg_Login();

// 對話方塊資料
	enum { IDD = IDD_LOGIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
	CEdit Input;
public:
	CString result;

	afx_msg void OnBnClickedLoginOk();
	afx_msg void OnBnClickedLoginCancel();
};
