#include "Vector2.h"

Vector2d Vector2::ToDouble(){
	return Vector2d(static_cast<double>(x), static_cast<double>(y));
}

Vector2 Vector2d::ToInt(){
	return Vector2(static_cast<int>(x), static_cast<int>(y));
}
