#pragma once
#include "includes.h"
#include "DxLib.h"
#include "Vector2.h"
#include "Color.h"

// 図形クラス
class Shape{
public:
	
	// 色
	Color color;

	// 描画
	virtual void Draw() = 0;

protected:

	Shape(Color color);
	virtual ~Shape();

	// Colorをintに変換
	unsigned int GetColorValue();
	static unsigned int GetColorValue(Color color);

	// intをColorに変換
	static Color GetColorByValue(unsigned int value);

};

// 点
class Point : public Shape {
public:

	// 点生成
	Point(Vector2d p, Color color = Color::White());

	// 座標
	Vector2d p;

	// 描画
	void Draw();

	// 指定座標の点の色を取得
	static Color GetColor(Vector2 p);

};

// 線分
class Line : public Shape {
public:

	// 線分生成
	Line(Vector2d first, Vector2d last, Color color = Color::White());

	// 始点座標
	Vector2d first;

	// 終点座標
	Vector2d last;

	// 描画
	void Draw();

};

// 四角形
class Square : public Shape {
public:

	// 四角形生成
	Square(Vector2d first, Vector2d last, Color color = Color::White(), bool fillFlg = true);

	// 始点座標
	Vector2d first;

	// 終点座標
	Vector2d last;

	// 塗りつぶしフラグ
	bool fillFlg;

	// 描画
	void Draw();

};

// 三角形
class Triangle : public Shape {
public:

	// 三角形生成
	Triangle(Vector2d p1, Vector2d p2, Vector2d p3, Color color = Color::White(), bool fillFlg = true);

	// 各頂点座標
	Vector2d p1, p2, p3;

	// 塗りつぶしフラグ
	bool fillFlg;

	// 描画
	void Draw();

};

// 楕円
class Circle : public Shape {
public:

	// 端座標から楕円生成
	Circle(Vector2d first, Vector2d last, Color color = Color::White(), bool fillFlg = true);

	// 中心座標と半径から楕円生成
	Circle(Vector2d center, double radiusX, double radiusY, Color color = Color::White(), bool fillFlg = true);

	// 中心座標と半径から円取得
	static Circle GetCircle(Vector2d center, double radius, Color color = Color::White(), bool fillFlg = true);

	// 始点座標
	Vector2d first;
	
	// 終点座標
	Vector2d last;

	// 中心座標取得
	Vector2d GetCenterPos();

	// 半径X取得
	double GetRadiusX();

	// 半径Y取得
	double GetRadiusY();

	// 塗りつぶしフラグ
	bool fillFlg;

	// 描画
	void Draw();

};
