#pragma once
//とりあえず2次ベクトルが見つからなかったので作る
#include<iostream>

struct Vector2D
{
	double x;
	double y;

	//コンストラクタ
	Vector2D() = default;
	Vector2D(double _x, double _y);		

	//ベクトルの長さ
	double length() const;

	//ベクトルの長さ２乗
	double LengthSquare() const;

	//もう一方のベクトルとの内積
	double dot(const Vector2D& other) const;

	//もう一方のベクトルとの距離
	double distanceFrom(const Vector2D& other) const;

	//正規化ベクトル
	Vector2D normalized() const;

	//ゼロベクトルか判定
	bool isZero() const;

	//  =演算子のオーバーロード
	Vector2D& operator=(const Vector2D& v);
	//  +=演算子のオーバーロード
	Vector2D& operator+=(const Vector2D& v);
	//  -=演算子のオーバーロード
	Vector2D& operator-=(const Vector2D& v);

};

//  +演算子のオーバーロード
Vector2D operator+(const Vector2D&, const Vector2D&);
//  -演算子のオーバーロード
Vector2D operator+(const Vector2D&, const Vector2D&);
//  *演算子のオーバーロード
Vector2D operator*(const double, const Vector2D& v);