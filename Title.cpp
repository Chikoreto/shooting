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
	DrawString(300, 100, "Aボタンでゲームスタート", GetColor(255, 255, 255));
	DrawString(0, 650, "十字キーで移動", GetColor(255, 255, 255));
	DrawString(0, 700, "Zキーで弾発射", GetColor(255, 255, 255));
}