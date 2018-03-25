#pragma once
#include<DxLib.h>
#include"Vector2D.h"
#include"ComonConstant.h"
#include <vector>
#include"KeyInput.h"
#include"Enemy.h"
#include <fstream>
#include<string>
#include <iostream>


class EnemyMgr
{

public:
	EnemyMgr();
	void Initialize();
	void Update();
	void Draw();
	

	std::vector<Vector2D> getEnemyPoint();
	void setDethFlag(int num);

	int getEnemySize();


private:

	std::vector<Vector2D> enemy_point;	//���W���X�g
	std::vector<Enemy> enemy;			//�G���X�g
	std::vector<std::string> enemy_data;
	std::string temp;
	std::string file_name;
	std::ifstream ifs;
	int counter;			//�G�o���p�J�E���^
	int graph;				//�摜�n���h���p


	void orderEnemyPoint();

};