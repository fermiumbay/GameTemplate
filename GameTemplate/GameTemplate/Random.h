#pragma once
#include "DxLib.h"
#include "includes.h"

// �����N���X
class Random{
public:

	// ����������
	static const void DefaultRand();

	// �����l���w�肵�ė���������
	static const void SetDefaultRand(int value);

	// �����l���w�肵�ė����������iSetDefaultRand�Ɠ��`�j
	static const void DefaultRand(int value);

	// �����擾�i0�`value-1�j
	static const int Rand(int value);

	// �����擾�imin�`max�j
	static const int Rand(int min, int max);

	// ���������擾�imin�`max�j
	static const double DRand(double min, double max);

	// �����Z���k�c�C�X�^�̎擾
	static std::mt19937 GetMt();

private:

	static std::mt19937 mt;	// �����Z���k�c�C�X�^

};
