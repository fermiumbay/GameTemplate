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

// ���ʖ��O���
namespace common{

	// �E�B���h�E�̒��S���W���擾
	inline static Vector2d GetWindowCenter(){
		return InfoData::WindowSize().ToDouble() / 2;
	}

	// �x�����W�A����
	inline static const double DegToRad(double degree){
		return degree * M_PI / 180.0;
	}

	// ���W�A����x��
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
		for (int i = 0; i<size_x; i++){
			(*var)[i] = new type[size_y];
		}
	}

	// 2�����z��̗̈���
	template <class type>
	static void delete2(type*** var, int size_x, int size_y = 0){
		for (int i = 0; i<size_x; i++){
			delete[](*var)[i];
		}
		delete[] * var;
	}

	// �A�z�z��Ŋi�[�����I�u�W�F�N�g�̑S����
	template <class key, class value>
	static void deleteMap(map<key, value> *item){
		map<key, value>::iterator it = item->begin();
		while (it != item->end())
			delete (*item)[(it++)->first];
		item->clear();
	}

	// ���X�g�Ŋi�[�����I�u�W�F�N�g�̑S����
	template <class type>
	static void deleteList(list<type> *item){
		list<type>::iterator it = item->begin();
		while (it != item->end()){
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
		if (systemTime - prevSystemTime == 0){
			fps = 0.0;
		}
		else{
			fps = static_cast<double>(CLOCKS_PER_SEC) / static_cast<double>(systemTime - prevSystemTime);
		}
		prevSystemTime = systemTime;
		return fps;
	}

	// startPos����goalPos�֌��������߂̊p�x�����߂�i���W�A���j
	static double Adir(Vector2 startPos, Vector2 goalPos) {
		return atan2(
			static_cast<double>(startPos.y - goalPos.y),
			static_cast<double>(goalPos.x - startPos.x)
			);
	}

	// startPos����goalPos�֌��������߂̊p�x�����߂�i�x�j
	static double AdirDeg(Vector2 startPos, Vector2 goalPos) {
		return RadToDeg(Adir(startPos, goalPos));
	}

	// �E��������������i���l�ƁA�w�茅���A0�l�߂��邩�̃t���O���w��j
	static string RightNumber(long long int number, int limit, bool zeroFlg = false) {
		string ret = "";
		string numstr = to_string(number);
		for (int i = 0; i < limit - (int)numstr.size(); i++) {
			ret += (zeroFlg ? "0" : " ");
		}
		return ret + numstr;
	}

	// �E��������������i���l�ƁA�w�茅���A0�l�߂��邩�̃t���O���w��j
	static string RightNumber(int number, int limit, bool zeroFlg = false) {
		return RightNumber(static_cast<long long int>(number), limit, zeroFlg);
	}

	// �����ړ�
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

	// �T�C���ړ��i���炩�ɂӂ���Ɠ����j
	template<class Type>
	Type SinMoving(int t, int tmax, Type startvalue, Type endvalue) {
		Type ret;

		// ������m sin^2 (��t�^(������))��t�Őϕ����ċ����ɂ����֐��i�܂�Ȃ������Ďn�[�ƏI�[�Œx�����񂶂łӂ���Ɠ����j
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
