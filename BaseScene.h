#pragma once

#include"Task.h"
#include "ISceneChanger.h"

//シーン用基底クラス
class BaseScene : public Task {

protected:
	ISceneChanger * mSceneChanger;

public:
	BaseScene(ISceneChanger* changer);
	virtual ~BaseScene() {}
	virtual void Initialize() override {}	//初期化オーバーライド
	virtual void Finalize() override {}		//終了オーバーライド
	virtual void Update() override {}		//更新オーバーライド
	virtual void Draw() override {}			//描画オーバーライド

};