#pragma once
#include<DxLib.h>
#include"Vector2D.h"
#include"ComonConstant.h"
#include"KeyInput.h"
#include <algorithm>
#include <vector>
#include <sstream>


class Enemy
{
public:
	Enemy();					//コンストラクタ
	Enemy(std::string enemydata,int graph);					//コンストラクタ
	void Initialayz();			//初期化
	void Update(int counter);				//更新
	void Draw();				//描画

	void Move();				//移動

	Vector2D getEnemyPoint();	//座標を渡す
	void setCollPoint();
	void setFlag(bool flag);				//フラグを折る
	bool getDethFlag();			//フラグ取得
	int getSpownCount();

private:

	Vector2D point,coll_point;						//敵座標
	double move_speed;					//移動速度
	int hp;								//敵HP
	int graphic;						//敵画像
	int spown_count;					//出現時間
	int pattern;						//敵パターン
	int level;							//敵レベル
	bool deth_flag;						//消滅フラグ
	std::string data;					//敵データ


	std::vector<std::string> status;	//受け取ったデータを分割するため使用
	std::stringstream ss;
	std::string buffer;


};