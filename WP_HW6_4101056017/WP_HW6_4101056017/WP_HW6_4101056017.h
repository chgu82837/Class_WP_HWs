
// WP_HW6_4101056017.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

// CWP_HW6_4101056017App:
// See WP_HW6_4101056017.cpp for the implementation of this class
//

class CWP_HW6_4101056017App : public CWinApp
{
public:
	CWP_HW6_4101056017App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CWP_HW6_4101056017App theApp;