#pragma once
#include "Vector2.h"
#include "includes.h"

// ������^����N���X����
namespace Motion{

	// ���[�V�����N���X�̊��
	template <class ValueType>
	class BaseMotion{
	public:

		// ���[�V�����N���X�̊��
		BaseMotion() : time(0), finished(false) {}

		// �f�X�g���N�^
		virtual ~BaseMotion(){}

		// ������
		void Initialize(){
			time = 0;
			finished = false;
		}

		// �X�V
		virtual void Update(){
			time++;
		}

		// �l�̎擾
		ValueType GetValue(){
			return value;
		}

		static ValueType GetValue() {
			return value;
		}

		// �I��������
		bool IsFinished(){
			return finished;
		}

	protected:

		// �l
		ValueType value;

		// �o�ߎ���
		int time;

		// �I������
		void Finished() {
			finished = true;
		};

	private:

		// ����I��
		bool finished;

		BaseMotion(const BaseMotion&) {}
		BaseMotion& operator=(const BaseMotion&) {}

	};

}
