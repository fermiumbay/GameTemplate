#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector2.h"

// ������^����N���X����
namespace Motion{

	// ���[�V�����N���X�̊��
	class MotionBase{
		bool finished;	// ����I��
		MotionBase(const MotionBase&) {}
		MotionBase& operator=(const MotionBase&);
	protected:
		double value;	// �l
		int time;	// �o�ߎ���
		void Finished();	// �I������
	public:
		MotionBase();
		virtual ~MotionBase(){}
		void Initialize();	// ������
		virtual void Update();	// �X�V
		double GetValue();	// �l�̎擾
		bool IsFinished();	// �I��������
	};

	// �񎟋Ȑ�
	class Curve : public MotionBase{
		int finishTime;	// �I�����鎞��
		double a, p, q;	// �萔(a(x-p)^2+q)
	public:
		Curve(Vector2d vertexPos);
		void Update() override;
		bool PassedVertex();	// ���_�ʂ���
	};

	// �����U��
	class Wave : public MotionBase {
		int finishTime;	// �I�����鎞��
		bool neverfinishFlg;	// �I�����Ȃ��t���O
		double setValue;	// ��������l
		double a, b, c, d;	// �萔�iae^(-bt)sin(ct+d)�j
	public:
		Wave(double setValue, double a, double b, double c, double d);
		void Update() override;
	};
}
