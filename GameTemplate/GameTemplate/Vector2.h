#pragma once

// 2次元ベクトル
class Vector2{
public:
	int x, y;
	Vector2(int xi = 0, int yi = 0) : x(xi), y(yi) {}

	Vector2 operator+() const { return *this; }
	Vector2 operator-() const { return Vector2(-x, -y); }

	Vector2& operator+=(const Vector2& v){
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2& operator-=(const Vector2& v){
		x -= v.x;
		y -= v.y;
		return *this;
	}

	friend bool operator==(const Vector2& v1, const Vector2& v2){
		return v1.x == v2.x && v1.y == v2.y;
	}

	friend bool operator!=(const Vector2& v1, const Vector2& v2){
		return !(v1 == v2);
	}

	friend bool operator<(const Vector2& v1, const Vector2& v2){
		return v1.x < v2.x && v1.y < v2.y;
	}

	friend bool operator<=(const Vector2& v1, const Vector2& v2){
		return v1.x <= v2.x && v1.y <= v2.y;
	}
	
	friend bool operator>(const Vector2& v1, const Vector2& v2){
		return v1.x > v2.x && v1.y > v2.y;
	}

	friend bool operator>=(const Vector2& v1, const Vector2& v2){
		return v1.x >= v2.x && v1.y >= v2.y;
	}

	friend Vector2 operator+(const Vector2& v1, const Vector2& v2){
		return Vector2(v1.x + v2.x, v1.y + v2.y);
	}

	friend Vector2 operator+(int x, const Vector2& v){
		return Vector2(x + v.x, v.y);
	}

	friend Vector2 operator+(const Vector2& v, int y){
		return Vector2(v.x, y + v.y);
	}

	friend Vector2 operator-(const Vector2& v1, const Vector2& v2){
		return Vector2(v1.x - v2.x, v1.y - v2.y);
	}

	friend Vector2 operator-(int x, const Vector2& v){
		return Vector2(x - v.x, v.y);
	}

	friend Vector2 operator-(const Vector2& v, int y){
		return Vector2(v.x, y - v.y);
	}

	friend Vector2 operator*(int a, const Vector2& v){
		return Vector2(a * v.x, a * v.y);
	}

	friend Vector2 operator/(const Vector2& v, int a){
		return Vector2(v.x / a, v.y / a);
	}
};

// 2次元ベクトル（実数）
class Vector2d{
public:
	double x, y;
	Vector2d(double xi = 0, double yi = 0) : x(xi), y(yi) {}

	Vector2d operator+() const { return *this; }
	Vector2d operator-() const { return Vector2d(-x, -y); }

	Vector2d& operator+=(const Vector2d& v){
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2d& operator-=(const Vector2d& v){
		x -= v.x;
		y -= v.y;
		return *this;
	}

	friend bool operator==(const Vector2d& v1, const Vector2d& v2){
		return v1.x == v2.x && v1.y == v2.y;
	}

	friend bool operator!=(const Vector2d& v1, const Vector2d& v2){
		return !(v1 == v2);
	}

	friend Vector2d operator+(const Vector2d& v1, const Vector2d& v2){
		return Vector2d(v1.x + v2.x, v1.y + v2.y);
	}

	friend Vector2d operator+(double x, const Vector2d& v){
		return Vector2d(x + v.x, v.y);
	}

	friend Vector2d operator+(const Vector2d& v, double y){
		return Vector2d(v.x, y + v.y);
	}

	friend Vector2d operator-(const Vector2d& v1, const Vector2d& v2){
		return Vector2d(v1.x - v2.x, v1.y - v2.y);
	}

	friend Vector2d operator-(double x, const Vector2d& v){
		return Vector2d(x - v.x, v.y);
	}

	friend Vector2d operator-(const Vector2d& v, double y){
		return Vector2d(v.x, y - v.y);
	}

	friend Vector2d operator*(double a, const Vector2d& v){
		return Vector2d(a * v.x, a * v.y);
	}

	friend Vector2d operator/(const Vector2d& v, double a){
		return Vector2d(v.x / a, v.y / a);
	}
};
