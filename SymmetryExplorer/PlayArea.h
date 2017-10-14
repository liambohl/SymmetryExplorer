/**
 * \file PlayArea.h
 *
 * \author Liam Bohl
 *
 * Area to contain, display, and handle play objects
 */

#pragma once

#include "PointCloud2D.h"

class CPlayArea
{
public:
	/// Constructor
	CPlayArea();

	/// Destructor
	~CPlayArea();

	void OnDraw(Gdiplus::Graphics *graphics);

private:
	CPointCloud2D mPointCloud; ///< Cloud of points used to demonstrate symmetry
};

