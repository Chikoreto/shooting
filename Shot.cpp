#include"Shot.h"

//コンストラクタ
Shot::Shot(){}

Shot::Shot(Vector2D player_point, int graph): point(player_point),graphic(graph),atk_pow(3),size(PIC_SIZE_DEFOLT), move_speed(8),deth_flag(true)
{
}

//初期化
void Shot::Initialaize()
{

}

//更新
void Shot::Update()
{
	Move();
	setCollPoint();

	//ショットフラグoff
	if(Shot_deth())
	{
		deth_flag = false;
	}
}

//描画
void Shot::Draw()
{
	if (deth_flag)
	{
		DrawGraph(point.x, point.y, graphic, true);
	}
}

//移動
void Shot::Move()
{
	point.x += move_speed;
}


//画面外に弾が行ったか
bool Shot::Shot_deth()
{
	if (point.x < 0 || point.x > WINDOW_WIDTH + 32 ||
		point.y < 0 || point.y > WINDOW_HEIGHT + 32)
	{
		return true;
	}
	return false;
}

//当たり判定用の座標をセット
void Shot::setCollPoint()
{
	coll_point.x = point.x + 16;
	coll_point.y = point.y + 16;
}


//弾の消滅フラグを渡す
bool Shot::getDethFlag()
{
	return deth_flag;
}

//フラグをセットする
void Shot::setDethFlag(bool flag)
{
	deth_flag = flag;
}


//当たり判定用座標を返す
Vector2D Shot::getShotPoint()
{
	return coll_point;
}






