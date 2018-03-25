#include"Shot.h"

//�R���X�g���N�^
Shot::Shot(){}

Shot::Shot(Vector2D player_point, int graph): point(player_point),graphic(graph),atk_pow(3),size(PIC_SIZE_DEFOLT), move_speed(8),deth_flag(true)
{
}

//������
void Shot::Initialaize()
{

}

//�X�V
void Shot::Update()
{
	Move();
	setCollPoint();

	//�V���b�g�t���Ooff
	if(Shot_deth())
	{
		deth_flag = false;
	}
}

//�`��
void Shot::Draw()
{
	if (deth_flag)
	{
		DrawGraph(point.x, point.y, graphic, true);
	}
}

//�ړ�
void Shot::Move()
{
	point.x += move_speed;
}


//��ʊO�ɒe���s������
bool Shot::Shot_deth()
{
	if (point.x < 0 || point.x > WINDOW_WIDTH + 32 ||
		point.y < 0 || point.y > WINDOW_HEIGHT + 32)
	{
		return true;
	}
	return false;
}

//�����蔻��p�̍��W���Z�b�g
void Shot::setCollPoint()
{
	coll_point.x = point.x + 16;
	coll_point.y = point.y + 16;
}


//�e�̏��Ńt���O��n��
bool Shot::getDethFlag()
{
	return deth_flag;
}

//�t���O���Z�b�g����
void Shot::setDethFlag(bool flag)
{
	deth_flag = flag;
}


//�����蔻��p���W��Ԃ�
Vector2D Shot::getShotPoint()
{
	return coll_point;
}






