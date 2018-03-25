#pragma once
#include<DxLib.h>
#include"Vector2D.h"
#include"ComonConstant.h"
#include <vector>
#include"KeyInput.h"
#include<math.h>

class Shot
{
public:
	Shot();
	Shot(Vector2D player_point, int graph);
	void Initialaize();
	void Update();
	void Draw();

	bool getDethFlag();
	void setDethFlag(bool flag);

	Vector2D getShotPoint();


private:
	Vector2D point,coll_point;		//���W
	int atk_pow;		//�U����
	int size;			//�傫��
	int graphic;		//�摜�n���h��
	double move_speed;		//�ړ����x
	bool deth_flag;		//�e�����t���O

	void Move();		//�e�̈ړ�
	bool Shot_deth();	//�e�̏��ŏ�����

	void setCollPoint();	//�����蔻��p���W�Z�b�g����


};