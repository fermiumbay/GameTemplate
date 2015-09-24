#pragma once
#include "includes.h"
#include "DxLib.h"
#include "Vector2.h"
#include "Color.h"

// �}�`�N���X
class Shape{
public:
	
	// �F
	Color color;

	// �`��
	virtual void Draw() = 0;

protected:

	Shape(Color color);
	virtual ~Shape();

	// Color��int�ɕϊ�
	unsigned int GetColorValue();
	static unsigned int GetColorValue(Color color);

	// int��Color�ɕϊ�
	static Color GetColorByValue(unsigned int value);

};

// �_
class Point : public Shape {
public:

	// �_����
	Point(Vector2d p, Color color = Color::White());

	// ���W
	Vector2d p;

	// �`��
	void Draw();

	// �w����W�̓_�̐F���擾
	static Color GetColor(Vector2 p);

};

// ����
class Line : public Shape {
public:

	// ��������
	Line(Vector2d first, Vector2d last, Color color = Color::White());

	// �n�_���W
	Vector2d first;

	// �I�_���W
	Vector2d last;

	// �`��
	void Draw();

};

// �l�p�`
class Square : public Shape {
public:

	// �l�p�`����
	Square(Vector2d first, Vector2d last, Color color = Color::White(), bool fillFlg = true);

	// �n�_���W
	Vector2d first;

	// �I�_���W
	Vector2d last;

	// �h��Ԃ��t���O
	bool fillFlg;

	// �`��
	void Draw();

};

// �O�p�`
class Triangle : public Shape {
public:

	// �O�p�`����
	Triangle(Vector2d p1, Vector2d p2, Vector2d p3, Color color = Color::White(), bool fillFlg = true);

	// �e���_���W
	Vector2d p1, p2, p3;

	// �h��Ԃ��t���O
	bool fillFlg;

	// �`��
	void Draw();

};

// �ȉ~
class Circle : public Shape {
public:

	// �[���W����ȉ~����
	Circle(Vector2d first, Vector2d last, Color color = Color::White(), bool fillFlg = true);

	// ���S���W�Ɣ��a����ȉ~����
	Circle(Vector2d center, double radiusX, double radiusY, Color color = Color::White(), bool fillFlg = true);

	// ���S���W�Ɣ��a����~�擾
	static Circle GetCircle(Vector2d center, double radius, Color color = Color::White(), bool fillFlg = true);

	// �n�_���W
	Vector2d first;
	
	// �I�_���W
	Vector2d last;

	// ���S���W�擾
	Vector2d GetCenterPos();

	// ���aX�擾
	double GetRadiusX();

	// ���aY�擾
	double GetRadiusY();

	// �h��Ԃ��t���O
	bool fillFlg;

	// �`��
	void Draw();

};
