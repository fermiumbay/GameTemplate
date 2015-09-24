#pragma once

#include <string>

class Color;
class ColorHSV;

// �F
class Color {
public:

	// �e�P�x�̌��E�l
	static const int MaxValue = 255;

	// �F
	Color(int r = 0, int g = 0, int b = 0);

	// HSV�F�ɕϊ�
	ColorHSV ToHSV();

	// RGB�l�̕�������擾
	std::string GetString();

	// �Ԃ̋P�x���Z�b�g
	void SetR(int r);

	// �΂̋P�x���Z�b�g
	void SetG(int g);

	// �̋P�x���Z�b�g
	void SetB(int b);

	// �Ԃ̋P�x���擾
	int GetR();

	// �΂̋P�x���擾
	int GetG();

	// �̋P�x���擾
	int GetB();

	// �F�������ĂȂ�
	bool HasNotColor();

	// ��
	static const Color Red() { return Color(MaxValue, 0, 0); }

	// ��
	static const Color Green() { return Color(0, MaxValue, 0); }

	// ��
	static const Color Blue() { return Color(0, 0, MaxValue); }

	// ���F
	static const Color Yellow() { return Color(MaxValue, MaxValue, 0); }

	// ���邢��
	static const Color Purple() { return Color(MaxValue, 0, MaxValue); }

	// ���F
	static const Color Cyan() { return Color(0, MaxValue, MaxValue); }

	// ��
	static const Color White() { return Color(MaxValue, MaxValue, MaxValue); }

	// �D�F
	static const Color Gray() { return Color((MaxValue + 1) / 2, (MaxValue + 1) / 2, (MaxValue + 1) / 2); }

	// ��
	static const Color Black() { return Color(0, 0, 0); }

	// �F�Ȃ��i�����ȗ��Ȃǁj
	static const Color None();

	Color& operator+=(const Color& v) {
		r += v.r;
		g += v.g;
		b += v.b;
		RegularColor();
		return *this;
	}

	Color& operator-=(const Color& v) {
		r -= v.r;
		g -= v.g;
		b -= v.b;
		RegularColor();
		return *this;
	}

	Color& operator+=(int a) {
		r += a;
		g += a;
		b += a;
		RegularColor();
		return *this;
	}

	Color& operator-=(int a) {
		r -= a;
		g -= a;
		b -= a;
		RegularColor();
		return *this;
	}

	Color& operator*=(double a) {
		r = (int)(a * r);
		g = (int)(a * g);
		b = (int)(a * b);
		RegularColor();
		return *this;
	}

	Color& operator/=(double a) {
		r = (int)(1.0 * r / a);
		g = (int)(1.0 * g / a);
		b = (int)(1.0 * b / a);
		RegularColor();
		return *this;
	}

	friend bool operator==(const Color& v1, const Color& v2) {
		return v1.r == v2.r && v1.g == v2.g && v1.b == v2.b;
	}

	friend bool operator!=(const Color& v1, const Color& v2) {
		return !(v1 == v2);
	}

	friend Color operator+(const Color& v1, const Color& v2) {
		Color c = Color(v1.r + v2.r, v1.g + v2.g, v1.b + v2.b);
		c.RegularColor();
		return c;
	}

	friend Color operator+(int a, const Color& v) {
		Color c = Color(a + v.r, a + v.g, a + v.b);
		c.RegularColor();
		return c;
	}

	friend Color operator+(const Color& v, int a) {
		Color c = Color(v.r + a, v.g + a, v.b + a);
		c.RegularColor();
		return c;
	}

	friend Color operator-(const Color& v1, const Color& v2) {
		Color c = Color(v1.r - v2.r, v1.g - v2.g, v1.b - v2.b);
		c.RegularColor();
		return c;
	}

	friend Color operator-(int a, const Color& v) {
		Color c = Color(a - v.r, a - v.g, a - v.b);
		c.RegularColor();
		return c;
	}

	friend Color operator-(const Color& v, int a) {
		Color c = Color(v.r - a, v.g - a, v.b - a);
		c.RegularColor();
		return c;
	}

	friend Color operator*(double a, const Color& v) {
		Color c = Color((int)(a * v.r), (int)(a * v.g), (int)(a * v.b));
		c.RegularColor();
		return c;
	}

	friend Color operator*(const Color& v, double a) {
		return a * v;
	}

	friend Color operator/(const Color& v, double a) {
		Color c = Color((int)(1.0 * v.r / a), (int)(1.0 * v.g / a), (int)(1.0 * v.b / a));
		c.RegularColor();
		return c;
	}

	Color& operator++() {
		r += 1;
		g += 1;
		b += 1;
		RegularColor();
		return *this;
	}

	Color& operator--() {
		r -= 1;
		g -= 1;
		b -= 1;
		RegularColor();
		return *this;
	}

	Color operator++(int) {
		Color v = *this;
		this->r += 1;
		this->g += 1;
		this->b += 1;
		this->RegularColor();
		return v;
	}

	Color operator--(int) {
		Color v = *this;
		this->r -= 1;
		this->g -= 1;
		this->b -= 1;
		this->RegularColor();
		return v;
	}

private:

	// �e�P�x
	int r, g, b;

	// �F�Ȃ��t���O
	bool noneFlg;

	// �������F�͈̔͂ɏC��
	inline void RegularColor();

};

// �F�iHSV�j
class ColorHSV {
public:

	// �eHSV�̌��E�l
	static const int MaxH = 239;
	static const int MaxS = 240;
	static const int MaxV = 240;

	// �F�iHSV�j
	ColorHSV(int h = 0, int s = 0, int v = 0);

	// RGB�F�ɕϊ�
	Color ToRGB();

	// HSV�l�̕�������擾
	std::string GetString();

	// H�l���Z�b�g
	void SetH(int h);

	// S�l���Z�b�g
	void SetS(int s);

	// V�l���Z�b�g
	void SetV(int v);
	
	// H�l���擾
	int GetH();

	// S�l���擾
	int GetS();

	// V�l���擾
	int GetV();

	// �F�������ĂȂ�
	bool HasNotColor();

	// �F�Ȃ��i�����ȗ��Ȃǁj
	static const ColorHSV None();

	friend bool operator==(const ColorHSV& v1, const ColorHSV& v2) {
		return v1.h == v2.h && v1.s == v2.s && v1.v == v2.v;
	}

	friend bool operator!=(const ColorHSV& v1, const ColorHSV& v2) {
		return !(v1 == v2);
	}

private:

	// �eHSV�l
	int h, s, v;

	// �F�Ȃ��t���O
	bool noneFlg;

};
