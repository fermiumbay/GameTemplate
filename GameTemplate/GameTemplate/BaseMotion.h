#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector2.h"

// ������^����N���X����
namespace Motion{
	// ���[�V�����N���X�̊��
	template <class ValueType>
	class BaseMotion{
		bool finished;	// ����I��
		BaseMotion(const BaseMotion&) {}
		BaseMotion& operator=(const BaseMotion&);
	protected:
		ValueType value;	// �l
		int time;	// �o�ߎ���
		void Finished(){
			finished = true;
		};	// �I������
	public:
		BaseMotion() : time(0), finished(false) {}
		virtual ~BaseMotion(){}
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
}
