#pragma once
#include "DxLib.h"
#include "common.h"

// キー入力の状態
enum KeyState{
	PushedNow,	// 押した瞬間
	HasBePushed,	// 押している状態
	ReleaseNow,	// 離した瞬間
	NeverPushed,	// 離している状態
};

// キーの種類
enum KeyType{
	Down,	// ↓
	Left,	// ←
	Right,	// →
	Up,	// ↑
	OK,	// 決定キー
	Cancel,	// キャンセルキー
	Shift,	// シフトキー
	Ctrl,	// コントロールキー
};

// キー入力
class KeyInput{

	// キー入力に用いるキー
	class Key{
	public:
		bool prevPushFlg;	// 前回押したフラグ
		function<bool()> cond;	// 判定条件
		Key(){}
		Key(function<bool()> cond);
	};

	KeyInput(){}
	~KeyInput(){}
	static bool CheckKeyState(bool cond, KeyState state, bool prevPushFlg);	// キー押下状況を調べ、条件に一致するかどうか判定する
	static map<KeyType, Key> key;	// キー
public:
	static bool Initialize();	// キー入力の初期化（成功したらtrue）
	static bool GetKey(KeyType type, KeyState state);	// キー状態取得
	static void SetKeyCond(KeyType type, function<bool()> cond);	// キーの判定条件を設定
};