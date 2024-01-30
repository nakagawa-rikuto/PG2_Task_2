#pragma once
#include "Vector2.h"
#include "Novice.h"
#include "Distance.h"

class Collision {
protected:

	Distance dis_;

public:

	virtual void OnCollision() = 0;
};

