#include "Player.h"

void Player::Move(InputKeys input, Bullet* bullet){

	if (input.keys[DIK_W]) {

		pos_.y -= speed_;
	}
	if (input.keys[DIK_S]) {

		pos_.y += speed_;
	}

	if (input.keys[DIK_A]) {

		pos_.x -= speed_;
	}
	if (input.keys[DIK_D]) {

		pos_.x += speed_;
	}

	if (input.keys[DIK_SPACE] && !input.preKeys[DIK_SPACE]) {

		isShot_ = true;
		bullet->SetPos(pos_);
	}

}

void Player::Init(){

	pos_ = { 640.0f, 500.0f };

	radius_ = 16.0f;
	speed_ = 5.0f;

	isShot_ = false;

	isAlive_ = true;

	color_ = { 64,200,126,255 };
	//gh_ = Novice::LoadTexture("./RS/white1x1.png");
}

void Player::Update(InputKeys input, Bullet* bullet){

	//移動の処理
	Move(input,bullet);

	//画面外に行かないようにする処理
	if (pos_.x <= radius_) {

		pos_.x = radius_;
	}
	if (pos_.x >= 1280.0f - radius_) {

		pos_.x = 1280.0f - radius_;
	}

	if (pos_.y <= radius_) {

		pos_.y = radius_;
	}
	if (pos_.y >= 720.0f - radius_) {

		pos_.y = 720.0f - radius_;
	}

}

void Player::Draw(){

	if (isAlive_) {

		Novice::DrawEllipse(
			static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_),
			0.0f, GetColor(color_), kFillModeSolid
		);
	}
}

Player::Player(){

	Init();
}

Player::~Player(){}
