/**
 * \file PointCloud2D.cpp
 *
 * \author Liam Bohl
 */

#include "stdafx.h"
#include "PointCloud2D.h"
#include "Point2D.h"


/**
 * Constructor
 * \param symmetry the number of rotational symmetry domains
 */
CPointCloud2D::CPointCloud2D(int symmetry)
{
	CPoint2D point;
	for (int i = 0; i < symmetry; ++i)
	{
		Add(std::make_shared<CPoint2D>(point));
		Add(point.Reverse());
		point.Right(1, 2 * Pi / symmetry);
	}
}


CPointCloud2D::~CPointCloud2D()
{
}
