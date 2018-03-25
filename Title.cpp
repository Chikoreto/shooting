#include"DxLib.h"
#include"Title.h"
#include"KeyInput.h"


Title::Title(ISceneChanger* changer) : BaseScene(changer) {}

//初期化
void Title::Initialize()
{

}

void Title::Update()
{
	if (KeyInput::Instace()->GetHitKey(KEY_INPUT_A) != 0)
		mSceneChanger->ChangeScene(eScene_Game);
}

void Title::Draw()
{
	DrawString(0, 20, "aキーを押すとゲーム本体。", GetColor(255, 255, 255));
}