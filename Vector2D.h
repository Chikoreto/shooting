#pragma once
//�Ƃ肠����2���x�N�g����������Ȃ������̂ō��
#include<iostream>

struct Vector2D
{
	double x;
	double y;

	//�R���X�g���N�^
	Vector2D() = default;
	Vector2D(double _x, double _y);		

	//�x�N�g���̒���
	double length() const;

	//�x�N�g���̒����Q��
	double LengthSquare() const;

	//��������̃x�N�g���Ƃ̓���
	double dot(const Vector2D& other) const;

	//��������̃x�N�g���Ƃ̋���
	double distanceFrom(const Vector2D& other) const;

	//���K���x�N�g��
	Vector2D normalized() const;

	//�[���x�N�g��������
	bool isZero() const;

	//  =���Z�q�̃I�[�o�[���[�h
	Vector2D& operator=(const Vector2D& v);
	//  +=���Z�q�̃I�[�o�[���[�h
	Vector2D& operator+=(const Vector2D& v);
	//  -=���Z�q�̃I�[�o�[���[�h
	Vector2D& operator-=(const Vector2D& v);

};

//  +���Z�q�̃I�[�o�[���[�h
Vector2D operator+(const Vector2D&, const Vector2D&);
//  -���Z�q�̃I�[�o�[���[�h
Vector2D operator+(const Vector2D&, const Vector2D&);
//  *���Z�q�̃I�[�o�[���[�h
Vector2D operator*(const double, const Vector2D& v);