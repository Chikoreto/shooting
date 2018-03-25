#include "DxLib.h"
#include "Title.h"
#include "SceneMgr.h"
#include "GameMain.h"
#include"Clear.h"
#include"GameOver.h"

SceneMgr::SceneMgr() : mNextScene(eScene_Non)
{
	mScene = (BaseScene*) new Title(this);
	mStageNumber = 0;
}

//������
void SceneMgr::Initialize()
{
	mScene->Initialize();
}

//�I������
void SceneMgr::Finalize()
{
	mScene->Finalize();
}

//�X�V
void SceneMgr::Update()
{
	if (mNextScene != eScene_Non)		//���̃V�[�����Z�b�g���ꂽ��
	{
		mScene->Finalize();			//�I�����������s
		delete mScene;				//�C���X�^���X�폜

		switch (mNextScene) {	//�e�V�[�����Ƃ̃C���X�^���X����
		case eScene_Title:			//�^�C�g��
			mScene = (BaseScene*) new Title(this);
			break;

		case eScene_Game:
			mScene = (BaseScene*) new GameMain(this);
			break;

		case eScene_GameClear:
			mScene = (BaseScene*) new Clear(this);
			break;
		case eScene_GameOver:
			mScene = (BaseScene*) new GameOver(this);
			break;

		default:
			break;

		}
		mNextScene = eScene_Non;		//���̃V�[�����N���A
		mScene->Initialize();			//������

	}

	mScene->Update();
}

//�`��
void SceneMgr::Draw() 
{
	mScene->Draw();
}


void SceneMgr::ChangeScene(eScene NextScene)
{
	mNextScene = NextScene;			//���̃V�[�����Z�b�g
}


void SceneMgr::setStageNumber(int number)
{
	mStageNumber = number;
}

int SceneMgr::getStageNumber()
{
	return mStageNumber;
}
