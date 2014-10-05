#pragma once
#include "BaseMotion.h"

// ���[�V������ݒ肷��
namespace Motion{
	// �񎟋Ȑ�
	class Curve : public BaseMotion<double>{
		int finishTime;	// �I�����鎞��
		double a, p, q;	// �萔(a(x-p)^2+q)
	public:
		Curve(Vector2d vertexPos);
		void Update() override;
		bool PassedVertex();	// ���_�ʂ���
	};

	// �����U��
	class Wave : public BaseMotion<double>{
		int finishTime;	// �I�����鎞��
		bool neverfinishFlg;	// �I�����Ȃ��t���O
		double setValue;	// ��������l
		double a, b, c, d;	// �萔�iae^(-bt)sin(ct+d)�j
	public:
		Wave(double setValue, double a, double b, double c, double d);
		void Update() override;
	};
}
