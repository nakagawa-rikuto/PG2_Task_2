#include "Color.h"

int GetColor(SetColor color) {
	// 8ビットごとに赤、緑、青、アルファ(透明度)をOR演算して組み合わせる
	unsigned int result = (color.alpha_) | (color.red_ << 24) | (color.green_ << 16) | (color.blue_ << 8);
	return result;
}
