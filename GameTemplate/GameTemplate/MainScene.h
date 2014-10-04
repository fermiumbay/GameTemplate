#pragma once
#include "BaseScene.h"

// ゲーム画面クラス
class MainScene : public BaseScene{
public:
	MainScene();	// コンストラクタ
	~MainScene();	// デストラクタ
	void Update() override;	// 更新
	void Draw() override;	// 描画
};
