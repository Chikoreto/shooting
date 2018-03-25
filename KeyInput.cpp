#include "KeyInput.h"
#include <DxLib.h>

KeyInput::KeyInput()
{
	memset(keyStatCounter, 0, sizeof(keyStatCounter));
}

bool KeyInput::Update()
{
	//現在の入力状態を配列内格納
	GetHitKeyStateAll(nowKeyStat);

	for (int i = 0; i < KEY_NUM; i++)
	{
		if (nowKeyStat[i] > 0)	//キーが押されていたら
		{
			keyStatCounter[i] += 1;		//キーの押下状態のカウンタを増やす
		}
		else
		{
			keyStatCounter[i] =0;		//キーの押下状態のカウンタを0にする
			
		}

	}



	return true;
}

//keyCodeのキーが押されているかを返す(押された瞬間を返す)
bool KeyInput::GetHitKey(int keyCode)
{
	//範囲外だったらエラー
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

//keyCodeのキーが押され続けているかを返す
bool KeyInput::GetHitKeyKeep(int keyCode)
{
	//範囲外だったらエラー
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


//keyCodeが有効かチェック
bool KeyInput::IsCodeOk(int keyCode)
{
	//0～256以内ならtrue
	if (0 <= keyCode && keyCode <= KEY_NUM)
	{
		return true;
	}
	return false;
}