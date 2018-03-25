#pragma once
#include<DxLib.h>
#include"Vector2D.h"
#include"ComonConstant.h"
#include <vector>
#include"KeyInput.h"
#include<math.h>
#include"Shot.h"
#include <algorithm>

class Player
{
public:
	Player();					//�R���X�g���N�^
	int Initialaize();			//������
	void Uodate();				//�X�V
	void Draw();				//�`��

	Vector2D getPlayerPoint();		//�v���C���[�̍��W��Ԃ�
	void setCollPoint();
	void setShotFlag(int num, bool flag);
	int getShotSize();
	
	Vector2D getShotPoint(int num);			//�V���b�g�̍��W�Q��Ԃ�
	void setDamegeFlag(bool flag);			//�_���[�W���󂯂��Ƃ��̃t���O
	void setHpDamage(int damage);			//HP�����炷
	bool getGameOver();						//�Q�[���I�[�o�[�̃t���O��Ԃ�


private:
	Vector2D point,temp_point,coll_point;		//�v���C���[���W,���Wtemp,�����蔻�蒆�S���W
	bool damege_flag;		//�_���[�W���󂯂����̃t���O
	bool game_over;			//game�I�[�o�[�t���O
	
	double move_coef;		//�ړ����x�W��
	double move_speed;		//�ړ����x


	int graphic;			//�L�����N�^�̉摜�n���h��
	int shot_graph;			//�e�摜
	int hp;					//�̗�
	int damage_count;		//���G����
	
	void Move();			//�L�����ړ��֐�
	void SetMoveCoef();		//�ړ��W���ݒ�
	void Attack();			//�v���C���[�U��

	std::vector<Shot> player_shot;	//�v���C���[�̃V���b�g
	std::vector<Vector2D> shot_coll_point;
	int shot_interval;				//�v���C���[�̃V���b�g�Ԋu

	
	bool MoveLimit(Vector2D point);		//�L�����N�^�̈ړ������Ɉ��������邩�𔻒�

	bool getPlayerFlag(Shot shot);		//�V���b�g���Ńt���O�m�F



	
};