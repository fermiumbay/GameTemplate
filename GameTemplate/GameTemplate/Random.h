#pragma once
#include "DxLib.h"
#include <time.h>

// �����N���X
class Random{
public:

	// ����������
	inline static const void DefaultRand(){
		SRand((int)time(NULL));
	}

	// �����̏����l�ݒ�
	inline static const void SetDefaultRand(int value){
		SRand(value);
	}

	// �����擾�i0�`value-1�j
	inline static const int Rand(int value){
		return GetRand(value - 1);
	}

};
