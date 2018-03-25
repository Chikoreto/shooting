#include"Player.h"

Player::Player() :
	point(0, WINDOW_HEIGHT/2), temp_point(0, 0),
	damege_flag(false), move_coef(1),move_speed(MOVE_SPEED_DEFAULT),damage_count(0),hp(5), game_over(false),
	shot_interval(0)
{
	//LoadDivGraph("image/Player.png", 1, 1, 1, 32, 32, graphic); //自機画像を分割ロード　歩行
	
	graphic = LoadGraph("image/Player.png");					 //プレイヤー画像
	shot_graph = LoadGraph("image/shot.png");					 //弾画像
}


int Player::Initialaize()
{
	return 0;
}

void Player::Uodate()
{

	if (hp <= 0)
	{
		game_over = true;
	}

	//移動
	Move();
	Attack();

	//無敵時間消費
	if(damage_count >= 0 && damege_flag)
	{
		damage_count--;
	}

	//無敵が終わったのでフラグを落とす
	if (damage_count <= 0 && damege_flag)
	{
		setDamegeFlag(false);
	}

	if (player_shot.size() != 0)
	{
		for (Shot &s : player_shot)
		{
			s.Update();
		}

		//不要なショットの削除
		for (std::vector<Shot>::iterator it = player_shot.begin(); it != player_shot.end();) 
		{
			if (it->getDethFlag())
			{
				++it;
			}
			else 
			{
				it = player_shot.erase(it);
			}
		}

	}


	setCollPoint();


}

void Player::Draw()
{
	//HPバー
	DrawBox(32, 0, 64*5, 16, GetColor(255, 255, 255), FALSE);
	DrawBox(33, 1, 64 * hp+1, 17, GetColor(255, 255, 255), TRUE);
	DrawString(0, 0, "HP", GetColor(255, 255, 255));

	DrawGraph(point.x, point.y, graphic, true);

	//描画
	for (Shot shot : player_shot)
	{
		shot.Draw();
	}


}

void Player::Move()
{
	//斜め移動かを判定
	SetMoveCoef();
	temp_point = point;

	//上へ移動
	if (KeyInput::Instace()->GetHitKeyKeep(KEY_INPUT_UP)) 
	{
		temp_point.y = temp_point.y - (move_speed*move_coef);
	}

	//下へ移動
	if (KeyInput::Instace()->GetHitKeyKeep(KEY_INPUT_DOWN))
	{
		temp_point.y = temp_point.y + (move_speed*move_coef);
	}

	//右へ移動
	if (KeyInput::Instace()->GetHitKeyKeep(KEY_INPUT_RIGHT))
	{
		temp_point.x = temp_point.x + (move_speed*move_coef);
	}

	//左へ移動
	if (KeyInput::Instace()->GetHitKeyKeep(KEY_INPUT_LEFT))
	{
		temp_point.x = temp_point.x - (move_speed*move_coef);
	}


	//移動制限に引っかからなかったらポイントを適用
	if(MoveLimit(temp_point))
	{
		point = temp_point;
	}
	

}

//移動係数を設定
//斜め移動かを判定
void Player::SetMoveCoef()
{
	if (KeyInput::Instace()->GetHitKeyKeep(KEY_INPUT_UP) || KeyInput::Instace()->GetHitKeyKeep(KEY_INPUT_DOWN) &&
		KeyInput::Instace()->GetHitKeyKeep(KEY_INPUT_RIGHT) || KeyInput::Instace()->GetHitKeyKeep(KEY_INPUT_LEFT))
	{
		move_coef = 0.71;
	}
	else 
	{
		move_coef = 1;
	}

}

//キャラクタの移動制限
bool Player::MoveLimit(Vector2D point)
{
	if (point.x < 0 || point.x > WINDOW_WIDTH-32 ||
		point.y < 0 || point.y > WINDOW_HEIGHT-32)
	{
		return false;
	}
	return true;
}


void Player::Attack()
{
	//Zでショット攻撃
	if (KeyInput::Instace()->GetHitKeyKeep(KEY_INPUT_Z))
	{
		if(shot_interval == 0)
		{
			player_shot.push_back(Shot(point, shot_graph));
			shot_interval = 15;
		}
		else
		{
			shot_interval--;
		}
		
	}
	else if(shot_interval <= 15 )
	{
		if (!shot_interval == 0)
		{
			shot_interval--;
		}
		else {
			shot_interval = 0;
		}

	}

}


bool Player::getPlayerFlag(Shot shot)
{
	return shot.getDethFlag();
}

void Player::setCollPoint()
{
	coll_point.x = point.x + 16;
	coll_point.y = point.y + 16;
	
	if (player_shot.size() != 0)
	{
		shot_coll_point.clear();
		for (Shot &s : player_shot)
		{
			shot_coll_point.push_back(s.getShotPoint());
		}
	}
}

void Player::setShotFlag(int num, bool flag)
{
	player_shot[num].setDethFlag(flag);

}

int Player::getShotSize()
{
	return player_shot.size();
}

Vector2D Player::getShotPoint(int num)
{
	return shot_coll_point.at(num);
}

void Player::setDamegeFlag(bool flag)
{
	//フラグが立つ場合は無敵時間設定
	if(flag)
	{
		damage_count = 10;
	}

	damege_flag = flag;
}

void Player::setHpDamage(int damage)
{
	//フラグがたっていなかった場合はダメージ
	if(!damege_flag)
	{
		hp -= damage;
	}
	
}

bool Player::getGameOver()
{
	return game_over;
}


Vector2D Player::getPlayerPoint()
{
	return coll_point;
}



