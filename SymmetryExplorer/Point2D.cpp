/**
 * \file Point2D.cpp
 *
 * \author Liam Bohl
 */

#include "stdafx.h"
#include <cmath>
#include "Point2D.h"


/**
 * Move the point forward/backward by a given distance
 * \param sign direction of motion (+1 for forward, -1 for backward)
 * \param distance how far to move (virtual pixels)
 */
void CPoint2D::Forward(int sign, double distance)
{
	mXPos += sign * distance * cos(mDirection);
	mYPos += sign * distance * sin(mDirection);
}

/**
 * Rotate the point right/left by a given amount
 * \param sign direction of rotation (+1 for right, -1 for left)
 * \param distance how far to move (radians)
 */
void CPoint2D::Right(int sign, double distance)
{
	mDirection += sign * GetRotationSign() * distance;
}