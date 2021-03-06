#pragma once
#include "afxwin.h"


// Dlg_NewProduct 對話方塊

class Dlg_NewProduct : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_NewProduct)

public:
	Dlg_NewProduct(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~Dlg_NewProduct();

// 對話方塊資料
	enum { IDD = IDD_NEW_PRODUCT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	CEdit name;
	CEdit quantity;
	CEdit init_bid;
	CEdit winning_bid;
	CEdit shipping_cost;
	CEdit deadline;

	void setProduct(AProduct product);
	AProduct getProduct();
	afx_msg void OnBnClickedAddProductBtn();

private:
	AProduct product;
};
