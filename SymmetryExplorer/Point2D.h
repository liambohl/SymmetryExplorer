/**
 * \file Point2D.h
 *
 * \author Liam Bohl
 *
 * Simple point which can move around in 2D space
 */

#pragma once
#include "PointBase.h"

class CPoint2D : public CPointBase
{
public:
	/**
	* Constructor
	* \param rotationSign direction (forward or backward) for rotation
	* \param speed scale factor for forward/backward motion
	* \param rotationSpeed scale factor for rotation
	*/
	CPoint2D(int rotationSign, double speed, double rotationSpeed) :
		CPointBase(rotationSign, speed, rotationSpeed) {}

	/// Destructor
	~CPoint2D() {}

	virtual void Forward(int sign, double distance) override;

	virtual void Right(int sign, double distance) override;

private:
	double mXPos; ///< x value of point position
	double mYPos; ///< y value of point position
	double mDirection; ///< direction as angle CCW from positive x-axis (radians)
};

