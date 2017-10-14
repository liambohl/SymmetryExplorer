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

	///Move point cloud forward
	void CPlayArea::OnUp() { mPointCloud.Forward(1); }

	///Move point cloud backward
	void CPlayArea::OnDown() { mPointCloud.Forward(-1); }

	///Turn point cloud right
	void CPlayArea::OnRight() { mPointCloud.Right(1); }

	///Turn point cloud left
	void CPlayArea::OnLeft() { mPointCloud.Right(-1); }

private:
	CPointCloud2D mPointCloud; ///< Cloud of points used to demonstrate symmetry
};

