#pragma once
#include "BaseScene.h"

//�^�C�g��
class Clear : public BaseScene {
public:
	Clear(ISceneChanger* changer);
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	int graphic;
};