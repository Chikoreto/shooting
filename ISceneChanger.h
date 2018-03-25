#pragma once

//総シーン
typedef enum {
	eScene_Title,		//タイトル
	eScene_Game,		//ゲーム
	eScene_GameOver,	//ゲームオーバー
	eScene_GameClear,	//ゲームクリア

	eScene_Non			//なし
} eScene;

//シーン変更用クラス
class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(eScene NextScene) = 0;	//指定のシーンへ変更
};