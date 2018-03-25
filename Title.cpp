#include"DxLib.h"
#include"Title.h"
#include"KeyInput.h"


Title::Title(ISceneChanger* changer) : BaseScene(changer) {}

//������
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
	DrawString(0, 20, "a�L�[�������ƃQ�[���{�́B", GetColor(255, 255, 255));
}