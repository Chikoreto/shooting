#include "DxLib.h"
#include "Title.h"
#include "SceneMgr.h"
#include "GameMain.h"
#include"Clear.h"
#include"GameOver.h"

SceneMgr::SceneMgr() : mNextScene(eScene_Non)
{
	mScene = (BaseScene*) new Title(this);
	mStageNumber = 0;
}

//初期化
void SceneMgr::Initialize()
{
	mScene->Initialize();
}

//終了処理
void SceneMgr::Finalize()
{
	mScene->Finalize();
}

//更新
void SceneMgr::Update()
{
	if (mNextScene != eScene_Non)		//次のシーンがセットされたら
	{
		mScene->Finalize();			//終了処理を実行
		delete mScene;				//インスタンス削除

		switch (mNextScene) {	//各シーンごとのインスタンス生成
		case eScene_Title:			//タイトル
			mScene = (BaseScene*) new Title(this);
			break;

		case eScene_Game:
			mScene = (BaseScene*) new GameMain(this);
			break;

		case eScene_GameClear:
			mScene = (BaseScene*) new Clear(this);
			break;
		case eScene_GameOver:
			mScene = (BaseScene*) new GameOver(this);
			break;

		default:
			break;

		}
		mNextScene = eScene_Non;		//次のシーンをクリア
		mScene->Initialize();			//初期化

	}

	mScene->Update();
}

//描画
void SceneMgr::Draw() 
{
	mScene->Draw();
}


void SceneMgr::ChangeScene(eScene NextScene)
{
	mNextScene = NextScene;			//次のシーンをセット
}


void SceneMgr::setStageNumber(int number)
{
	mStageNumber = number;
}

int SceneMgr::getStageNumber()
{
	return mStageNumber;
}
