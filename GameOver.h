#pragma once
#include "BaseScene.h"

//ƒ^ƒCƒgƒ‹
class GameOver : public BaseScene {
public:
	GameOver(ISceneChanger* changer);
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	int graphic;
};