/**
 * \file Point2D.h
 *
 * \author Liam Bohl
 *
 * Simple point which can move around in 2D space
 */

#pragma once
#include <memory>
#include <vector>
#include "PointBase.h"

#define Pi 3.14159265358979323846 ///< Mathematical pi

const double Speed = 3.0;
const double RotationSpeed = Pi / 12;

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
	 * \param xHistory x position history
	 * \param yHistory y position history
	 * \param direction direction as angle CCW from positive x-axis (radians)
	 */
	CPoint2D(int rotationSign, std::vector<double> xHistory, std::vector<double> yHistory, double direction) :
		CPointBase(rotationSign, Speed, RotationSpeed),
		mXHistory(xHistory), mYHistory(yHistory), mDirection(direction) {}

	/// Destructor
	~CPoint2D() {}

	/**
	 * Copy this point and reverse rotation direction
	 * \returns pointer to new point identical to this one but with opposite rotation sign
	 */
	std::shared_ptr<CPoint2D> Reverse()
	{
		return std::make_shared<CPoint2D>(-mRotationSign, mXHistory, mYHistory, mDirection);
	}

	virtual void Forward(int sign, double distance) override;

	virtual void Right(int sign, double distance) override;

	virtual void OnDraw(Gdiplus::Graphics *graphics, const Gdiplus::Pen *pen) override;

private:
	struct Position
	{
		Position(double newX, double newY) : x(newX), y(newY) {}
		double x;
		double y;
	};

	/// History of this point's position
	//std::vector<Position> mPositionHistory = { Position(0, 0) };
	std::vector<double> mXHistory = {0}; ///< history of x positions
	std::vector<double> mYHistory = { 0 }; ///< history of y positions
	double mDirection = 0; ///< current direction as angle CCW from positive x-axis (radians)
};

