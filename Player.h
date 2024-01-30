#pragma once
#include "Entity.h"
#include "Bullet.h"

class Player 
	:public Entity {
private:

	Vector2 pos_;

	float radius_;
	float speed_;

	bool isShot_;

	SetColor color_;
	//int gh_;

	void Move(InputKeys input, Bullet* bullet);

public:

	void Damage() { this->isAlive_ = false; };
	Vector2 GetPos() { return pos_; }
	float GetRadius() { return radius_; }
	bool GeiIsAlive() { return isAlive_; }
	bool GetIsShot() { return isShot_; }
	void Init();
	void Update(InputKeys input, Bullet* bullet);
	void Draw()override;
	Player();
	~Player();
};

