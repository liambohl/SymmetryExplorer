/**
 * \file PointCloud.h
 *
 * \author Liam Bohl
 *
 * Container to manipulate many points while retaining symmetry
 */

#pragma once
#include <vector>
#include <memory>
#include "PointBase.h"

class CPointCloud
{
public:
	CPointCloud();
	~CPointCloud();

	void OnDraw(Gdiplus::Graphics *graphics);

	void Forward(int sign);

	void Right(int sign);

private:
	std::vector<std::shared_ptr<CPointBase>> mPoints; ///< Constituent points
	Gdiplus::Pen mPen; ///< Pen used to draw points
};

