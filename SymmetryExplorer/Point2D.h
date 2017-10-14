/**
 * \file Point2D.h
 *
 * \author Liam Bohl
 *
 * Simple point which can move around in 2D space
 */

#pragma once
#include <memory>
#include "PointBase.h"

const double Speed = 1.0;
const double RotationSpeed = 0.1;

class CPoint2D : public CPointBase
{
public:
	/**
	 * Constructor
	 */
	CPoint2D() :
		CPointBase(1, Speed, RotationSpeed) {}

	/**
	 * Constructor
	 * \param rotationSign direction (forward or backward) for rotation
	 * \param xPos x position
	 * \param yPos y position
	 * \param direction direction as angle CCW from positive x-axis (radians)
	 */
	CPoint2D(int rotationSign, double xPos, double yPos, double direction) :
		CPointBase(rotationSign, Speed, RotationSpeed),
		mXPos(xPos), mYPos(yPos), mDirection(direction) {}

	// TODO: remove this constructor
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

	/**
	 * Copy this point and reverse rotation direction
	 * \returns pointer to new point identical to this one but with opposite rotation sign
	 */
	std::shared_ptr<CPoint2D> Reverse()
	{
		//return std::make_shared<CPoint2D>(-GetRotationSign(), mXPos, mYPos, mDirection);
		return std::make_shared<CPoint2D>(-mRotationSign, mXPos, mYPos, mDirection);
	}

	virtual void Forward(int sign, double distance) override;

	virtual void Right(int sign, double distance) override;

	virtual void OnDraw(Gdiplus::Graphics *graphics, const Gdiplus::Pen *pen) override;

private:
	double mXPos = 0; ///< x value of point position
	double mYPos = 0; ///< y value of point position
	double mDirection = 0; ///< direction as angle CCW from positive x-axis (radians)
};

