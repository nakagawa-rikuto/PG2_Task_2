#include "Bullet.h"

void Bullet::Move() {

	pos_.y -= speed_;

	if (pos_.y <= radius_) {

		isActive_ = false;
		pos_ = { -400.0f,-400.0f };
	}
}

void Bullet::SetPos(Vector2 pos) {

	if (!isActive_) {

		this->pos_ = pos;
		this->isActive_ = true;
	}

}

void Bullet::Asport(){

	this->pos_ = { -400.0f, -400.0f };
	this->isActive_ = false;
}

void Bullet::Init() {

	pos_ = { -400.0f,-400.0f };

	radius_ = 8.0f;
	speed_ = 8.0f;

	isActive_ = false;

	color_ = { 255,0,0,255 };
	//gh_ = Novice::LoadTexture("./RS/white1x1.png");
}

void Bullet::Update() {

	if (isActive_) {

		Move();
	}
}

void Bullet::Draw() {

	if (isActive_) {

		Novice::DrawEllipse(
			static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_),
			0.0f, GetColor(color_), kFillModeSolid
		);
	}
}

Bullet::Bullet() {

	Init();
}

Bullet::~Bullet() {}
