#pragma once

#include "ISceneChanger.h"
#include "BaseScene.h"

class SceneMgr : public ISceneChanger, Task
{
private:
	BaseScene * mScene;			//�V�[���Ǘ��ϐ�
	eScene mNextScene;			//���̃V�[���Ǘ��ϐ�

	int mStageNumber;

public:
	SceneMgr();
	void Initialize() override;		//������
	void Finalize() override;		//�I������
	void Update() override;			//�X�V
	void Draw() override;			//�`��

	//NextScene�ɃV�[����ύX
	void ChangeScene(eScene NetScene) override;

	void setStageNumber(int number);
	int getStageNumber();



};

