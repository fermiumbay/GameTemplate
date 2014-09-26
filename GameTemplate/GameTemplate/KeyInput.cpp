#include "KeyInput.h"

map<KeyType, KeyInput::Key> KeyInput::key;

bool KeyInput::Initialize(){
	key.clear();

	// ↓
	key[Down] = Key([]{
		bool ret =
			(CheckHitKey(KEY_INPUT_DOWN) != 0) |
			((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_DOWN) != 0);
		return ret;
	});

	// ←
	key[Left] = Key([]{
		bool ret =
			(CheckHitKey(KEY_INPUT_LEFT) != 0) |
			((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_LEFT) != 0);
		return ret;
	});

	// →
	key[Right] = Key([]{
		bool ret =
			(CheckHitKey(KEY_INPUT_RIGHT) != 0) |
			((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_RIGHT) != 0);
		return ret;
	});

	// ↑
	key[Up] = Key([]{
		bool ret =
			(CheckHitKey(KEY_INPUT_UP) != 0) |
			((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_UP) != 0);
		return ret;
	});

	// 決定キー
	key[OK] = Key([]{
		bool ret =
			(CheckHitKey(KEY_INPUT_Z) != 0) |
			((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_1) != 0) |
			(CheckHitKey(KEY_INPUT_RETURN) != 0);
		return ret;
	});

	// キャンセルキー
	key[Cancel] = Key([]{
		bool ret =
			(CheckHitKey(KEY_INPUT_X) != 0) |
			((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_2) != 0) |
			(CheckHitKey(KEY_INPUT_ESCAPE) != 0) |
			((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_5) != 0);
		return ret;
	});

	// シフトキー
	key[Shift] = Key([]{
		bool ret =
			(CheckHitKey(KEY_INPUT_LSHIFT) != 0) |
			(CheckHitKey(KEY_INPUT_RSHIFT) != 0) |
			((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_3) != 0);
		return ret;
	});

	// コントロールキー
	key[Ctrl] = Key([]{
		bool ret =
			(CheckHitKey(KEY_INPUT_LCONTROL) != 0) |
			(CheckHitKey(KEY_INPUT_RCONTROL) != 0) |
			((GetJoypadInputState(DX_INPUT_PAD1)&PAD_INPUT_4) != 0);
		return ret;
	});

	return true;
}

KeyInput::Key::Key(function<bool()> cond){
	prevPushFlg = false;
	this->cond = cond;
}

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

bool KeyInput::GetKey(KeyType type, KeyState state){
	bool cond = key[type].cond();
	bool ret = CheckKeyState(cond, state, key[type].prevPushFlg);
	key[type].prevPushFlg = cond;
	return ret;
}

void KeyInput::SetKeyCond(KeyType type, function<bool()> cond){
	key[type].cond = cond;
}