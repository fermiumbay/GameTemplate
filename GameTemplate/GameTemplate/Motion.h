#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector2.h"

// ������^����N���X����
namespace Motion{

	// ���[�V�����N���X�̊��
	template <class ValueType>
	class MotionBase{
		bool finished;	// ����I��
		MotionBase(const MotionBase&) {}
		MotionBase& operator=(const MotionBase&);
	protected:
		ValueType value;	// �l
		int time;	// �o�ߎ���
		void Finished(){
			finished = true;
		};	// �I������
	public:
		MotionBase() : time(0), finished(false) {}
		virtual ~MotionBase(){}
		void Initialize(){
			time = 0;
			finished = false;
		}// ������
		virtual void Update(){
			time++;
		}	// �X�V
		ValueType GetValue(){
			return value;
		}	// �l�̎擾
		bool IsFinished(){
			return finished;
		}	// �I��������
	};

	// �񎟋Ȑ�
	class Curve : public MotionBase<double>{
		int finishTime;	// �I�����鎞��
		double a, p, q;	// �萔(a(x-p)^2+q)
	public:
		Curve(Vector2d vertexPos);
		void Update() override;
		bool PassedVertex();	// ���_�ʂ���
	};

	// �����U��
	class Wave : public MotionBase<double>{
		int finishTime;	// �I�����鎞��
		bool neverfinishFlg;	// �I�����Ȃ��t���O
		double setValue;	// ��������l
		double a, b, c, d;	// �萔�iae^(-bt)sin(ct+d)�j
	public:
		Wave(double setValue, double a, double b, double c, double d);
		void Update() override;
	};
}
