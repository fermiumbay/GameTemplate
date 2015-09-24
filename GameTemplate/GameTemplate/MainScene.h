#pragma once
#include "BaseScene.h"

// ゲーム画面クラス
class MainScene : public BaseScene{
public:

	// コンストラクタ
	MainScene();

	// デストラクタ
	~MainScene();

	// 更新
	void Update() override;

	// 描画
	void Draw() override;

};
