#include "Pl2EnCollision.h"

Pl2EnCollision::Pl2EnCollision(Player* player, Enemy* enemy){

	player_ = player;
	enemy_ = enemy;
}

void Pl2EnCollision::Collision(){

	dis_ = {
		Length(player_->GetPos().x, enemy_->GetPos().x),
		Length(player_->GetPos().y, enemy_->GetPos().y)
	};

	dis_.sum = dis_.x + dis_.y;
	dis_.radiusSum = player_->GetRadius() + enemy_->GetRadius();
}

void Pl2EnCollision::OnCollision(){

	if (dis_.sum < dis_.radiusSum) {

		player_->Damage();
		enemy_->Death();
	}
}
