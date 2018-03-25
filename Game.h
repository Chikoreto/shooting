#pragma once
#include "DxLib.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "Collision.h"

class Game
{
public:

	Game();

	void Initialize();
	void Update();
	void Draw();

	bool getClearFlag();
	bool getGameOverFlag();

private:
	Player* player;
	EnemyMgr* enemyMgr;
	Collision* collision;

	bool game_clear_flag;
	bool game_over_flag;

	int k;

	std::vector<int> player_enemy_coll;		//�v���C���[�ƓG�̓����蔻�茋��
	std::vector<int> shot_enemy_coll;		//�e�ƓG�̓����蔻�茋��
};