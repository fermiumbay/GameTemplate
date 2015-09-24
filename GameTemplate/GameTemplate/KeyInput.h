#pragma once
#include "DxLib.h"
#include <map>
#include <functional>
using namespace std;

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
public:

	// �L�[���͂̏������i����������true�j
	static bool Initialize();

	// �L�[��Ԏ擾
	static bool GetKey(KeyType type, KeyState state);

	// �L�[�̔��������ݒ�
	static void SetKeyCond(KeyType type, function<bool()> cond);

	// �L�[�̔��������ʂ̃L�[�ɃR�s�[
	static void CopyKeyCond(KeyType copiedType, KeyType copyingType);

private:
	// �L�[���͂ɗp����L�[
	class Key {
	public:

		// �O�񉟂����t���O
		bool prevPushFlg;

		// �������
		function<bool()> cond;

		Key() {}
		Key(function<bool()> cond);
	};

	KeyInput() {}
	~KeyInput() {}

	// �L�[�����󋵂𒲂ׁA�����Ɉ�v���邩�ǂ������肷��
	static bool CheckKeyState(bool cond, KeyState state, bool prevPushFlg);

	// �L�[
	static map<KeyType, Key> key;
};
