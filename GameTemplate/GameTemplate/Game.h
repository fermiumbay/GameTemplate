#pragma once
#include "SceneManager.h"

// ゲームクラス
class Game {
public:

	// コンストラクタ
	Game();

	// デストラクタ
	~Game();

	// ゲームをプレイ
	void Play();

	// ゲームをやめる
	bool Exit();
private:

	// シーンマネージャー
	SceneManager sm;

};
