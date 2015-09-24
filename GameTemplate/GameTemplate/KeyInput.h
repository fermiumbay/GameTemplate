#pragma once
#include "DxLib.h"
#include <map>
#include <functional>
using namespace std;

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
public:

	// キー入力の初期化（成功したらtrue）
	static bool Initialize();

	// キー状態取得
	static bool GetKey(KeyType type, KeyState state);

	// キーの判定条件を設定
	static void SetKeyCond(KeyType type, function<bool()> cond);

	// キーの判定条件を別のキーにコピー
	static void CopyKeyCond(KeyType copiedType, KeyType copyingType);

private:
	// キー入力に用いるキー
	class Key {
	public:

		// 前回押したフラグ
		bool prevPushFlg;

		// 判定条件
		function<bool()> cond;

		Key() {}
		Key(function<bool()> cond);
	};

	KeyInput() {}
	~KeyInput() {}

	// キー押下状況を調べ、条件に一致するかどうか判定する
	static bool CheckKeyState(bool cond, KeyState state, bool prevPushFlg);

	// キー
	static map<KeyType, Key> key;
};
