#include"Enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(std::string enemydata,int graph):ss(enemydata), graphic(graph),move_speed(3),deth_flag(false)
{
	//,で分解
	while (std::getline(ss, buffer, ','))
	{
		status.push_back(buffer);
	}

	//出現時間
	spown_count = std::stoi(status.at(0));
	//座標
	point.x = std::stoi(status.at(1));
	point.y = std::stoi(status.at(2));
	//敵pattern
	pattern = std::stoi(status.at(3));
	//敵レベル
	level = std::stoi(status.at(4));


}

void Enemy::Initialayz()
{

}


void Enemy::Update(int counter)
{
	//敵出現判定
	if (!deth_flag)
	{
		if (spown_count == counter)
		{
			setFlag(true);
		}
		else
		{
			return;
		}
	}

	if (point.x < 0)
	{
		setFlag(false);
	}



	Move();


	setCollPoint();
	
}


void Enemy::Draw()
{
	if(deth_flag)
	{
		DrawGraph(point.x, point.y, graphic, true);
	}
	
}


//移動
void Enemy::Move()
{
	if (deth_flag)
	{
		point.x -= move_speed;
	}
}


//当たり判定用の座標をセット
void Enemy::setCollPoint()
{
	coll_point.x = point.x + 16;
	coll_point.y = point.y + 16;
}


//当たり判定用の座標を渡す
Vector2D Enemy::getEnemyPoint()
{
	return coll_point;
}


//フラグセット
void Enemy::setFlag(bool flag)
{
	deth_flag = flag;
}

//フラグを渡す
bool Enemy::getDethFlag()
{
	return deth_flag;
}


//出現時間を渡す
int Enemy::getSpownCount()
{
	return spown_count;
}
