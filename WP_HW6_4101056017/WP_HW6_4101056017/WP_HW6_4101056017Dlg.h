
// WP_HW6_4101056017Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

// CWP_HW6_4101056017Dlg dialog
class CWP_HW6_4101056017Dlg : public CDialogEx
{
// Construction
public:
	CWP_HW6_4101056017Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_WP_HW6_4101056017_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CTabCtrl tab;
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedNewBtn();
	CStatic product_group;
	CStatic bid_group;
	CListCtrl product_list;
	CListCtrl bid_list;
	CButton product_btn;

	afx_msg void OnBnClickedLoadBtn();
	afx_msg void OnBnClickedLoginoutBtn();
	afx_msg void OnBnClickedProductBtn();
	afx_msg void OnNMClickProductList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickBidList(NMHDR *pNMHDR, LRESULT *pResult);
private:
	void update();
	ASys sys;
	ARole user;
	int selected_product;
public:
	afx_msg void OnBnClickedReadme();
	afx_msg void OnBnClickedSaveBtn();
};
