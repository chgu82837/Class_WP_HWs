
// WP_HW6_4101056017Dlg.cpp : implementation file
//

#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	//ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()

// CWP_HW6_4101056017Dlg dialog

CWP_HW6_4101056017Dlg::CWP_HW6_4101056017Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWP_HW6_4101056017Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWP_HW6_4101056017Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, tab);
	DDX_Control(pDX, IDC_PRODUCT_GROUP, product_group);
	DDX_Control(pDX, IDC_BID_GROUP, bid_group);
	DDX_Control(pDX, IDC_PRODUCT_BTN, product_btn);
	DDX_Control(pDX, IDC_PRODUCT_LIST, product_list);
	DDX_Control(pDX, IDC_BID_LIST, bid_list);
}

BEGIN_MESSAGE_MAP(CWP_HW6_4101056017Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CWP_HW6_4101056017Dlg::OnTcnSelchangeTab)
	ON_BN_CLICKED(IDC_NEW_BTN, &CWP_HW6_4101056017Dlg::OnBnClickedNewBtn)
	ON_BN_CLICKED(IDC_LOAD_BTN, &CWP_HW6_4101056017Dlg::OnBnClickedLoadBtn)
	ON_BN_CLICKED(IDC_LOGINOUT_BTN, &CWP_HW6_4101056017Dlg::OnBnClickedLoginoutBtn)
	ON_BN_CLICKED(IDC_PRODUCT_BTN, &CWP_HW6_4101056017Dlg::OnBnClickedProductBtn)
	ON_NOTIFY(NM_CLICK, IDC_PRODUCT_LIST, &CWP_HW6_4101056017Dlg::OnNMClickProductList)
	ON_NOTIFY(NM_CLICK, IDC_BID_LIST, &CWP_HW6_4101056017Dlg::OnNMClickBidList)
	ON_BN_CLICKED(IDC_README, &CWP_HW6_4101056017Dlg::OnBnClickedReadme)
	ON_BN_CLICKED(IDC_SAVE_BTN, &CWP_HW6_4101056017Dlg::OnBnClickedSaveBtn)
END_MESSAGE_MAP()

void CWP_HW6_4101056017Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWP_HW6_4101056017Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWP_HW6_4101056017Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/***************************
4101056017 邱冠喻 第六次作業 12/30
4101056017 Chiu Guan-Yu TheSixthHomework 12/30
***************************/

BOOL CWP_HW6_4101056017Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	tab.InsertItem(0,_T("shopping"));
	tab.InsertItem(1,_T("selling"));

	sys = new AucSys();
	user = nullptr;
	selected_product = -1;

	AucBase::setAucSys(sys);
	AucProduct::set_list_head(&product_list);
	AucBid::set_list_head(&bid_list);

	update();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWP_HW6_4101056017Dlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	update();
	*pResult = 0;
}


void CWP_HW6_4101056017Dlg::OnBnClickedNewBtn()
{
	Dlg_Confirm* confirm_dlg = new Dlg_Confirm();
	confirm_dlg->text = new CString(_T("Open a new market? Old state will be lost if you dont save it!"));
	if (confirm_dlg->DoModal() == IDOK) {
		delete sys;
		sys = new AucSys();
		user = nullptr;
		selected_product = -1;
		AucBase::setAucSys(sys);
		update();
	}
}


void CWP_HW6_4101056017Dlg::OnBnClickedLoadBtn()
{
	try{
		CFileDialog FileDlg(TRUE, CString(".json"), NULL, OFN_HIDEREADONLY,CString(_T("JSON Files (*.json)|*.json|")));
		CString fname;
		if (FileDlg.DoModal() == IDOK)  
		{  
			fname = FileDlg.GetPathName();
			delete sys;
			sys = new AucSys(&fname);
			user = nullptr;
			selected_product = -1;
			AucBase::setAucSys(sys);

			AfxMessageBox(_T("Load success!"));
			update();
		}
	}catch(String msg){
		AfxMessageBox(*msg);
	}
}


void CWP_HW6_4101056017Dlg::OnBnClickedLoginoutBtn()
{
	try{
		Dlg_Login dialog;
		CString* name;
		bool* created = new bool(true);
		if (dialog.DoModal() == IDOK) {
			name = new CString(dialog.result);
			user = sys->getUser(name,created);
			AfxMessageBox((*created) ? _T("Login success!") : _T("Hello new-comer!"));
			update();
		}
		//user = sys->
	}catch(String msg){
		AfxMessageBox(*msg);
	}
}

void CWP_HW6_4101056017Dlg::OnBnClickedProductBtn()
{
	try{
		Dlg_NewProduct dialog;
		AProduct product = new AucProduct();
		dialog.setProduct(product);
		if (dialog.DoModal() == IDOK) {
			product->save(sys,user);
			AfxMessageBox(_T("Product added!"));
			update();
		}
		//user = sys->
	}catch(String msg){
		AfxMessageBox(*msg);
	}
}

void CWP_HW6_4101056017Dlg::OnBnClickedReadme()
{
	CAboutDlg dlg;
	dlg.DoModal();
}


void CWP_HW6_4101056017Dlg::OnBnClickedSaveBtn()
{
	try{
		CFileDialog FileDlg(FALSE, CString(".json"), NULL, OFN_HIDEREADONLY,CString(_T("JSON Files (*.json)|*.json|")));
		CString fname;
		if (FileDlg.DoModal() == IDOK)  
		{  
			fname = FileDlg.GetPathName();
			sys->save(&fname);
			AfxMessageBox(_T("Saved!"));
		}
	}catch(String msg){
		AfxMessageBox(*msg);
	}
}

