#include"DxLib.h"
#include"GameOver.h"
#include"KeyInput.h"


GameOver::GameOver(ISceneChanger* changer) : BaseScene(changer) {}

//初期化
void GameOver::Initialize()
{
	graphic = LoadGraph("image/gameover.png");					 //clear画像
}

void GameOver::Update()
{
	if (KeyInput::Instace()->GetHitKey(KEY_INPUT_T) != 0)
		mSceneChanger->ChangeScene(eScene_Title);

	if (KeyInput::Instace()->GetHitKey(KEY_INPUT_R) != 0)
		mSceneChanger->ChangeScene(eScene_Game);
}

void GameOver::Draw()
{
	DrawGraph(350, 250, graphic, true);

	DrawString(400, 400, "Tでタイトル", GetColor(255, 255, 255));
	DrawString(400, 450, "Rでリトライ", GetColor(255, 255, 255));
}