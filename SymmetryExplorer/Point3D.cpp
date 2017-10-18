/**
 * \file Point3D.cpp
 *
 * \author Liam Bohl
 */

#include "stdafx.h"
#include "Point3D.h"


/**
 * Move the point forward/backward by a given distance
 * \param sign direction of motion (+1 for forward, -1 for backward)
 * \param distance how far to move (virtual pixels)
 */
void CPoint3D::Forward(int sign, double distance)
{
	Transform<double, 3, Affine> rotation(AngleAxis<double>(distance * Pi / 180, direction));
	position = rotation * position;
}


/**
 * Rotate the point right/left by a given amount
 * \param sign direction of rotation (+1 for right, -1 for left)
 * \param distance how far to move (radians)
 */
void CPoint3D::Right(int sign, double distance)
{
	Transform<double, 3, Affine> rotation(AngleAxis<double>(-distance * Pi / 180, position));
	direction = rotation * direction;
}


/**
 * Copy this point and reverse rotation direction
 * \returns pointer to new point identical to this one but with opposite rotation sign
 */
std::shared_ptr<CPoint3D> CPoint3D::Reverse()
{
	auto reversePoint = std::make_shared<CPoint3D>(*this);
	reversePoint->SwitchRotationSign();
	return reversePoint;
}


/**
* Draw this point onto the play area
* \param graphics the graphics object to draw on
* \param pen the pen to draw with
*/
void CPoint3D::OnDraw(Gdiplus::Graphics *graphics, const Gdiplus::Pen *pen)
{

}