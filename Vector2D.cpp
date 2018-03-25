#include"Vector2D.h"
#include<cmath>

//コンストラクタ
Vector2D::Vector2D(double _x, double _y):x(_x),y(_y){}


//ベクトル長さ
double Vector2D::length() const 
{
	return std::sqrt(x*x+ y*y);
	
}

//ベクトル長さ(２乗)
double Vector2D::LengthSquare() const
{
	return x*x + y * y;
}

//指定ベクトルとの内積
double Vector2D::dot(const Vector2D& other) const 
{
	return x * other.x + y * other.y;
}

//指定ベクトルとの距離
double Vector2D::distanceFrom(const Vector2D& other)const
{
	return std::sqrt((other.x - x)*(other.x - x) + (other.y - y)*(other.y - y));
}

//正規化ベクトル
Vector2D Vector2D::normalized() const
{
	return { x / Vector2D::length(),y / Vector2D::length() };
}

//0ベクトルか
bool Vector2D::isZero() const
{
	return x == 0.0 && y == 0.0;
}



//  +演算子のオーバーロード
Vector2D operator+(const Vector2D& v1,const Vector2D& v2)
{
	Vector2D v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    return v;
}
//  -演算子のオーバーロード
Vector2D operator-(const Vector2D& v1,const Vector2D& v2)
{
	Vector2D v;
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    return v;
}
//  スカラー倍
Vector2D operator*(const double d, const Vector2D& v)
{
	Vector2D r;
    r.x = d * v.x;
    r.y = d * v.y;
    return r;
}
//  =演算子のオーバーロード
Vector2D& Vector2D::operator=(const Vector2D& v)
{
    x = v.x;
    y = v.y; 
    return *this; 
}
//  +=演算子のオーバーロード
Vector2D& Vector2D::operator+=(const Vector2D& v)
{
    x += v.x;
    y += v.y;
    return *this;
}
//  -=演算子のオーバーロード
Vector2D& Vector2D::operator-=(const Vector2D& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}