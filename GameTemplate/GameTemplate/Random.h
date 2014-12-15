#pragma once
#include "DxLib.h"
#include <random>

// �����N���X
class Random{
	static std::mt19937 mt;	// �����Z���k�c�C�X�^
public:
	static const void DefaultRand();	// ����������
	static const void SetDefaultRand(int value);	// �����l���w�肵�ė���������
	static const void DefaultRand(int value);	// �����l���w�肵�ė����������iSetDefaultRand�Ɠ��`�j
	static const int Rand(int value);	// �����擾�i0�`value-1�j
	static const int Rand(int min, int max);	// �����擾�imin�`max�j
	static const double DRand(double min, double max);	// ���������擾�imin�`max�j
	static std::mt19937 GetMt();	// �����Z���k�c�C�X�^�̎擾
};
