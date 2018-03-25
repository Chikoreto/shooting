#pragma once
#include<DxLib.h>
#include"Vector2D.h"
#include"ComonConstant.h"
#include <vector>
#include"KeyInput.h"
#include<math.h>

class Shot
{
public:
	Shot();
	Shot(Vector2D player_point, int graph);
	void Initialaize();
	void Update();
	void Draw();

	bool getDethFlag();
	void setDethFlag(bool flag);

	Vector2D getShotPoint();


private:
	Vector2D point,coll_point;		//座標
	int atk_pow;		//攻撃力
	int size;			//大きさ
	int graphic;		//画像ハンドル
	double move_speed;		//移動速度
	bool deth_flag;		//弾生存フラグ

	void Move();		//弾の移動
	bool Shot_deth();	//弾の消滅条件を

	void setCollPoint();	//当たり判定用座標セットする


};