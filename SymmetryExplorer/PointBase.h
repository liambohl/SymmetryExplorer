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
	 * \param sign direction of motion (+1 for forward, -1 for backward)
	 */
	void Forward(int sign) { Forward(sign, mSpeed); }

	/**
	 * Move the point forward/backward by a given distance
	 * \param sign direction of motion (+1 for forward, -1 for backward)
	 * \param distance how far to move (virtual pixels)
	 */
	virtual void Forward(int sign, double distance) = 0;

	/**
	 * Rotate the point right/left by its rotational speed
	 * \param sign direction of rotation (+1 for right, -1 for left)
	 */
	void Right(int sign) { Right(sign, mSpeed); }

	/**
	 * Rotate the point right/left by a given amount
	 * \param sign direction of rotation (+1 for right, -1 for left)
	 * \param distance how far to move (radians)
	 */
	virtual void Right(int sign, double distance) = 0;

	/**
	 * Draw this point onto the play area
	 * \param graphics the graphics object to draw on
	 * \param pen the pen to draw with
	 */
	virtual void OnDraw(Gdiplus::Graphics *graphics, const Gdiplus::Pen *pen) = 0;

protected:
	/**
	 * Rotation sign
	 * \returns 1 for normal, -1 to make all turns in opposite direction
	 */
	//double GetRotationSign() { return mRotationSign; }
	int mRotationSign; ///< 1 for normal, -1 to make all turns in opposite direction

private:
	double mSpeed; ///< default movement distance (virtual pixels)
	double mRotationSpeed; ///< default rotation angle (radians)
};

