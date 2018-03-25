#pragma once

#include "ISceneChanger.h"
#include "BaseScene.h"

class SceneMgr : public ISceneChanger, Task
{
private:
	BaseScene * mScene;			//シーン管理変数
	eScene mNextScene;			//次のシーン管理変数

	int mStageNumber;

public:
	SceneMgr();
	void Initialize() override;		//初期化
	void Finalize() override;		//終了処理
	void Update() override;			//更新
	void Draw() override;			//描画

	//NextSceneにシーンを変更
	void ChangeScene(eScene NetScene) override;

	void setStageNumber(int number);
	int getStageNumber();



};

