#pragma once
#include "Collision.h"
#include "Player.h"
#include "Enemy.h"

class Pl2EnCollision 
	: public Collision{

private:

	Player* player_;
	Enemy* enemy_;

public:

	Pl2EnCollision(Player* player, Enemy* enemy);
	void Collision();
	void OnCollision()override;
};

