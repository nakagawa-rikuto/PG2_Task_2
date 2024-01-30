#pragma once
#include "Vector2.h"
#include "InputKeys.h"

//=======================================
// 各種シーンの基底クラス(interface class)
//=======================================

enum Scene {
	TITLE,
	PLAY
};

class IScene {
protected:

	//現在のシーンを識別するための変数
	static int sceneNum_;

public:

	//必要な関数
	virtual void Load() = 0;
	virtual void Update(InputKeys input) = 0;
	virtual void Draw() = 0;

	int GetSceneNum()const;

	virtual ~IScene();
};

