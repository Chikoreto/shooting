#include"EnemyMgr.h"

EnemyMgr::EnemyMgr(): file_name("data/stageData.txt"),counter(0)
{
}

//������
void EnemyMgr::Initialize()
{
	graph = LoadGraph("image/enemy.png");

	ifs.open(file_name);

	if (ifs.fail())
	{
		return;
	}
	std::getline(ifs, temp);		//��ڃX�L�b�v
	while (std::getline(ifs, temp))
	{
		//�f�[�^���l�ߍ���
		enemy_data.push_back(temp);
	}

	for (std::string &s : enemy_data)
	{
		enemy.push_back(Enemy(s, graph));
	}

}

//�X�V
void EnemyMgr::Update()
{

	//�X�V
	for (Enemy &e : enemy)
	{

		e.Update(counter);

	}


	//�s�v�ȓG�̍폜
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

	//�J�E���^�v���X
	counter++;

}


//�`��
void EnemyMgr::Draw()
{
	//�`��
	for (Enemy &e : enemy)
	{

		e.Draw();

	}
}

//���W���Z�b�g
void EnemyMgr::orderEnemyPoint()
{

	enemy_point.clear();

	for (Enemy &e : enemy)
	{

		enemy_point.push_back(e.getEnemyPoint());

	}
}

//���W��Ԃ�
std::vector<Vector2D> EnemyMgr::getEnemyPoint()
{
	return enemy_point;
}


//num�̓G�̃t���O��܂�
void EnemyMgr::setDethFlag(int num)
{
	enemy[num].setFlag(false);
}


//�G�̃T�C�Y
int EnemyMgr::getEnemySize()
{
	return enemy.size();
}

