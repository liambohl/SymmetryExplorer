/**
 * \file PointCloud2D.h
 *
 * \author Liam Bohl
 *
 * 2-dimensional point cloud
 */

#pragma once

#define Pi 3.14159265358979323846 ///< Mathematical pi

#include "PointCloud.h"

class CPointCloud2D : public CPointCloud
{
public:
	/// Constructor
	CPointCloud2D(int symmetry);

	/// Destructor
	~CPointCloud2D();
};

