#pragma once
#include "includes.h"

#include "InfoData.h"
#include "Vector2.h"
#include "Color.h"
#include "Shape.h"

#include "Graphic.h"
#include "Sound.h"
#include "Font.h"
#include "Screen.h"

#include "KeyInput.h"
#include "Random.h"
#include "Motion.h"

// 共通名前空間
namespace common{

	// ウィンドウの中心座標を取得
	inline static Vector2d GetWindowCenter(){
		return InfoData::WindowSize().ToDouble() / 2;
	}

	// 度をラジアンに
	inline static const double DegToRad(double degree){
		return degree * M_PI / 180.0;
	}

	// ラジアンを度に
	inline static const double RadToDeg(double radian){
		return radian * 180.0 / M_PI;
	}

	// TypeA→TypeBのstringstream変換
	template <class TypeA, class TypeB>
	static TypeB convert(TypeA obj){
		stringstream ss;
		TypeB ret;
		ss << obj;
		ss >> ret;
		return ret;
	}

	// 2次元配列の領域確保
	template <class type>
	static void new2(type*** var, int size_x, int size_y){
		*var = new type*[size_x];
		for (int i = 0; i<size_x; i++){
			(*var)[i] = new type[size_y];
		}
	}

	// 2次元配列の領域解放
	template <class type>
	static void delete2(type*** var, int size_x, int size_y = 0){
		for (int i = 0; i<size_x; i++){
			delete[](*var)[i];
		}
		delete[] * var;
	}

	// 連想配列で格納したオブジェクトの全消去
	template <class key, class value>
	static void deleteMap(map<key, value> *item){
		map<key, value>::iterator it = item->begin();
		while (it != item->end())
			delete (*item)[(it++)->first];
		item->clear();
	}

	// リストで格納したオブジェクトの全消去
	template <class type>
	static void deleteList(list<type> *item){
		list<type>::iterator it = item->begin();
		while (it != item->end()){
			delete *it;
			it++;
		}
		item->clear();
	}

	// 1フレーム分のFPS測定
	static double GetFps(int gameTime){
		static clock_t prevSystemTime = clock();	// 前回起動後経過時間
		clock_t systemTime;	// 起動後経過時間
		double fps;

		systemTime = clock();
		if (systemTime - prevSystemTime == 0){
			fps = 0.0;
		}
		else{
			fps = static_cast<double>(CLOCKS_PER_SEC) / static_cast<double>(systemTime - prevSystemTime);
		}
		prevSystemTime = systemTime;
		return fps;
	}

	// startPosからgoalPosへ向かうための角度を求める（ラジアン）
	static double Adir(Vector2 startPos, Vector2 goalPos) {
		return atan2(
			static_cast<double>(startPos.y - goalPos.y),
			static_cast<double>(goalPos.x - startPos.x)
			);
	}

	// startPosからgoalPosへ向かうための角度を求める（度）
	static double AdirDeg(Vector2 startPos, Vector2 goalPos) {
		return RadToDeg(Adir(startPos, goalPos));
	}

	// 右揃え数字文字列（数値と、指定桁数、0詰めするかのフラグを指定）
	static string RightNumber(long long int number, int limit, bool zeroFlg = false) {
		string ret = "";
		string numstr = to_string(number);
		for (int i = 0; i < limit - (int)numstr.size(); i++) {
			ret += (zeroFlg ? "0" : " ");
		}
		return ret + numstr;
	}

	// 右揃え数字文字列（数値と、指定桁数、0詰めするかのフラグを指定）
	static string RightNumber(int number, int limit, bool zeroFlg = false) {
		return RightNumber(static_cast<long long int>(number), limit, zeroFlg);
	}

	// 直線移動
	template<class Type>
	Type StraightMoving(int t, int tmax, Type startvalue, Type endvalue) {
		Type ret;

		if (t >= tmax) {
			ret = endvalue;
		}
		else if (t < 0) {
			ret = startvalue;
		}
		else {
			ret = startvalue + (endvalue - startvalue) * t / tmax;
		}

		return ret;
	}

	// サイン移動（滑らかにふわっと動く）
	template<class Type>
	Type SinMoving(int t, int tmax, Type startvalue, Type endvalue) {
		Type ret;

		// 速さ＝m sin^2 (πt／(総時間))をtで積分して距離にした関数（まんなか速くて始端と終端で遅いかんじでふわっと動く）
		if (t >= tmax) {
			ret = endvalue;
		}
		else if (t < 0) {
			ret = startvalue;
		}
		else {
			Type m = 2.0 * (endvalue - startvalue) / tmax;
			ret = startvalue + (t - tmax / (2.0 * M_PI) * sin(2.0 * M_PI * t / tmax)) * m / 2.0;
		}

		return ret;
	}
}
