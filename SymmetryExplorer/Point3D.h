/**
 * \file Point3D.h
 *
 * \author Liam Bohl
 *
 * More complex point which can move around the surface of a sphere
 */

#pragma once

#include <memory>
#include <vector>
#include <Eigen\Dense>
#include "PointBase.h"

#define Pi 3.14159265358979323846 ///< Mathematical pi

class CPoint3D : public CPointBase
{
	/// Movement speed (rad / key press)
	const double Speed = Pi / 24;

	/// Rotational speed (rad / key press)
	const double RotationSpeed = Pi / 12;

	/// Length to draw arrowhead (virtual pixels)
	const int ArrowLength = 20;

public:
	/// Constructor
	CPoint3D() : CPointBase(Speed, RotationSpeed) {};

	/// Destructor
	~CPoint3D() {}

	std::shared_ptr<CPoint3D> Reverse();

	virtual void Forward(int sign, double distance) override;

	virtual void Right(int sign, double distance) override;

	virtual void OnDraw(Gdiplus::Graphics *graphics, const Gdiplus::Pen *pen) override;

private:
	/// History of this point's position
	std::vector<Eigen::Vector3d> mPositionHistory = { Eigen::Vector3d(1.0, 0.0, 0.0) };

	/// current direction as angle CCW from positive x-axis (radians)
	Eigen::Vector3d mDirection = Eigen::Vector3d(0.0, 1.0, 0.0);
};

