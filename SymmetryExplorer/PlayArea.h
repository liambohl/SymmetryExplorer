/**
 * \file PlayArea.h
 *
 * \author Liam Bohl
 *
 * Area to contain, display, and handle play objects
 */

#pragma once

#include <memory>
#include "PointCloud.h"

class CPlayArea
{
public:
	/// Constructor
	CPlayArea();

	/// Destructor
	~CPlayArea();

	void OnDraw(Gdiplus::Graphics *graphics);

private:
	std::shared_ptr<CPointCloud> mPointCloud; ///< Cloud of points used to demonstrate symmetry
};

