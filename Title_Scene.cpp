#include "Title_Scene.h"
#include "SceneManager.h"
#include "Play_Scene.h"
#include "Novice.h"

/*===============================================
  TitleSceneで使いたい処理及び関数はここに入力すること
===============================================*/

Title_Scene::Title_Scene(){

	Load();
}

Title_Scene::~Title_Scene(){}

//初期化するための関数
void Title_Scene::Load(){

	gh_ = Novice::LoadTexture("./RS/white1x1.png");
}

void Title_Scene::Update(InputKeys input){

	if (input.keys[DIK_E] && !input.preKeys[DIK_E]) {

		sceneNum_ = PLAY;
	}

}

void Title_Scene::Draw(){

	Novice::DrawSprite(
		0, 0, gh_, 1280, 720, 0.0f, BLACK
	);

	Novice::ScreenPrintf(600, 360, "PG2_Task_2");
	Novice::ScreenPrintf(590, 400, "DIK_E >> PLAY");
}
