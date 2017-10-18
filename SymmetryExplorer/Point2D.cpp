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
	Position currentPos = mPositionHistory.back();
	currentPos.x += sign * distance * cos(mDirection);
	currentPos.y += sign * distance * sin(mDirection);
	mPositionHistory.push_back(currentPos);
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
 * Copy this point and reverse rotation direction
 * \returns pointer to new point identical to this one but with opposite rotation sign
 */
std::shared_ptr<CPoint2D> CPoint2D::Reverse()
{
	auto reversePoint = std::make_shared<CPoint2D>(*this);
	reversePoint->SwitchRotationSign();
	return reversePoint;
}


/**
 * Draw this point onto the play area
 * \param graphics the graphics object to draw on
 * \param pen the pen to draw with
 */
void CPoint2D::OnDraw(Gdiplus::Graphics *graphics, const Gdiplus::Pen *pen)
{
	// Draw path
	Position pos1;
	bool first = true;
	for (Position pos2 : mPositionHistory)
	{
		if (first)
		{
			first = false;
		}
		else
		{
			graphics->DrawLine(pen, (int)pos1.x, (int)pos1.y, (int)pos2.x, (int)pos2.y);
			pos1 = pos2;
		}
	}

	// Draw arrow at end of path
	Position currentPos = mPositionHistory.back();
	int arrowheadX = currentPos.x + ArrowLength * cos(mDirection);
	int arrowheadY = currentPos.y + ArrowLength * sin(mDirection);
	graphics->DrawLine(pen, currentPos.x, currentPos.y, arrowheadX, arrowheadY);
}
