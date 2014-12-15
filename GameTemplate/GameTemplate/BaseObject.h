#pragma once
#include "CommonData.h"

// �Q�[���ɂ�����l�X�ȐU�镑�����s���I�u�W�F�N�g�̊��
class BaseObject{
	virtual enum State{ none };	// ��Ԃ̎��
	State state;	// ���݂̏��
	int stateTime;	// ���݂̏�ԂɂȂ��Ă���̌o�ߎ���
	vector<future<void>*> futureVector;	// ����ǂݍ��ݗp�t���[�`���[�z��
protected:
	map<string, Graphic*> pic;	// �摜
	map<string, vector<Graphic*>> picDiv;	// �����摜
	map<string, GraphicHandle> picHandle;	// �摜�n���h��
	map<string, Sound*> sound;	// ���y
	map<string, Font*> font;	// �t�H���g
	void DeletePic(string name);	// �摜�̍폜
	void DeletePicDiv(string name);	// �����摜�̍폜
	void DeletePicHandle(string name);	// �摜�n���h���̍폜
	void DeleteSound(string name);	// ���y�̍폜
	void DeleteFont(string name);	// �t�H���g�̍폜
	State GetState();	// ��Ԃ̎擾
	int GetStateTime();	// ���݂̏�ԂɂȂ��Ă���̌o�ߎ��Ԏ擾
	void AddThread(function<void()> thread);	// ���񏈗��X���b�h�̒ǉ�
	int GetThreadTotalNum();	// �ǉ�����Ă���X���b�h����
	int GetFinishedThreadNum();	// �ǉ�����Ă���X���b�h�̂����I�������X���b�h��
	bool AllThreadFinished();	// �ǉ�����Ă���S�X���b�h���I������
	void WaitForThread();	// �S�X���b�h�I���҂�
	void ClearThread();	// �S�X���b�h����

	// ��Ԃ̕ύX
	template<class NewState>
	void ChangeState(NewState state){
		this->state = static_cast<BaseObject::State>(state);
		stateTime = 0;
	}

public:
	BaseObject();
	virtual ~BaseObject();
	virtual void Update();	// �X�V
	virtual void Draw();	// �`��
};
