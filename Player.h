#pragma once
#include<DxLib.h>
#include"Vector2D.h"
#include"ComonConstant.h"
#include <vector>
#include"KeyInput.h"
#include<math.h>
#include"Shot.h"
#include <algorithm>

class Player
{
public:
	Player();					//コンストラクタ
	int Initialaize();			//初期化
	void Uodate();				//更新
	void Draw();				//描画

	Vector2D getPlayerPoint();		//プレイヤーの座標を返す
	void setCollPoint();
	void setShotFlag(int num, bool flag);
	int getShotSize();
	
	Vector2D getShotPoint(int num);			//ショットの座標群を返す
	void setDamegeFlag(bool flag);			//ダメージを受けたときのフラグ
	void setHpDamage(int damage);			//HPを減らす
	bool getGameOver();						//ゲームオーバーのフラグを返す


private:
	Vector2D point,temp_point,coll_point;		//プレイヤー座標,座標temp,当たり判定中心座標
	bool damege_flag;		//ダメージを受けたかのフラグ
	bool game_over;			//gameオーバーフラグ
	
	double move_coef;		//移動速度係数
	double move_speed;		//移動速度


	int graphic;			//キャラクタの画像ハンドル
	int shot_graph;			//弾画像
	int hp;					//体力
	int damage_count;		//無敵時間
	
	void Move();			//キャラ移動関数
	void SetMoveCoef();		//移動係数設定
	void Attack();			//プレイヤー攻撃

	std::vector<Shot> player_shot;	//プレイヤーのショット
	std::vector<Vector2D> shot_coll_point;
	int shot_interval;				//プレイヤーのショット間隔

	
	bool MoveLimit(Vector2D point);		//キャラクタの移動制限に引っかかるかを判定

	bool getPlayerFlag(Shot shot);		//ショット消滅フラグ確認



	
};