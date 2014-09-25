#include "KeyInput.h"

bool KeyInput::CheckKeyState(bool cond, KeyState state, bool prevPushFlg){
	switch(state){
	case PushedNow:
		return cond && !prevPushFlg;
	case HasBePushed:
		return cond;
	case ReleaseNow:
		return !cond && prevPushFlg;
	case NeverPushed:
		return !cond;
	}
	return false;
}

bool KeyInput::GetKeyDown(KeyState state){
	static bool prevPushFlg = false;
	bool cond =
		(CheckHitKey(KEY_INPUT_DOWN)!=0)|
		((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_DOWN)!=0);

	bool ret = CheckKeyState(cond, state, prevPushFlg);
	prevPushFlg = cond;
	return ret;
}

bool KeyInput::GetKeyLeft(KeyState state){
	static bool prevPushFlg = false;
	bool cond =
		(CheckHitKey(KEY_INPUT_LEFT)!=0)|
		((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_LEFT)!=0);

	bool ret = CheckKeyState(cond, state, prevPushFlg);
	prevPushFlg = cond;
	return ret;
}

bool KeyInput::GetKeyRight(KeyState state){
	static bool prevPushFlg = false;
	bool cond =
		(CheckHitKey(KEY_INPUT_RIGHT)!=0)|
		((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_RIGHT)!=0);

	bool ret = CheckKeyState(cond, state, prevPushFlg);
	prevPushFlg = cond;
	return ret;
}

bool KeyInput::GetKeyUp(KeyState state){
	static bool prevPushFlg = false;
	bool cond =
		(CheckHitKey(KEY_INPUT_UP)!=0)|
		((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_UP)!=0);

	bool ret = CheckKeyState(cond, state, prevPushFlg);
	prevPushFlg = cond;
	return ret;
}

bool KeyInput::GetKeyOK(KeyState state){
	static bool prevPushFlg = false;
	bool cond =
		(CheckHitKey(KEY_INPUT_Z)!=0)|
		((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_1)!=0)|
		(CheckHitKey(KEY_INPUT_RETURN)!=0);

	bool ret = CheckKeyState(cond, state, prevPushFlg);
	prevPushFlg = cond;
	return ret;
}

bool KeyInput::GetKeyCancel(KeyState state){
	static bool prevPushFlg = false;
	bool cond =
		(CheckHitKey(KEY_INPUT_X)!=0)|
		((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_2)!=0)|
		(CheckHitKey(KEY_INPUT_ESCAPE)!=0)|
		((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_5)!=0);

	bool ret = CheckKeyState(cond, state, prevPushFlg);
	prevPushFlg = cond;
	return ret;
}

bool KeyInput::GetKeyShift(KeyState state){
	static bool prevPushFlg = false;
	bool cond =
		(CheckHitKey(KEY_INPUT_LSHIFT)!=0)|
		(CheckHitKey(KEY_INPUT_RSHIFT)!=0)|
		((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_3)!=0);

	bool ret = CheckKeyState(cond, state, prevPushFlg);
	prevPushFlg = cond;
	return ret;
}

bool KeyInput::GetKeyCtrl(KeyState state){
	static bool prevPushFlg = false;
	bool cond =
		(CheckHitKey(KEY_INPUT_LCONTROL)!=0)|
		(CheckHitKey(KEY_INPUT_RCONTROL)!=0)|
		((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_4)!=0);

	bool ret = CheckKeyState(cond, state, prevPushFlg);
	prevPushFlg = cond;
	return ret;
}
