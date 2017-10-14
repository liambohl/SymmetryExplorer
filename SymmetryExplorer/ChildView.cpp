
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "SymmetryExplorer.h"
#include "DoubleBufferDC.h"
#include "ChildView.h"

using namespace Gdiplus;

const int VirtualWidth = 1500; ///< Minimum width of window (virtual pixels)
const int VirtualHeight = 1100; ///< Minimum height of window (virtual pixels)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC paintDC(this); // device context for painting
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC);

	// Get window size
	CRect rect;
	GetClientRect(&rect);

	// Calculate transform
	double windowWidth = double(rect.Width());
	double windowHeight = double(rect.Height());

	double scaleX = windowWidth / VirtualWidth;
	double scaleY = windowHeight / VirtualHeight;
	double minScale = min(scaleX, scaleY);

	double offsetX = windowWidth / 2.0;
	double offsetY = windowHeight / 2.0;

	// Apply transform
	graphics.TranslateTransform(offsetX, offsetY);
	graphics.ScaleTransform(minScale, minScale);

	// Fill the window with gray
	graphics.Clear(Color(63, 63, 63));

	// Draw play area
}

