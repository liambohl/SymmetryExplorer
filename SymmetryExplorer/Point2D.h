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

const double Speed = 5.0;
const double RotationSpeed = Pi / 12;

class CPoint2D : public CPointBase
{
public:
	/// Constructor
	CPoint2D() : CPointBase(Speed, RotationSpeed) {}

	/// Destructor
	~CPoint2D() {}

	std::shared_ptr<CPoint2D> Reverse();

	virtual void Forward(int sign, double distance) override;

	virtual void Right(int sign, double distance) override;

	virtual void OnDraw(Gdiplus::Graphics *graphics, const Gdiplus::Pen *pen) override;

private:
	struct Position
	{
		Position() {}
		Position(double newX, double newY) : x(newX), y(newY) {}
		double x;
		double y;
	};

	/// History of this point's position
	std::vector<Position> mPositionHistory = { Position(0, 0) };
	double mDirection = 0; ///< current direction as angle CCW from positive x-axis (radians)
};

