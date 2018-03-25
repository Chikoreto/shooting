#include"Enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(std::string enemydata,int graph):ss(enemydata), graphic(graph),move_speed(3),deth_flag(false)
{
	//,�ŕ���
	while (std::getline(ss, buffer, ','))
	{
		status.push_back(buffer);
	}

	//�o������
	spown_count = std::stoi(status.at(0));
	//���W
	point.x = std::stoi(status.at(1));
	point.y = std::stoi(status.at(2));
	//�Gpattern
	pattern = std::stoi(status.at(3));
	//�G���x��
	level = std::stoi(status.at(4));


}

void Enemy::Initialayz()
{

}


void Enemy::Update(int counter)
{
	//�G�o������
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


//�ړ�
void Enemy::Move()
{
	if (deth_flag)
	{
		point.x -= move_speed;
	}
}


//�����蔻��p�̍��W���Z�b�g
void Enemy::setCollPoint()
{
	coll_point.x = point.x + 16;
	coll_point.y = point.y + 16;
}


//�����蔻��p�̍��W��n��
Vector2D Enemy::getEnemyPoint()
{
	return coll_point;
}


//�t���O�Z�b�g
void Enemy::setFlag(bool flag)
{
	deth_flag = flag;
}

//�t���O��n��
bool Enemy::getDethFlag()
{
	return deth_flag;
}


//�o�����Ԃ�n��
int Enemy::getSpownCount()
{
	return spown_count;
}
