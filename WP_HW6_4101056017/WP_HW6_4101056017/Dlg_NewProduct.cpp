// Dlg_NewProduct.cpp : 實作檔
//

#include "stdafx.h"
#include "Dlg_NewProduct.h"

// Dlg_NewProduct 對話方塊

IMPLEMENT_DYNAMIC(Dlg_NewProduct, CDialogEx)

Dlg_NewProduct::Dlg_NewProduct(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dlg_NewProduct::IDD, pParent)
{

}

Dlg_NewProduct::~Dlg_NewProduct()
{
}

void Dlg_NewProduct::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PNAME_INPUT, name);
	DDX_Control(pDX, IDC_QUAN_INPUT, quantity);
	DDX_Control(pDX, IDC_IBID_INPUT, init_bid);
	DDX_Control(pDX, IDC_WBID_INPUT, winning_bid);
	DDX_Control(pDX, IDC_COST_INPUT, shipping_cost);
	DDX_Control(pDX, IDC_DEAD_INPUT, deadline);
}


BEGIN_MESSAGE_MAP(Dlg_NewProduct, CDialogEx)
	ON_BN_CLICKED(IDR_ADD_PRODUCT_BTN, &Dlg_NewProduct::OnBnClickedAddProductBtn)
END_MESSAGE_MAP()


// Dlg_NewProduct 訊息處理常式

void Dlg_NewProduct::OnBnClickedAddProductBtn()
{
	/*
		CEdit name;
	CEdit quantity;
	CEdit init_bid;
	CEdit winning_bid;
	CEdit shipping_cost;
	CEdit deadline;
	*/
	try{
		CString tmp;
#define getinput(X) X.GetWindowTextW(tmp); if(!tmp.GetLength()) throw new CString("Please input something!");

		getinput(name)
		product->name = new CString(tmp);

#define getint_input(X) getinput(X) if(((product->X = _ttoi(tmp)) == 0)) if(tmp.Compare(_T("0"))) throw new CString("Please input valid number!");
		getint_input(quantity);
		getint_input(init_bid);
		getint_input(winning_bid);
		getint_input(shipping_cost);

		getinput(deadline)
		COleDateTime datetime;
		if(!datetime.ParseDateTime(tmp))
			throw new CString("Please input valid datetime!");
		SYSTEMTIME stime;
		datetime.GetAsSystemTime(stime);
		CTime ctime(stime);
		product->deadline = ctime.GetTime();

		product->check();

		this->OnOK();
	}catch(String msg){
		AfxMessageBox(*msg);
	}
}

void Dlg_NewProduct::setProduct(AProduct product)
{
	this->product = product;
}

AProduct Dlg_NewProduct::getProduct()
{
	return this->product;
}