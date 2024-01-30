#pragma once
#include "Entity.h"

class Bullet {

private:

	Vector2 pos_;

	float radius_;
	float speed_;

	bool isActive_;

	SetColor color_;
	//int gh_;

	void Move();

public:

	Vector2 GetPos() { return pos_; }
	void SetPos(Vector2 pos);
	void Asport();
	float GetRadius() { return radius_; }

	void Init();
	void Update();
	void Draw();

	Bullet();
	~Bullet();
};

