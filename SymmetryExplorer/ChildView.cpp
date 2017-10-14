
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "SymmetryExplorer.h"
#include "DoubleBufferDC.h"
#include "ChildView.h"

using namespace Gdiplus;

const int VirtualWidth = 1500; ///< Minimum width of window (virtual pixels)
const int VirtualHeight = 1100; ///< Minimum height of window (virtual pixels)
const int FrameDuration = 30; ///< Duration of each frame (ms)

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
	ON_COMMAND(ID_UP, &CChildView::OnUp)
	ON_COMMAND(ID_DOWN, &CChildView::OnDown)
	ON_COMMAND(ID_RIGHT, &CChildView::OnRight)
	ON_COMMAND(ID_LEFT, &CChildView::OnLeft)
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
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
	// Create helper objects
	CPaintDC paintDC(this); // device context for painting
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC);

	// Get window size
	CRect rect;
	GetClientRect(&rect);

	// Calculate transform
	REAL windowWidth = (REAL)rect.Width();
	REAL windowHeight = (REAL)rect.Height();

	REAL scaleX = windowWidth / VirtualWidth;
	REAL scaleY = windowHeight / VirtualHeight;
	REAL minScale = min(scaleX, scaleY);

	REAL offsetX = windowWidth / 2;
	REAL offsetY = windowHeight / 2;

	// Apply transform
	graphics.TranslateTransform(offsetX, offsetY);
	graphics.ScaleTransform(minScale, minScale);

	// Fill the window with gray
	graphics.Clear(Color(63, 63, 63));

	// Draw play area
	mPlayArea.OnDraw(&graphics);

	// Initiate timer
	if (mFirstDraw)
	{
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);

		// Initialize the elapsed time system
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}

	// Compute the elapsed time since the last draw
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;
}


/**
* Handle timer events
* \param nIDEvent The timer event ID
*/
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}


/**
 * Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context
 * \returns FALSE
 */
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}


/**
 * Move points forward
 */
void CChildView::OnUp()
{
	mPlayArea.OnUp();
}


/**
 * Move points backward
 */
void CChildView::OnDown()
{
	mPlayArea.OnDown();
}


/**
 * Turn points right
 */
void CChildView::OnRight()
{
	mPlayArea.OnRight();
}


/**
 * Turn points left
 */
void CChildView::OnLeft()
{
	mPlayArea.OnLeft();
}
