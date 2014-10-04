#pragma once
#define _USE_MATH_DEFINES
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <functional>
#include <time.h>
#include <math.h>
#include "InfoData.h"
#include "Vector2.h"
#include "Color.h"
#include "Graphic.h"
#include "Sound.h"
#include "Font.h"
#include "KeyInput.h"
#include "Random.h"
#include "Motion.h"
using namespace std;

namespace common{
	// ウィンドウの中心座標を取得
	inline static Vector2d GetWindowCenter(){
		return InfoData::WindowSize().ToDouble() / 2;
	}
	inline static const double DegToRad(double degree){
		return degree * M_PI / 180.0;
	}

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
		for(int i=0; i<size_x; i++){
			(*var)[i] = new type[size_y];
		}
	}
	
	// 2次元配列の領域解放
	template <class type>
	static void delete2(type*** var, int size_x, int size_y = 0){
		for(int i=0; i<size_x; i++){
			delete[] (*var)[i];
		}
		delete[] *var;
	}

	// 連想配列で格納したオブジェクトの全消去
	template <class key, class value>
	static void deleteMap(map<key, value> *item){
		map<key, value>::iterator it = item->begin();
		while(it != item->end())
			delete (*item)[(it++)->first];
		item->clear();
	}

	// リストで格納したオブジェクトの全消去
	template <class type>
	static void deleteList(list<type> *item){
		list<type>::iterator it = item->begin();
		while(it != item->end()){
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
		if(systemTime - prevSystemTime == 0){
			fps = 0.0;
		}else{
			fps = static_cast<double>(CLOCKS_PER_SEC) / static_cast<double>(systemTime - prevSystemTime);
		}
		prevSystemTime = systemTime;
		return fps;
	}

	// startPosからgoalPosへ向かうための角度を求める
	static double Adir(Vector2 startPos, Vector2 goalPos){
		return atan2(
			static_cast<double>(startPos.y - goalPos.y),
			static_cast<double>(goalPos.x - startPos.x)
			);
	}
}
