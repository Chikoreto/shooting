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
	DrawString(300, 100, "A�{�^���ŃQ�[���X�^�[�g", GetColor(255, 255, 255));
	DrawString(0, 650, "�\���L�[�ňړ�", GetColor(255, 255, 255));
	DrawString(0, 700, "Z�L�[�Œe����", GetColor(255, 255, 255));
}