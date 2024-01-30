#pragma once
#include "Entity.h"

class Enemy 
	: public Entity{

private:

	Vector2 pos_;

	float radius_;
	float speed_;
	float y_;

	float respawnTimer_;

	SetColor color_;
	int gh_;

	void Move();

public:

	Vector2 GetPos() { return pos_; }
	float GetRadius() { return radius_; }
	bool GetIsAlive() { return isAlive_; }
	void Death() { this->isAlive_ = false; }
	void Respawn(float y);
	void Init(float y);
	void Update();
	void Draw()override;
	Enemy(float y);
	~Enemy();

};

