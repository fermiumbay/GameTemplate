#include "Color.h"

void Color::RegularColor(){
	if (this->r < 0) this->r = 0;
	if (this->g < 0) this->g = 0;
	if (this->b < 0) this->b = 0;
	if (this->r > 255) this->r = 255;
	if (this->g > 255) this->g = 255;
	if (this->b > 255) this->b = 255;
}

void Color::SetR(int r){
	this->r = r;
	this->RegularColor();
}

void Color::SetG(int g){
	this->g = g;
	this->RegularColor();
}

void Color::SetB(int b){
	this->b = b;
	this->RegularColor();
}

int Color::GetR(){
	return r;
}

int Color::GetG(){
	return g;
}

int Color::GetB(){
	return b;
}

bool Color::HasNotColor(){
	return noneFlg;
}

const Color Color::None(){
	Color ret;
	ret.noneFlg = true;
	return ret;
}
