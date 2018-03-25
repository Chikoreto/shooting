#pragma once
#include "Singleton.h"

//キー入力用クラス
class KeyInput : public Singleton<KeyInput>
{
	KeyInput();
	friend Singleton<KeyInput>;

private:

	static const int KEY_NUM = 256;		//キー総数
	char nowKeyStat[KEY_NUM];			//現在のキー入力情報保存用
	int keyStatCounter[KEY_NUM];		//現在キーが押されているフレーム数
	bool IsCodeOk(int keyCode);			//キーコードが有効か確認



public:
	bool Update();		//更新
	bool GetHitKey(int keyCode);		//keyCodeのキーが押されているかを判定
	bool GetHitKeyKeep(int keyCode);	//keyCodeのキーが押され続けているか

};