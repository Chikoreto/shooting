#pragma once
#include "BaseScene.h"
#include "ComonConstant.h"
#include"Game.h"


//ƒ^ƒCƒgƒ‹
class GameMain : public BaseScene {
public:
	GameMain(ISceneChanger* changer);
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	Game* game;
};