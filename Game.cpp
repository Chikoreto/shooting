#include"Game.h"

Game::Game():game_clear_flag(false)
{
	player = new Player();
	enemyMgr = new EnemyMgr();
	collision = new Collision();
}

void Game::Initialize()
{
	//player = new Player();
	enemyMgr->Initialize();

}

void Game::Update()
{
	player_enemy_coll.clear();

	player->Uodate();
	enemyMgr->Update();

	//�v���C���[�ƓG�̓����蔻��
	player_enemy_coll = collision->collisionPlayerEnemy(player->getPlayerPoint(),enemyMgr->getEnemyPoint());

	for (int i=0 ; i<player_enemy_coll.size();i++)
	{
		//1�������ꍇ
		if (player_enemy_coll[i])
		{
			enemyMgr->setDethFlag(i);
			player->setHpDamage(1);
			player->setDamegeFlag(true);
		}
	}

	//�e�ƓG�̓����蔻��
	for (int i = 0; i < player->getShotSize(); i++)
	{
		shot_enemy_coll.clear();
		shot_enemy_coll = collision->collisionShotEnemy(player->getShotPoint(i), enemyMgr->getEnemyPoint());

		for (int k = 0; k < shot_enemy_coll.size(); k++)
		{
			if (shot_enemy_coll[k])
			{
				enemyMgr->setDethFlag(k);
				player->setShotFlag(i, false);
			}
		}

	}


	//�Q�[���N���A�m�F
	if (enemyMgr->getEnemySize() == 0)
	{
		game_clear_flag = true;
	}

	//�Q�[���I�[�o�[�m�F
	if (player->getGameOver())
	{
		game_over_flag = true;
	}


}

void Game::Draw()
{
	player->Draw();
	enemyMgr->Draw();
}

bool Game::getClearFlag()
{
	return game_clear_flag;
}

bool Game::getGameOverFlag()
{
	return game_over_flag;
}
