#pragma once
#include "DxLib.h"
#include "common.h"

// �L�[���͂̏��
enum KeyState{
	PushedNow,	// �������u��
	HasBePushed,	// �����Ă�����
	ReleaseNow,	// �������u��
	NeverPushed,	// �����Ă�����
};

// �L�[�̎��
enum KeyType{
	Down,	// ��
	Left,	// ��
	Right,	// ��
	Up,	// ��
	OK,	// ����L�[
	Cancel,	// �L�����Z���L�[
	Shift,	// �V�t�g�L�[
	Ctrl,	// �R���g���[���L�[
};

// �L�[����
class KeyInput{

	// �L�[���͂ɗp����L�[
	class Key{
	public:
		bool prevPushFlg;	// �O�񉟂����t���O
		function<bool()> cond;	// �������
		Key(){}
		Key(function<bool()> cond);
	};

	KeyInput(){}
	~KeyInput(){}
	static bool CheckKeyState(bool cond, KeyState state, bool prevPushFlg);	// �L�[�����󋵂𒲂ׁA�����Ɉ�v���邩�ǂ������肷��
	static map<KeyType, Key> key;	// �L�[
public:
	static bool Initialize();	// �L�[���͂̏������i����������true�j
	static bool GetKey(KeyType type, KeyState state);	// �L�[��Ԏ擾
	static void SetKeyCond(KeyType type, function<bool()> cond);	// �L�[�̔��������ݒ�
};