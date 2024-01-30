#pragma once
#include "Collision.h"
#include "Bullet.h"
#include "Enemy.h"

class En2BuCollision 
	:public Collision{

private:

	Bullet* bullet_;
	Enemy* enemy_;

public:

	En2BuCollision(Bullet* bullet, Enemy* enemy);
	void Collision();
	void OnCollision()override;
};

