#pragma once
#include "BaseMotion.h"

// ���[�V������ݒ肷��
namespace Motion{

	// �񎟋Ȑ�
	class Curve : public BaseMotion<double> {
	public:

		// �񎟋Ȑ�
		Curve() : BaseMotion<double>() {}

		// ������
		void Initialize(Vector2d vertexPos);

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
	class Wave : public BaseMotion<double> {
	public:

		// �����U��
		Wave() : BaseMotion<double>() {}

		// ������
		void Initialize(double setValue, double a, double b, double c, double d);

		// �X�V
		void Update() override;

	private:

		// �I�����鎞��
		int finishTime;

		// �I�����Ȃ��t���O
		bool neverfinishFlg;

		// ��������l
		double setValue;

		// �萔�iae^(-bt)sin(ct+d)�j
		double a, b, c, d;

	};

}
