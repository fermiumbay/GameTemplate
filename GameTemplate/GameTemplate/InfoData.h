#pragma once
#include <string>
#include "Vector2.h"
using namespace std;

// 固定情報データ（ゲーム中に変化しない情報）
namespace InfoData{
	// ゲームタイトル
	inline static const string GameTitle(){
		return "新規プロジェクト";
	}

	// ウィンドウサイズ
	inline static const Vector2 WindowSize(){
		return Vector2(640, 480);
	}

	// ウィンドウのカラービット数
	inline static const int WindowColorBitNum(){
		return 32;
	}

	// ウィンドウモードフラグ
	inline static const bool WindowMode(){
		return true;
	}

	// 初期シーン名称
	inline static const string DefaultScene(){
		return "Main";
	}
};
