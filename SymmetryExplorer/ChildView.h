
// ChildView.h : interface of the CChildView class
//


#pragma once
#include <memory>
#include "PlayArea.h"

// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

private:
	std::shared_ptr<CPlayArea> mPlayArea; ///< The play area containing the symmetry demonstration
};

