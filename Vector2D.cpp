#include"Vector2D.h"
#include<cmath>

//�R���X�g���N�^
Vector2D::Vector2D(double _x, double _y):x(_x),y(_y){}


//�x�N�g������
double Vector2D::length() const 
{
	return std::sqrt(x*x+ y*y);
	
}

//�x�N�g������(�Q��)
double Vector2D::LengthSquare() const
{
	return x*x + y * y;
}

//�w��x�N�g���Ƃ̓���
double Vector2D::dot(const Vector2D& other) const 
{
	return x * other.x + y * other.y;
}

//�w��x�N�g���Ƃ̋���
double Vector2D::distanceFrom(const Vector2D& other)const
{
	return std::sqrt((other.x - x)*(other.x - x) + (other.y - y)*(other.y - y));
}

//���K���x�N�g��
Vector2D Vector2D::normalized() const
{
	return { x / Vector2D::length(),y / Vector2D::length() };
}

//0�x�N�g����
bool Vector2D::isZero() const
{
	return x == 0.0 && y == 0.0;
}



//  +���Z�q�̃I�[�o�[���[�h
Vector2D operator+(const Vector2D& v1,const Vector2D& v2)
{
	Vector2D v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    return v;
}
//  -���Z�q�̃I�[�o�[���[�h
Vector2D operator-(const Vector2D& v1,const Vector2D& v2)
{
	Vector2D v;
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    return v;
}
//  �X�J���[�{
Vector2D operator*(const double d, const Vector2D& v)
{
	Vector2D r;
    r.x = d * v.x;
    r.y = d * v.y;
    return r;
}
//  =���Z�q�̃I�[�o�[���[�h
Vector2D& Vector2D::operator=(const Vector2D& v)
{
    x = v.x;
    y = v.y; 
    return *this; 
}
//  +=���Z�q�̃I�[�o�[���[�h
Vector2D& Vector2D::operator+=(const Vector2D& v)
{
    x += v.x;
    y += v.y;
    return *this;
}
//  -=���Z�q�̃I�[�o�[���[�h
Vector2D& Vector2D::operator-=(const Vector2D& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}