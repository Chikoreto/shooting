#pragma once
#include<DxLib.h>
#include"Vector2D.h"
#include"ComonConstant.h"
#include"KeyInput.h"
#include <algorithm>
#include <vector>
#include <sstream>


class Enemy
{
public:
	Enemy();					//�R���X�g���N�^
	Enemy(std::string enemydata,int graph);					//�R���X�g���N�^
	void Initialayz();			//������
	void Update(int counter);				//�X�V
	void Draw();				//�`��

	void Move();				//�ړ�

	Vector2D getEnemyPoint();	//���W��n��
	void setCollPoint();
	void setFlag(bool flag);				//�t���O��܂�
	bool getDethFlag();			//�t���O�擾
	int getSpownCount();

private:

	Vector2D point,coll_point;						//�G���W
	double move_speed;					//�ړ����x
	int hp;								//�GHP
	int graphic;						//�G�摜
	int spown_count;					//�o������
	int pattern;						//�G�p�^�[��
	int level;							//�G���x��
	bool deth_flag;						//���Ńt���O
	std::string data;					//�G�f�[�^


	std::vector<std::string> status;	//�󂯎�����f�[�^�𕪊����邽�ߎg�p
	std::stringstream ss;
	std::string buffer;


};