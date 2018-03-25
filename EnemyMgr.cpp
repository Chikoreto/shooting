#include"EnemyMgr.h"

EnemyMgr::EnemyMgr(): file_name("data/stageData.txt"),counter(0)
{
}

//初期化
void EnemyMgr::Initialize()
{
	graph = LoadGraph("image/enemy.png");

	ifs.open(file_name);

	if (ifs.fail())
	{
		return;
	}
	std::getline(ifs, temp);		//一つ目スキップ
	while (std::getline(ifs, temp))
	{
		//データを詰め込む
		enemy_data.push_back(temp);
	}

	for (std::string &s : enemy_data)
	{
		enemy.push_back(Enemy(s, graph));
	}

}

//更新
void EnemyMgr::Update()
{

	//更新
	for (Enemy &e : enemy)
	{

		e.Update(counter);

	}


	//不要な敵の削除
	for (std::vector<Enemy>::iterator it = enemy.begin(); it != enemy.end();)
	{
		if (it->getDethFlag() || it->getSpownCount() > counter)
		{
			++it;
		}
		else
		{
			it = enemy.erase(it);
		}
	}



	orderEnemyPoint();

	//カウンタプラス
	counter++;

}


//描画
void EnemyMgr::Draw()
{
	//描画
	for (Enemy &e : enemy)
	{

		e.Draw();

	}
}

//座標をセット
void EnemyMgr::orderEnemyPoint()
{

	enemy_point.clear();

	for (Enemy &e : enemy)
	{

		enemy_point.push_back(e.getEnemyPoint());

	}
}

//座標を返す
std::vector<Vector2D> EnemyMgr::getEnemyPoint()
{
	return enemy_point;
}


//numの敵のフラグを折る
void EnemyMgr::setDethFlag(int num)
{
	enemy[num].setFlag(false);
}


//敵のサイズ
int EnemyMgr::getEnemySize()
{
	return enemy.size();
}

