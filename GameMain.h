#pragma once
#include "BaseScene.h"
#include "ComonConstant.h"
#include"Game.h"


//�^�C�g��
class GameMain : public BaseScene {
public:
	GameMain(ISceneChanger* changer);
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	Game* game;
};