#include"DxLib.h"
#include"Clear.h"
#include"KeyInput.h"


Clear::Clear(ISceneChanger* changer) : BaseScene(changer) {}

//������
void Clear::Initialize()
{
	graphic = LoadGraph("image/gameclear.png");					 //clear�摜
}

void Clear::Update()
{
	if (KeyInput::Instace()->GetHitKey(KEY_INPUT_T) != 0)
		mSceneChanger->ChangeScene(eScene_Title);

	if (KeyInput::Instace()->GetHitKey(KEY_INPUT_R) != 0)
		mSceneChanger->ChangeScene(eScene_Game);
}

void Clear::Draw()
{
	DrawGraph(350, 250, graphic, true);

	DrawString(400, 400, "T�Ń^�C�g��", GetColor(255, 255, 255));
	DrawString(400, 450, "R�Ń��g���C", GetColor(255, 255, 255));
}