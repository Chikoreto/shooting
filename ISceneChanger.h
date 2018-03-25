#pragma once

//���V�[��
typedef enum {
	eScene_Title,		//�^�C�g��
	eScene_Game,		//�Q�[��
	eScene_GameOver,	//�Q�[���I�[�o�[
	eScene_GameClear,	//�Q�[���N���A

	eScene_Non			//�Ȃ�
} eScene;

//�V�[���ύX�p�N���X
class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(eScene NextScene) = 0;	//�w��̃V�[���֕ύX
};