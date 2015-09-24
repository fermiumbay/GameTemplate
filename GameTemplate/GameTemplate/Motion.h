#pragma once
#include "BaseMotion.h"

// ���[�V������ݒ肷��
namespace Motion{

	// �񎟋Ȑ�
	class Curve : public BaseMotion<double> {
	public:

		// �񎟋Ȑ�
		Curve(Vector2d vertexPos);

		// �X�V
		void Update() override;

		// ���_�ʂ���
		bool PassedVertex();

	private:

		// �I�����鎞��
		int finishTime;

		// �萔(a(x-p)^2+q)
		double a, p, q;

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
