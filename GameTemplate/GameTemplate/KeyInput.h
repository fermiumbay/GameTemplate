#pragma once
#include "DxLib.h"
#include "common.h"

// キー入力の状態
enum KeyState{
	PushedNow,	// 押した瞬間
	HasBePushed,	// 押している状態
	ReleaseNow,	// 離した瞬間
	NeverPushed	// 離している状態
};

// キー入力
class KeyInput{
	KeyInput(){}
	~KeyInput(){}
	static bool CheckKeyState(bool cond, KeyState state, bool prevPushFlg);	// キー押下状況を調べ、条件に一致するかどうか判定する
public:
	static bool GetKeyDown(KeyState state);	// ↓
	static bool GetKeyLeft(KeyState state);	// ←
	static bool GetKeyRight(KeyState state);	// →
	static bool GetKeyUp(KeyState state);	// ↑
	static bool GetKeyOK(KeyState state);	// 決定キー
	static bool GetKeyCancel(KeyState state);	// キャンセルキー
	static bool GetKeyShift(KeyState state);	// シフトキー
	static bool GetKeyCtrl(KeyState state);	// コントロールキー
};