#include "Motion.h"
using namespace Motion;

Curve::Curve(Vector2d vertexPos){
	p = vertexPos.x;
	q = vertexPos.y;
	if (p == 0){
		a = 0.0;
		finishTime = 0;
	}
	else{
		a = -q / (p*p);
		finishTime = static_cast<int>(2.0 * p);
	}
}

void Curve::Update(){
	BaseMotion<double>::Update();
	value = a * (time - p) * (time - p) + q;
	if (time >= finishTime){
		Finished();
	}
}

bool Curve::PassedVertex(){
	return time >= p;
}

Wave::Wave(double setValue, double a, double b, double c, double d){
	this->setValue = setValue;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	if (a == 0 || (c == 0 && d == 0)){
		finishTime = 0;
		neverfinishFlg = false;
	}
	else if (b == 0){
		neverfinishFlg = true;
	}
	else if (c == 0){
		finishTime = static_cast<int>(log(abs(a * sin(d))) / b);
		neverfinishFlg = false;
	}
	else{
		int n = static_cast<int>(1.0 / M_PI * (c / b * log(abs(a)) + d) + 1.0);
		finishTime = static_cast<int>((-d + M_PI * n) / c);
		neverfinishFlg = false;
	}
}

void Wave::Update(){
	BaseMotion<double>::Update();
	if (!neverfinishFlg && time > finishTime){
		value = setValue;
		Finished();
	}
	else{
		value = setValue + a * exp(-b * time) * sin(c * time + d);
	}
}
