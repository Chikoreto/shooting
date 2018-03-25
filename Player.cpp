#include"Player.h"

Player::Player() :
	point(0, WINDOW_HEIGHT/2), temp_point(0, 0),
	damege_flag(false), move_coef(1),move_speed(MOVE_SPEED_DEFAULT),damage_count(0),hp(5), game_over(false),
	shot_interval(0)
{
	//LoadDivGraph("image/Player.png", 1, 1, 1, 32, 32, graphic); //���@�摜�𕪊����[�h�@���s
	
	graphic = LoadGraph("image/Player.png");					 //�v���C���[�摜
	shot_graph = LoadGraph("image/shot.png");					 //�e�摜
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

	//�ړ�
	Move();
	Attack();

	//���G���ԏ���
	if(damage_count >= 0 && damege_flag)
	{
		damage_count--;
	}

	//���G���I������̂Ńt���O�𗎂Ƃ�
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

		//�s�v�ȃV���b�g�̍폜
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
	//HP�o�[
	DrawBox(32, 0, 64*5, 16, GetColor(255, 255, 255), FALSE);
	DrawBox(33, 1, 64 * hp+1, 17, GetColor(255, 255, 255), TRUE);
	DrawString(0, 0, "HP", GetColor(255, 255, 255));

	DrawGraph(point.x, point.y, graphic, true);

	//�`��
	for (Shot shot : player_shot)
	{
		shot.Draw();
	}


}

void Player::Move()
{
	//�΂߈ړ����𔻒�
	SetMoveCoef();
	temp_point = point;

	//��ֈړ�
	if (KeyInput::Instace()->GetHitKeyKeep(KEY_INPUT_UP)) 
	{
		temp_point.y = temp_point.y - (move_speed*move_coef);
	}

	//���ֈړ�
	if (KeyInput::Instace()->GetHitKeyKeep(KEY_INPUT_DOWN))
	{
		temp_point.y = temp_point.y + (move_speed*move_coef);
	}

	//�E�ֈړ�
	if (KeyInput::Instace()->GetHitKeyKeep(KEY_INPUT_RIGHT))
	{
		temp_point.x = temp_point.x + (move_speed*move_coef);
	}

	//���ֈړ�
	if (KeyInput::Instace()->GetHitKeyKeep(KEY_INPUT_LEFT))
	{
		temp_point.x = temp_point.x - (move_speed*move_coef);
	}


	//�ړ������Ɉ���������Ȃ�������|�C���g��K�p
	if(MoveLimit(temp_point))
	{
		point = temp_point;
	}
	

}

//�ړ��W����ݒ�
//�΂߈ړ����𔻒�
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

//�L�����N�^�̈ړ�����
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
	//Z�ŃV���b�g�U��
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
	//�t���O�����ꍇ�͖��G���Ԑݒ�
	if(flag)
	{
		damage_count = 10;
	}

	damege_flag = flag;
}

void Player::setHpDamage(int damage)
{
	//�t���O�������Ă��Ȃ������ꍇ�̓_���[�W
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



