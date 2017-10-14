
// ChildView.h : interface of the CChildView class
//


#pragma once
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
	bool mFirstDraw = true; ///< True if this will be the first time the pane is drawn
	long long mLastTime; ///< Time of last frame
	double mTimeFreq; ///< Frequency of timer updates
	CPlayArea mPlayArea; ///< The play area containing the symmetry demonstration

public:
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnRight();
	afx_msg void OnLeft();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

