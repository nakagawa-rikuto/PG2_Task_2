#include "Distance.h"

float Length(float pos1, float pos2) {

	//2点間の距離を求める関数
	float distance;
	distance = float(std::sqrt(std::pow(pos2 - pos1, 2)));

	return distance;
}
