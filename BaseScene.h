#pragma once

#include"Task.h"
#include "ISceneChanger.h"

//�V�[���p���N���X
class BaseScene : public Task {

protected:
	ISceneChanger * mSceneChanger;

public:
	BaseScene(ISceneChanger* changer);
	virtual ~BaseScene() {}
	virtual void Initialize() override {}	//�������I�[�o�[���C�h
	virtual void Finalize() override {}		//�I���I�[�o�[���C�h
	virtual void Update() override {}		//�X�V�I�[�o�[���C�h
	virtual void Draw() override {}			//�`��I�[�o�[���C�h

};