#pragma once
#include "BaseScene.h"

//�^�C�g��
class GameOver : public BaseScene {
public:
	GameOver(ISceneChanger* changer);
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	int graphic;
};