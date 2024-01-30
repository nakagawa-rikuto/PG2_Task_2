#include "SceneManager.h"
#include "Title_Scene.h"
#include "Play_Scene.h"
#include "Novice.h"

SceneManager::SceneManager(){

	currentSceneNum_ = 0;
	preSceneNum_ = 0;

	sceneArr_[TITLE] = std::make_unique<Title_Scene>();
	sceneArr_[PLAY] = std::make_unique<Play_Scene>();
}

SceneManager::~SceneManager(){}

void SceneManager::Run(InputKeys input){

	// 前フレームのシーンナンバーをpreSceneNum_に保存する
	preSceneNum_ = currentSceneNum_;
	currentSceneNum_ = sceneArr_[currentSceneNum_]->GetSceneNum();

	//sceneArr[preSceneNum_]をUnload
	//sceneArr[currentScene]を初期化

	if (preSceneNum_ != currentSceneNum_) {

		sceneArr_[currentSceneNum_]->Load();
	}

	//currentSceneのUpdate
	sceneArr_[currentSceneNum_]->Update(input);

	//currentSceneのDraw
	sceneArr_[currentSceneNum_]->Draw();
}
