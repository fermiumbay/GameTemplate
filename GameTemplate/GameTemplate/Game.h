#pragma once
#include "common.h"
#include "SceneManager.h"

// ゲームクラス
class Game{
	SceneManager sm;	// シーンマネージャー
public:
	Game();	// コンストラクタ
	~Game();	// デストラクタ
	void Play();	// ゲームをプレイ
	bool Exit();	// ゲームをやめる
};
