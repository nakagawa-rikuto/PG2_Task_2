#pragma once
#include "IScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Pl2EnCollision.h"
#include "En2BuCollision.h"

class Play_Scene 
	:public IScene{
public:

	Play_Scene();
	~Play_Scene();

	void Load()override;
	void Update(InputKeys input)override;
	void Draw()override;

private:

	Player* player_;
	Enemy* enemy_[4];
	Bullet* bullet_;
	Pl2EnCollision* pl2En_[4];
	En2BuCollision* en2Bu_[4];
};

