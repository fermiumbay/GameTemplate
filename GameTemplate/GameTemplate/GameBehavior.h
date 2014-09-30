#pragma once
#include "CommonData.h"

// �Q�[���ɂ�����l�X�ȐU�镑�����s���I�u�W�F�N�g�̊��
class GameBehavior{
	virtual enum State{none};	// ��Ԃ̎��
	State state;	// ���݂̏��
	int stateTime;	// ���݂̏�ԂɂȂ��Ă���̌o�ߎ���
protected:
	map<string, Graphic*>	pic;	// �摜
	map<string, Sound*>	sound;	// ���y
	void DeletePic(string name);	// �摜�̍폜
	void DeleteSound(string name);	// ���y�̍폜
	inline State GetState();	// ��Ԃ̎擾
	inline int GetStateTime();	// ���݂̏�ԂɂȂ��Ă���̌o�ߎ��Ԏ擾
	// Git�ŕʃu�����`�؂��āA�ŏ��P�ʂ܂ŏȂ��Ă����̂��g�ł��낤

	// ��Ԃ̕ύX
	template<class NewState>
	void ChangeState(NewState state){
		this->state = static_cast<GameBehavior::State>(state);
	}

public:
	GameBehavior();
	virtual ~GameBehavior();
	virtual void Update();	// �X�V
	virtual void Draw();	// �`��
};
