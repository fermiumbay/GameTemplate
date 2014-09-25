#pragma once
#include "DxLib.h"
#include "common.h"

// �L�[���͂̏��
enum KeyState{
	PushedNow,	// �������u��
	HasBePushed,	// �����Ă�����
	ReleaseNow,	// �������u��
	NeverPushed	// �����Ă�����
};

// �L�[����
class KeyInput{
	KeyInput(){}
	~KeyInput(){}
	static bool CheckKeyState(bool cond, KeyState state, bool prevPushFlg);	// �L�[�����󋵂𒲂ׁA�����Ɉ�v���邩�ǂ������肷��
public:
	static bool GetKeyDown(KeyState state);	// ��
	static bool GetKeyLeft(KeyState state);	// ��
	static bool GetKeyRight(KeyState state);	// ��
	static bool GetKeyUp(KeyState state);	// ��
	static bool GetKeyOK(KeyState state);	// ����L�[
	static bool GetKeyCancel(KeyState state);	// �L�����Z���L�[
	static bool GetKeyShift(KeyState state);	// �V�t�g�L�[
	static bool GetKeyCtrl(KeyState state);	// �R���g���[���L�[
};