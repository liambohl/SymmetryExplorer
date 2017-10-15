/**
 * \file Point2D.cpp
 *
 * \author Liam Bohl
 */

#include "stdafx.h"
#include <cmath>
#include "Point2D.h"

const int ArrowLength = 20;


/**
 * Move the point forward/backward by a given distance
 * \param sign direction of motion (+1 for forward, -1 for backward)
 * \param distance how far to move (virtual pixels)
 */
void CPoint2D::Forward(int sign, double distance)
{
	double xPos = mXHistory.back;
	double yPos = mYHistory.back;
	xPos += sign * distance * cos(mDirection);
	yPos += sign * distance * sin(mDirection);
	mXHistory.push_back(xPos);
	mYHistory.push_back(yPos);
}

/**
 * Rotate the point right/left by a given amount
 * \param sign direction of rotation (+1 for right, -1 for left)
 * \param distance how far to move (radians)
 */
void CPoint2D::Right(int sign, double distance)
{
	//mDirection += sign * GetRotationSign() * distance;
	mDirection += sign * mRotationSign * distance;
}


/**
 * Draw this point onto the play area
 * \param graphics the graphics object to draw on
 * \param pen the pen to draw with
 */
void CPoint2D::OnDraw(Gdiplus::Graphics *graphics, const Gdiplus::Pen *pen)
{
	// Draw path

	// Draw arrow at end of path
	double xPos = mXHistory.back;
	double yPos = mYHistory.back;
	int arrowheadX = xPos + ArrowLength * cos(mDirection);
	int arrowheadY = yPos + ArrowLength * sin(mDirection);
	graphics->DrawLine(pen, xPos, yPos, arrowheadX, arrowheadY);
}
