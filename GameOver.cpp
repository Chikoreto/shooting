#include"DxLib.h"
#include"GameOver.h"
#include"KeyInput.h"


GameOver::GameOver(ISceneChanger* changer) : BaseScene(changer) {}

//������
void GameOver::Initialize()
{
	graphic = LoadGraph("image/gameover.png");					 //clear�摜
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

	DrawString(400, 400, "T�Ń^�C�g��", GetColor(255, 255, 255));
	DrawString(400, 450, "R�Ń��g���C", GetColor(255, 255, 255));
}