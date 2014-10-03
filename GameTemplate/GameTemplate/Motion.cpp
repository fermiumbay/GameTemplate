#include "Motion.h"

Motion::MotionBase::MotionBase()
	: time(0), finished(false), value(0.0) {
}

void Motion::MotionBase::Update(){
	time++;
}

double Motion::MotionBase::GetValue(){
	return value;
}

void Motion::MotionBase::Finished(){
	finished = true;
}

bool Motion::MotionBase::IsFinished(){
	return finished;
}

void Motion::MotionBase::Initialize(){
	time = 0;
	finished = false;
}

Motion::Curve::Curve(Vector2d vertexPos){
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

void Motion::Curve::Update(){
	Motion::MotionBase::Update();
	value = a * (time - p) * (time - p) + q;
	if (time >= finishTime){
		Finished();
	}
}

bool Motion::Curve::PassedVertex(){
	return time >= p;
}

Motion::Wave::Wave(double setValue, double a, double b, double c, double d){
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

void Motion::Wave::Update(){
	Motion::MotionBase::Update();
	if (!neverfinishFlg && time > finishTime){
		value = setValue;
		Finished();
	}
	else{
		value = setValue + a * exp(-b * time) * sin(c * time + d);
	}
}
