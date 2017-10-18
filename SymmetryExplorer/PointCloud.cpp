/**
 * \file PointCloud.cpp
 *
 * \author Liam Bohl
 */

#include "stdafx.h"
#include "PointCloud.h"

using namespace Gdiplus;


CPointCloud::CPointCloud() : mPen(Color::Red, 3)
{
}


CPointCloud::~CPointCloud()
{
}


/**
 * Draw the points of this point cloud onto the play area.
 * \param graphics the graphics object to draw on
 */
void CPointCloud::OnDraw(Graphics *graphics)
{
	for (auto point : mPoints)
		point->OnDraw(graphics, &mPen);
}


/**
 * Move each point forward/backward by its speed
 * \param sign direction of motion (+1 for forward, -1 for backward)
 */
void CPointCloud::Forward(int sign)
{
	for (auto point : mPoints)
		point->Forward(sign);
}


/**
 * Rotate each point right/left by its rotational speed
 * \param sign direction of rotation (+1 for right, -1 for left)
 */
void CPointCloud::Right(int sign)
{
	for (auto point : mPoints)
		point->Right(sign);
}
