#include "IScene.h"

//初期シーン
int IScene::sceneNum_ = TITLE;

int IScene::GetSceneNum() const{

    return sceneNum_;
}

IScene::~IScene(){}
