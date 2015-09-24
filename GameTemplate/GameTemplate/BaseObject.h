#pragma once
#include "CommonData.h"

// �Q�[���ɂ�����l�X�ȐU�镑�����s���I�u�W�F�N�g�̊��
class BaseObject{

	// ��Ԃ̎��
	enum State { none };

public:

	// �R���X�g���N�^
	BaseObject();

	// �f�X�g���N�^
	virtual ~BaseObject();

	// �X�V
	virtual void Update();

	// �`��
	virtual void Draw();

protected:

	// �摜
	map<string, Graphic*> pic;

	// �����摜
	map<string, vector<Graphic*>> picDiv;

	// �摜�n���h��
	map<string, GraphicHandle> picHandle;

	// ���y
	map<string, Sound*> sound;

	// �t�H���g
	map<string, Font*> font;

	// �X�N���[��
	map<string, Screen*> screen;

	// �摜�̍폜
	void DeletePic(string name);

	// �����摜�̍폜
	void DeletePicDiv(string name);

	// �摜�n���h���̍폜
	void DeletePicHandle(string name);

	// ���y�̍폜
	void DeleteSound(string name);

	// �t�H���g�̍폜
	void DeleteFont(string name);

	// �X�N���[���̍폜
	void DeleteScreen(string name);

	// ��Ԃ̎擾
	State GetState();

	// ���݂̏�ԂɂȂ��Ă���̌o�ߎ��Ԏ擾
	int GetStateTime();

	// ���񏈗��X���b�h�̒ǉ�
	void AddThread(function<void()> thread);

	// �ǉ�����Ă���X���b�h����
	int GetThreadTotalNum();

	// �ǉ�����Ă���X���b�h�̂����I�������X���b�h��
	int GetFinishedThreadNum();

	// �ǉ�����Ă���S�X���b�h���I������
	bool AllThreadFinished();

	// �S�X���b�h����
	void ClearThread();

	// ��Ԃ̕ύX
	template<class NewState>
	void ChangeState(NewState state){
		this->state = static_cast<BaseObject::State>(state);
		stateTime = 0;
	}

private:

	// ���݂̏��
	State state;

	// ���݂̏�ԂɂȂ��Ă���̌o�ߎ���
	int stateTime;

	// ����ǂݍ��ݗp�X���b�h�z��
	vector<thread*> threadVector;	
};
