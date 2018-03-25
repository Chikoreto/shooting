#include "KeyInput.h"
#include <DxLib.h>

KeyInput::KeyInput()
{
	memset(keyStatCounter, 0, sizeof(keyStatCounter));
}

bool KeyInput::Update()
{
	//���݂̓��͏�Ԃ�z����i�[
	GetHitKeyStateAll(nowKeyStat);

	for (int i = 0; i < KEY_NUM; i++)
	{
		if (nowKeyStat[i] > 0)	//�L�[��������Ă�����
		{
			keyStatCounter[i] += 1;		//�L�[�̉�����Ԃ̃J�E���^�𑝂₷
		}
		else
		{
			keyStatCounter[i] =0;		//�L�[�̉�����Ԃ̃J�E���^��0�ɂ���
			
		}

	}



	return true;
}

//keyCode�̃L�[��������Ă��邩��Ԃ�(�����ꂽ�u�Ԃ�Ԃ�)
bool KeyInput::GetHitKey(int keyCode)
{
	//�͈͊O��������G���[
	if(!IsCodeOk(keyCode))
	{
		return false;
	}
	if (keyStatCounter[keyCode] == 1)
	{
		return true;
	}
	return false;
}

//keyCode�̃L�[�������ꑱ���Ă��邩��Ԃ�
bool KeyInput::GetHitKeyKeep(int keyCode)
{
	//�͈͊O��������G���[
	if (!IsCodeOk(keyCode))
	{
		return false;
	}

	if (keyStatCounter[keyCode] >= 1)
	{
		return true;
	}
	return false;
}


//keyCode���L�����`�F�b�N
bool KeyInput::IsCodeOk(int keyCode)
{
	//0�`256�ȓ��Ȃ�true
	if (0 <= keyCode && keyCode <= KEY_NUM)
	{
		return true;
	}
	return false;
}