void CWP_HW6_4101056017Dlg::OnNMClickProductList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	auto pos = product_list.GetFirstSelectedItemPosition();
	auto selected = product_list.GetNextSelectedItem(pos);
	Dlg_RaiseBid* raise_dialog;
	Dlg_Confirm* confirm_dlg;
	ABid b;
	AProduct p;

	if(user == nullptr)
		return;
	if(selected == -1)
		return;

	switch(tab.GetCurSel())
	{
	case 0: // Buyer
		try{
			p = pV(sys->products,selected);
			p->ended_chk();
			raise_dialog = new Dlg_RaiseBid();
			if (raise_dialog->DoModal() == IDOK) {
				b = p->raise(raise_dialog->result);
				b->save(sys,user,p);
				if(b->got)
					AfxMessageBox(_T("You have won the product!"));
				update();
			}
		}catch(String msg){
			AfxMessageBox(*msg);
		}
		break;
	case 1: // Seller
		if(selected_product == selected){ // double click
			try{
				p = pV(sys->products,selected);
				p->ended_chk();
				confirm_dlg = new Dlg_Confirm();
				confirm_dlg->text = new CString(_T("Close the auction for this product?"));
				if (confirm_dlg->DoModal() == IDOK) {
					p->close();
					p->chkBids();
					AfxMessageBox(_T("The auction has been closed!"));
					update();
				}
			}catch(String msg){
				AfxMessageBox(*msg);
			}
		}
		else{
			selected_product = selected;
			update();
		}
		break;
	}
	*pResult = 0;
}


void CWP_HW6_4101056017Dlg::OnNMClickBidList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	auto pos = bid_list.GetFirstSelectedItemPosition();
	auto selected = bid_list.GetNextSelectedItem(pos);
	Dlg_Confirm* confirm_dlg;
	AucRelas rela_i;
	ABid b;

	if(user == nullptr)
		return;
	if(selected == -1)
		return;

	switch(tab.GetCurSel())
	{
	case 0: // Buyer
		try{
			b = pV(user->bids,selected)->getTargetAsBid();
			b->receive(true);
			confirm_dlg = new Dlg_Confirm();
			confirm_dlg->text = new CString(_T("Recieve this product?"));
			if (confirm_dlg->DoModal() == IDOK) {
				b->receive(false);
				AfxMessageBox(_T("You have received this product!"));
				update();
			}
		}catch(String msg){
			AfxMessageBox(*msg);
		}
		break;
	case 1: // Seller
		try{
			rela_i = pV(user->products,selected_product)->getTargetAsProduct()->bids;
			b = pV(rela_i,selected)->getTargetAsBid();
			b->ship(true);
			confirm_dlg = new Dlg_Confirm();
			confirm_dlg->text = new CString(_T("Ship this product to the customer?"));
			if (confirm_dlg->DoModal() == IDOK) {
				b->ship(false);
				AfxMessageBox(_T("The product has been shipped!"));
				update();
			}
		}catch(String msg){
			AfxMessageBox(*msg);
		}
		break;
	}
	*pResult = 0;
}


void CWP_HW6_4101056017Dlg::update()
{
	static CString login_msg = CString("Please login!");
	AucRelas rela_i;
	switch(tab.GetCurSel())
	{
	case 0: // Buyer
		product_group.SetWindowTextW(_T("All products"));
		bid_group.SetWindowTextW(_T("Your bids"));
		product_btn.EnableWindow(false);
		clearList(&product_list);
		clearList(&bid_list);
		AucBid::switch_name_col(&bid_list,false);

		for (int i = 0; i < sys->products->size(); i++)
			(*(sys->products))[i]->to_list(&product_list);

		if(user == nullptr){
			bid_list.InsertItem(0,login_msg);
		}
		else{
			rela_i = user->bids;
			for (int i = 0; i < rela_i->size(); i++)
				(*rela_i)[i]->getTargetAsBid()->to_list(&bid_list);
		}
		break;
	case 1: // Seller
		product_group.SetWindowTextW(_T("Your products"));
		bid_group.SetWindowTextW(_T("bids of products"));
		clearList(&product_list);
		clearList(&bid_list);
		AucBid::switch_name_col(&bid_list,true);

		if(user == nullptr){
			product_list.InsertItem(0,login_msg);
			bid_list.InsertItem(0,login_msg);
			product_btn.EnableWindow(false);
		}
		else{
			rela_i = user->products;
			for (int i = 0; i < rela_i->size(); i++)
				(*rela_i)[i]->getTargetAsProduct()->to_list(&product_list);

			if(selected_product == -1){
				bid_list.InsertItem(0,_T("Please select one product!"));
			}
			else{
				product_list.SetItemState(selected_product,LVIS_SELECTED, LVIS_SELECTED);
				rela_i = (*(user->products))[selected_product]->getTargetAsProduct()->bids;
				for (int i = 0; i < rela_i->size(); i++)
					(*rela_i)[i]->getTargetAsBid()->to_list(&bid_list,true);
			}
			product_btn.EnableWindow(true);
		}

		break;
	default:;
	} 
}

/***************************
4101056017 邱冠喻 第六次作業 12/30
4101056017 Chiu Guan-Yu TheSixthHomework 12/30
***************************/
