#pragma once
#include "IScene.h"

//=======================================
// タイトルシーンのクラス
//=======================================

class Title_Scene 
	:public IScene{
public:

	Title_Scene();
	~Title_Scene();

	void Load()override;
	void Update(InputKeys input)override;
	void Draw()override;

private:

	int gh_;
};

