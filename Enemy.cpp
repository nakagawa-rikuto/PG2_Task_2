#include "Enemy.h"
#include <math.h>

void Enemy::Move() {

	pos_.x += speed_;
}

void Enemy::Respawn(float y) {

	while (pos_.x < radius_ || pos_.y < radius_) {

		pos_ = { float(rand() % 1200 - int(radius_)),y };
	}

	respawnTimer_ = 200.0f;

	isAlive_ = true;
}

void Enemy::Init(float y) {

	radius_ = 16.0f;
	speed_ = 3.0f;
	y_ = y;

	Respawn(y_);

	color_ = { 255,255,255,255 };
	gh_ = Novice::LoadTexture("./RS/white1x1.png");

}

void Enemy::Update() {

	if (isAlive_) {

		//移動の処理
		Move();

		//画面外に行った時の処理
		if (pos_.x <= radius_ || pos_.x >= 1280.0f - radius_) {

			speed_ *= -1.0f;
		}

		if (pos_.y <= radius_ || pos_.y >= 1280.0f - radius_) {

			speed_ *= -1.0f;
		}
	} else {

		respawnTimer_--;

		if (respawnTimer_ <= 0.0f) {

			Respawn(y_);
		}
	}
}

void Enemy::Draw() {

	if (isAlive_) {

		Novice::DrawEllipse(
			static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_),
			0.0f, GetColor(color_), kFillModeSolid
		);
	}
}

Enemy::Enemy(float y) {

	Init(y);
}

Enemy::~Enemy() {}
