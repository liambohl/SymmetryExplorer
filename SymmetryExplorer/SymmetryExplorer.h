
// SymmetryExplorer.h : main header file for the SymmetryExplorer application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSymmetryExplorerApp:
// See SymmetryExplorer.cpp for the implementation of this class
//

class CSymmetryExplorerApp : public CWinApp
{
public:
	CSymmetryExplorerApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
};

extern CSymmetryExplorerApp theApp;
