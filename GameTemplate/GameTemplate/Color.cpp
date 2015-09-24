#include "Color.h"

Color::Color(int r, int g, int b) {
	SetR(r);
	SetG(g);
	SetB(b);
	this->noneFlg = false;
}

void Color::RegularColor() {
	if (this->r < 0) this->r = 0;
	if (this->g < 0) this->g = 0;
	if (this->b < 0) this->b = 0;
	if (this->r > MaxValue) this->r = MaxValue;
	if (this->g > MaxValue) this->g = MaxValue;
	if (this->b > MaxValue) this->b = MaxValue;
}

void Color::SetR(int r) {
	this->r = r;
	this->RegularColor();
}

void Color::SetG(int g) {
	this->g = g;
	this->RegularColor();
}

void Color::SetB(int b) {
	this->b = b;
	this->RegularColor();
}

int Color::GetR() {
	return r;
}

int Color::GetG() {
	return g;
}

int Color::GetB() {
	return b;
}

bool Color::HasNotColor() {
	return noneFlg;
}

const Color Color::None() {
	Color ret;
	ret.noneFlg = true;
	return ret;
}

ColorHSV::ColorHSV(int h, int s, int v) {
	SetH(h);
	SetS(s);
	SetV(v);
	this->noneFlg = false;
}

void ColorHSV::SetH(int h) {
	this->h = (h + (MaxH + 1)) % (MaxH + 1);
}

void ColorHSV::SetS(int s) {
	if (s < 0) s = 0;
	if (s > MaxS) s = MaxS;
	this->s = s;
}

void ColorHSV::SetV(int v) {
	if (v < 0) v = 0;
	if (v > MaxV) s = MaxV;
	this->v = v;
}

int ColorHSV::GetH() {
	return h;
}

int ColorHSV::GetS() {
	return s;
}

int ColorHSV::GetV() {
	return v;
}

bool ColorHSV::HasNotColor() {
	return noneFlg;
}

const ColorHSV ColorHSV::None() {
	ColorHSV ret;
	ret.noneFlg = true;
	return ret;
}

std::string Color::GetString() {
	return "(" + std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + ")";
}

std::string ColorHSV::GetString() {
	return "(" + std::to_string(h) + ", " + std::to_string(s) + ", " + std::to_string(v) + ")";
}

ColorHSV Color::ToHSV() {
	int h, s, v;

	const int DivH = (ColorHSV::MaxH + 1) / 6;
	int max, min;

	if (r >= g && r >= b) {
		max = r;
		min = (g <= b ? g : b);
		h = (int)(1.0 * DivH * (1.0 * (g - b) / (max - min)));
	}
	else if (g >= r && g >= b) {
		max = g;
		min = (r <= b ? r : b);
		h = (int)(1.0 * DivH * (1.0 * (b - r) / (max - min))) + 2 * DivH;
	}
	else if (b >= r && b >= g) {
		max = b;
		min = (r <= g ? r : g);
		h = (int)(1.0 * DivH * (1.0 * (r - g) / (max - min))) + 4 * DivH;
	}
	else {
		h = 0;
		max = min = r;
	}
	h = (h + (ColorHSV::MaxH + 1)) % (ColorHSV::MaxH + 1);

	s = (int)(1.0 * ColorHSV::MaxS * (max - min) / max);
	v = (int)(1.0 * ColorHSV::MaxV * max / MaxValue);

	return ColorHSV(h, s, v);
}

Color ColorHSV::ToRGB() {
	int r, g, b;

	const int DivH = (ColorHSV::MaxH + 1) / 6;

	int max = (int)(1.0 * Color::MaxValue * v / MaxV);
	int min = (int)(1.0 * max - (1.0 * s / MaxS * max));

	if (h < DivH) {
		r = max;
		g = (int)((1.0 * h / DivH) * (max - min) + min);
		b = min;
	}
	else if (h < 2 * DivH) {
		r = (int)((1.0 * (2 * DivH - h) / DivH) * (max - min) + min);
		g = max;
		b = min;
	}
	else if (h < 3 * DivH) {
		r = min;
		g = max;
		b = (int)((1.0 * (h - 2 * DivH) / DivH) * (max - min) + min);
	}
	else if (h < 4 * DivH) {
		r = min;
		g = (int)((1.0 * (4 * DivH - h) / DivH) * (max - min) + min);
		b = max;
	}
	else if (h < 5 * DivH) {
		r = (int)((1.0 * (h - 4 * DivH) / DivH) * (max - min) + min);
		g = min;
		b = max;
	}
	else{
		r = max;
		g = min;
		b = (int)((1.0 * (6 * DivH - h) / DivH) * (max - min) + min);
	}

	return Color(r, g, b);
}
