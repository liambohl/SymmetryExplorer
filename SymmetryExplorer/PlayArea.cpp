/**
 * \file PlayArea.cpp
 *
 * \author Liam Bohl
 */

#include "stdafx.h"
#include "PlayArea.h"

using namespace Gdiplus;

const int Width = 1000; ///< Width of this area (virtual pixels)
const int Height = 1000; ///< Height of this area (virtual pixels)


CPlayArea::CPlayArea()
{
}


CPlayArea::~CPlayArea()
{
}


/**
 * Draw this play area and its contained objects
 */
void CPlayArea::OnDraw(Graphics *graphics)
{
	// Fill with black
	SolidBrush areaBrush(Color::Black);
	graphics->FillRectangle(&areaBrush, -Width / 2, -Height / 2, Width, Height);

	// Draw point cloud
	mPointCloud->OnDraw(graphics);
}