#include"DxLib.h"
#include"GameMain.h"
#include"KeyInput.h"




GameMain::GameMain(ISceneChanger* changer) : BaseScene(changer) {}

//‰Šú‰»
void GameMain::Initialize()
{
	game = new Game();
	game->Initialize();
}

void GameMain::Update()
{
	game->Update();

	if (game->getClearFlag())
	{
		mSceneChanger->ChangeScene(eScene_GameClear);
	}

	if (game->getGameOverFlag())
	{
		mSceneChanger->ChangeScene(eScene_GameOver);
	}
}

void GameMain::Draw()
{

	game->Draw();
}