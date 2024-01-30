#include "Play_Scene.h"
#include "SceneManager.h"
#include "Title_Scene.h"
#include "Novice.h"

Play_Scene::Play_Scene() {

	Load();
}

Play_Scene::~Play_Scene() {}

void Play_Scene::Load() {

	player_ = new Player();
	bullet_ = new Bullet();

	enemy_[0] = new Enemy(100.0f);
	enemy_[1] = new Enemy(200.0f);
	enemy_[2] = new Enemy(300.0f);
	enemy_[3] = new Enemy(400.0f);

	for (int num = 0; num < 4; num++) {

		pl2En_[num] = new Pl2EnCollision(player_, enemy_[num]);
		en2Bu_[num] = new En2BuCollision(bullet_, enemy_[num]);
	}
}

void Play_Scene::Update(InputKeys input) {

	if (player_->GeiIsAlive() == 0) {

		sceneNum_ = TITLE;
	}

	player_->Update(input, bullet_);
	bullet_->Update();

	for (int num = 0; num < 4; num++) {

		enemy_[num]->Update();

		pl2En_[num]->Collision();
		en2Bu_[num]->Collision();

		if (enemy_[num]->GetIsAlive()) {

			pl2En_[num]->OnCollision();
			en2Bu_[num]->OnCollision();
		}
	}
}

void Play_Scene::Draw() {

	player_->Draw();
	bullet_->Draw();
	for (int num = 0; num < 4; num++) {

		enemy_[num]->Draw();
	}
}
