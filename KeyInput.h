#pragma once
#include "Singleton.h"

//�L�[���͗p�N���X
class KeyInput : public Singleton<KeyInput>
{
	KeyInput();
	friend Singleton<KeyInput>;

private:

	static const int KEY_NUM = 256;		//�L�[����
	char nowKeyStat[KEY_NUM];			//���݂̃L�[���͏��ۑ��p
	int keyStatCounter[KEY_NUM];		//���݃L�[��������Ă���t���[����
	bool IsCodeOk(int keyCode);			//�L�[�R�[�h���L�����m�F



public:
	bool Update();		//�X�V
	bool GetHitKey(int keyCode);		//keyCode�̃L�[��������Ă��邩�𔻒�
	bool GetHitKeyKeep(int keyCode);	//keyCode�̃L�[�������ꑱ���Ă��邩

};