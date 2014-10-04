#pragma once

// 色
class Color{
	int r, g, b;	// 各輝度
	bool noneFlg;	// 色なしフラグ
	inline void RegularColor();	// 正しい色の範囲に修正
public:
	Color(int ri = 0, int gi = 0, int bi = 0) : r(ri), g(gi), b(bi), noneFlg(false) {}

	void SetR(int r);
	void SetG(int g);
	void SetB(int b);
	int GetR();
	int GetG();
	int GetB();
	bool HasNotColor();	// 色を持ってない

	Color& operator+=(const Color& v){
		r += v.r;
		g += v.g;
		b += v.b;
		RegularColor();
		return *this;
	}

	Color& operator-=(const Color& v){
		r -= v.r;
		g -= v.g;
		b -= v.b;
		RegularColor();
		return *this;
	}

	Color& operator+=(int a){
		r += a;
		g += a;
		b += a;
		RegularColor();
		return *this;
	}

	Color& operator-=(int a){
		r -= a;
		g -= a;
		b -= a;
		RegularColor();
		return *this;
	}

	friend bool operator==(const Color& v1, const Color& v2){
		return v1.r == v2.r && v1.g == v2.g && v1.b == v2.b;
	}

	friend bool operator!=(const Color& v1, const Color& v2){
		return !(v1 == v2);
	}

	friend Color operator+(const Color& v1, const Color& v2){
		Color c = Color(v1.r + v2.r, v1.g + v2.g, v1.b + v2.b);
		c.RegularColor();
		return c;
	}

	friend Color operator+(int a, const Color& v){
		Color c = Color(a + v.r, a + v.g, a + v.b);
		c.RegularColor();
		return c;
	}

	friend Color operator+(const Color& v, int a){
		Color c = Color(v.r + a, v.g + a, v.b + a);
		c.RegularColor();
		return c;
	}

	friend Color operator-(const Color& v1, const Color& v2){
		Color c = Color(v1.r - v2.r, v1.g - v2.g, v1.b - v2.b);
		c.RegularColor();
		return c;
	}

	friend Color operator-(int a, const Color& v){
		Color c = Color(a - v.r, a - v.g, a - v.b);
		c.RegularColor();
		return c;
	}

	friend Color operator-(const Color& v, int a){
		Color c = Color(v.r - a, v.g - a, v.b - a);
		c.RegularColor();
		return c;
	}

	Color& operator++(){
		r += 1;
		g += 1;
		b += 1;
		RegularColor();
		return *this;
	}

	Color& operator--(){
		r -= 1;
		g -= 1;
		b -= 1;
		RegularColor();
		return *this;
	}

	Color operator++(int){
		Color v = *this;
		this->r += 1;
		this->g += 1;
		this->b += 1;
		this->RegularColor();
		return v;
	}

	Color operator--(int){
		Color v = *this;
		this->r -= 1;
		this->g -= 1;
		this->b -= 1;
		this->RegularColor();
		return v;
	}

	static const Color Red(){ return Color(255, 0, 0); }
	static const Color Green(){ return Color(0, 255, 0); }
	static const Color Blue(){ return Color(0, 0, 255); }
	static const Color Yellow(){ return Color(255, 255, 0); }
	static const Color Purple(){ return Color(255, 0, 255); }
	static const Color Cyan(){ return Color(0, 255, 255); }
	static const Color White(){ return Color(255, 255, 255); }
	static const Color Gray(){ return Color(128, 128, 128); }
	static const Color Black(){ return Color(0, 0, 0); }
	static const Color None();	// 色なし（引数省略など）
};
