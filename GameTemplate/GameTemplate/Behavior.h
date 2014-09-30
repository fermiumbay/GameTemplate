#pragma once
#include "CommonData.h"

// �Q�[���ɂ�����l�X�ȐU�镑�����s���I�u�W�F�N�g�̊��
class Behavior{
	virtual enum State{none};	// ��Ԃ̎��
	State state;	// ���݂̏��
	int stateTime;	// ���݂̏�ԂɂȂ��Ă���̌o�ߎ���
protected:
	map<string, Graphic*>	pic;	// �摜
	map<string, Sound*>	sound;	// ���y
	void DeletePic(string name);	// �摜�̍폜
	void DeleteSound(string name);	// ���y�̍폜
	State GetState();	// ��Ԃ̎擾
	int GetStateTime();	// ���݂̏�ԂɂȂ��Ă���̌o�ߎ��Ԏ擾

	// ��Ԃ̕ύX
	template<class NewState>
	void ChangeState(NewState state){
		this->state = static_cast<Behavior::State>(state);
		stateTime = 0;
	}

public:
	Behavior();
	virtual ~Behavior();
	virtual void Update();	// �X�V
	virtual void Draw();	// �`��
};