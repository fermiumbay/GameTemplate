#pragma once

#include <string>

class Color;
class ColorHSV;

// 色
class Color {
public:

	// 各輝度の限界値
	static const int MaxValue = 255;

	// 色
	Color(int r = 0, int g = 0, int b = 0);

	// HSV色に変換
	ColorHSV ToHSV();

	// RGB値の文字列を取得
	std::string GetString();

	// 赤の輝度をセット
	void SetR(int r);

	// 緑の輝度をセット
	void SetG(int g);

	// 青の輝度をセット
	void SetB(int b);

	// 赤の輝度を取得
	int GetR();

	// 緑の輝度を取得
	int GetG();

	// 青の輝度を取得
	int GetB();

	// 色を持ってない
	bool HasNotColor();

	// 赤
	static const Color Red() { return Color(MaxValue, 0, 0); }

	// 緑
	static const Color Green() { return Color(0, MaxValue, 0); }

	// 青
	static const Color Blue() { return Color(0, 0, MaxValue); }

	// 黄色
	static const Color Yellow() { return Color(MaxValue, MaxValue, 0); }

	// 明るい紫
	static const Color Purple() { return Color(MaxValue, 0, MaxValue); }

	// 水色
	static const Color Cyan() { return Color(0, MaxValue, MaxValue); }

	// 白
	static const Color White() { return Color(MaxValue, MaxValue, MaxValue); }

	// 灰色
	static const Color Gray() { return Color((MaxValue + 1) / 2, (MaxValue + 1) / 2, (MaxValue + 1) / 2); }

	// 黒
	static const Color Black() { return Color(0, 0, 0); }

	// 色なし（引数省略など）
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

	// 各輝度
	int r, g, b;

	// 色なしフラグ
	bool noneFlg;

	// 正しい色の範囲に修正
	inline void RegularColor();

};

// 色（HSV）
class ColorHSV {
public:

	// 各HSVの限界値
	static const int MaxH = 239;
	static const int MaxS = 240;
	static const int MaxV = 240;

	// 色（HSV）
	ColorHSV(int h = 0, int s = 0, int v = 0);

	// RGB色に変換
	Color ToRGB();

	// HSV値の文字列を取得
	std::string GetString();

	// H値をセット
	void SetH(int h);

	// S値をセット
	void SetS(int s);

	// V値をセット
	void SetV(int v);
	
	// H値を取得
	int GetH();

	// S値を取得
	int GetS();

	// V値を取得
	int GetV();

	// 色を持ってない
	bool HasNotColor();

	// 色なし（引数省略など）
	static const ColorHSV None();

	friend bool operator==(const ColorHSV& v1, const ColorHSV& v2) {
		return v1.h == v2.h && v1.s == v2.s && v1.v == v2.v;
	}

	friend bool operator!=(const ColorHSV& v1, const ColorHSV& v2) {
		return !(v1 == v2);
	}

private:

	// 各HSV値
	int h, s, v;

	// 色なしフラグ
	bool noneFlg;

};
