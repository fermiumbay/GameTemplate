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
	// �E�B���h�E�̒��S���W���擾
	inline static Vector2d GetWindowCenter(){
		return InfoData::WindowSize().ToDouble() / 2;
	}
	inline static const double DegToRad(double degree){
		return degree * M_PI / 180.0;
	}

	inline static const double RadToDeg(double radian){
		return radian * 180.0 / M_PI;
	}

	// TypeA��TypeB��stringstream�ϊ�
	template <class TypeA, class TypeB>
	static TypeB convert(TypeA obj){
		stringstream ss;
		TypeB ret;
		ss << obj;
		ss >> ret;
		return ret;
	}

	// 2�����z��̗̈�m��
	template <class type>
	static void new2(type*** var, int size_x, int size_y){
		*var = new type*[size_x];
		for(int i=0; i<size_x; i++){
			(*var)[i] = new type[size_y];
		}
	}
	
	// 2�����z��̗̈���
	template <class type>
	static void delete2(type*** var, int size_x, int size_y = 0){
		for(int i=0; i<size_x; i++){
			delete[] (*var)[i];
		}
		delete[] *var;
	}

	// �A�z�z��Ŋi�[�����I�u�W�F�N�g�̑S����
	template <class key, class value>
	static void deleteMap(map<key, value> *item){
		map<key, value>::iterator it = item->begin();
		while(it != item->end())
			delete (*item)[(it++)->first];
		item->clear();
	}

	// ���X�g�Ŋi�[�����I�u�W�F�N�g�̑S����
	template <class type>
	static void deleteList(list<type> *item){
		list<type>::iterator it = item->begin();
		while(it != item->end()){
			delete *it;
			it++;
		}
		item->clear();
	}

	// 1�t���[������FPS����
	static double GetFps(int gameTime){
		static clock_t prevSystemTime = clock();	// �O��N����o�ߎ���
		clock_t systemTime;	// �N����o�ߎ���
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

	// startPos����goalPos�֌��������߂̊p�x�����߂�
	static double Adir(Vector2 startPos, Vector2 goalPos){
		return atan2(
			static_cast<double>(startPos.y - goalPos.y),
			static_cast<double>(goalPos.x - startPos.x)
			);
	}
}
