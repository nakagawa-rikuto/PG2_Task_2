#include "En2BuCollision.h"

En2BuCollision::En2BuCollision(Bullet* bullet, Enemy* enemy){

	bullet_ = bullet;
	enemy_ = enemy;
}

void En2BuCollision::Collision(){

	dis_ = {
		Length(bullet_->GetPos().x, enemy_->GetPos().x),
		Length(bullet_->GetPos().y, enemy_->GetPos().y)
	};

	dis_.sum = dis_.x + dis_.y;
	dis_.radiusSum = bullet_->GetRadius() + enemy_->GetRadius();
}

void En2BuCollision::OnCollision(){

	if (dis_.sum < dis_.radiusSum) {

		enemy_->Death();
		bullet_->Asport();
	}

}
