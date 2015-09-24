#include "Shape.h"

Point::Point(Vector2d p, Color color) : Shape(color) {
	this->p = p;
}

void Point::Draw() {
	DrawPixel((int)p.x, (int)p.y, GetColorValue());
}

Color Point::GetColor(Vector2 p) {
	return GetColorByValue(GetPixel(p.x, p.y));
}


Line::Line(Vector2d first, Vector2d last, Color color) : Shape(color) {
	this->first = first;
	this->last = last;
}

void Line::Draw() {
	DrawLine((int)first.x, (int)(first.y), (int)(last.x + 1), (int)(last.y + 1), GetColorValue());
}

Square::Square(Vector2d first, Vector2d last, Color color, bool fillFlg) : Shape(color) {
	this->first = first;
	this->last = last;
	this->fillFlg = fillFlg;
}

void Square::Draw() {
	DrawBox((int)first.x, (int)first.y, (int)(last.x + 1), (int)(last.y + 1), GetColorValue(), fillFlg);
}

Triangle::Triangle(Vector2d p1, Vector2d p2, Vector2d p3, Color color, bool fillFlg) : Shape(color) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->fillFlg = fillFlg;
}

void Triangle::Draw() {
	DrawTriangle((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y, (int)p3.x, (int)p3.y, GetColorValue(), fillFlg);
}

Circle::Circle(Vector2d first, Vector2d last, Color color, bool fillFlg) : Shape(color) {
	this->first = first;
	this->last = last;
	this->fillFlg = fillFlg;
}

Circle::Circle(Vector2d center, double radiusX, double radiusY, Color color, bool fillFlg) : Shape(color) {
	this->first = center - Vector2d(radiusX, radiusY);
	this->last = center + Vector2d(radiusX, radiusY);
	this->fillFlg = fillFlg;
}

Circle Circle::GetCircle(Vector2d center, double radius, Color color, bool fillFlg) {
	return Circle(center, radius, radius, color, fillFlg);
}

Vector2d Circle::GetCenterPos() {
	return (first + last) / 2.0;
}

double Circle::GetRadiusX() {
	return (last.x - first.x) / 2.0;
}

double Circle::GetRadiusY() {
	return (last.y - first.y) / 2.0;
}

void Circle::Draw() {
	Vector2 center = GetCenterPos().ToInt();
	DrawOval(center.x, center.y, (int)(GetRadiusX() + 0.5), (int)(GetRadiusY() + 0.5), GetColorValue(), fillFlg);
}


Shape::Shape(Color color) {
	this->color = color;
}

Shape::~Shape() {
}

unsigned int Shape::GetColorValue() {
	return GetColorValue(color);
}

unsigned int Shape::GetColorValue(Color color) {
	return GetColor(color.GetR(), color.GetG(), color.GetB());
}

Color Shape::GetColorByValue(unsigned int value) {
	int *r = 0, *g = 0, *b = 0;
	GetColor2(value, r, g, b);
	return Color(*r, *g, *b);
}
