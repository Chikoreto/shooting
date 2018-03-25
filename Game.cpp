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

	//プレイヤーと敵の当たり判定
	player_enemy_coll = collision->collisionPlayerEnemy(player->getPlayerPoint(),enemyMgr->getEnemyPoint());

	for (int i=0 ; i<player_enemy_coll.size();i++)
	{
		//1だった場合
		if (player_enemy_coll[i])
		{
			enemyMgr->setDethFlag(i);
			player->setHpDamage(1);
			player->setDamegeFlag(true);
		}
	}

	//弾と敵の当たり判定
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


	//ゲームクリア確認
	if (enemyMgr->getEnemySize() == 0)
	{
		game_clear_flag = true;
	}

	//ゲームオーバー確認
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
