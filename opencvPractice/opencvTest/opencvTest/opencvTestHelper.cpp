#include "opencvTestHelper.h"
#include <opencv2/imgproc.hpp>

int samX = 100;
int samY = 200;
int samRadius = 40;


float getDegree(int cx, int cy, int x, int y) {
	float degree;

	if (x > cx) {
		if (y < cy)
			degree = 180 * std::atan((cy - y) / (float)(x - cx)) / PI;
		else
			degree = 360 + 180 * std::atan((cy - y) / (float)(x - cx)) / PI;
	}
	if (x == cx) {
		if (y < cy)
			degree = 90.000000;
		else
			degree = 270.000000;
	}

	if (x < cx) {
		if (y < cy)
			degree = 90 + 180 * std::atan((cx - x) / (double)(cy - y)) / PI;
		else
			degree = 270 + 180 * std::atan((cx - x) / (double)(cy - y)) / PI;
	}

	if (y == cy) {
		if (x > cx)
			degree = 0.000000;
		else
			degree = 180.000000;
	}

	return degree;
}