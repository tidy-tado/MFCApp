
// tuan1part3.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Ctuan1part3App:
// See tuan1part3.cpp for the implementation of this class
//

class Ctuan1part3App : public CWinApp
{
public:
	Ctuan1part3App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Ctuan1part3App theApp;
