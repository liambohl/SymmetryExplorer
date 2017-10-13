/**
 * \file PointBase.h
 *
 * \author Liam Bohl
 *
 * Basem class for 2D and 3D points
 */

#pragma once
class CPointBase
{
public:
	/**
	 * Constructor
	 * \param rotationSign direction (forward or backward) for rotation
	 * \param speed scale factor for forward/backward motion
	 * \param rotationSpeed scale factor for rotation
	 */
	CPointBase(int rotationSign, double speed, double rotationSpeed) :
		mRotationSign(rotationSign), mSpeed(speed), mRotationSpeed(rotationSpeed) {}

	/** Destructor */
	~CPointBase() {}

	/**
	 * Move the point forward/backward by its speed
	 * \param sign direction (forward or backward) of motion
	 */
	virtual void Forward(int sign) { Forward(sign, mSpeed); }

	/**
	 * Move the point forward/backward by a given distance
	 * \param sign direction (forward or backward) of motion
	 * \param distance how far to move
	 */
	virtual void Forward(int sign, double distance) {}

private:
	int mRotationSign; ///< 1 for forward, -1 for backward rotation
	double mSpeed; ///< scale factor for forward/backward motion
	double mRotationSpeed; ///< scale factor for rotation
};

