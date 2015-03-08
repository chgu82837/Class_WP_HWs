
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions


#include <afxdisp.h>        // MFC Automation classes



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC support for ribbons and control bars

// ====================

#define Strings vector<CString*>*
#define String CString*

#define ASys AucSys*
#define ABase AucBase*
#define ARole AucRole*
#define ASeller AucSeller*
#define ABuyer AucBuyer*
#define AItem AucItem*
#define AProduct AucProduct*
#define ABid AucBid*
#define ARela AucRela*

#define AucProducts vector<AucProduct*>*
#define AucRoles vector<AucRole*>*
#define AucBids vector<AucBid*>*
#define AucRelas vector<AucRela*>*

#define pV(X,Y) (*(X))[Y] 

using namespace std;

#include "json/json.h"
#include "vector"
#include "string"
#include <fstream>
#include "afxdialogex.h"

#include "resource.h"		// main symbols

#include "helpers.h"

class AucSys;
class AucBase;
class AucRole;
class AucSeller;
class AucBuyer;
class AucItem;
class AucProduct;
class AucBid;
class AucRela;

#include "AucSys.h"
#include "AucBase.h"
#include "AucRole.h"
#include "AucSeller.h"
#include "AucBuyer.h"
#include "AucItem.h"
#include "AucProduct.h"
#include "AucBid.h"
#include "AucRela.h"

class CWP_HW6_4101056017App;
class CWP_HW6_4101056017Dlg;
class Dlg_Login;
class Dlg_NewProduct;
class Dlg_RaiseBid;
class Dlg_Confirm;

#include "WP_HW6_4101056017.h"
#include "WP_HW6_4101056017Dlg.h"
#include "Dlg_Login.h"
#include "Dlg_NewProduct.h"
#include "Dlg_RaiseBid.h"
#include "Dlg_Confirm.h"

// ====================

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


