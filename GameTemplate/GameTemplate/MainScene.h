#pragma once
#include "BaseScene.h"

// ゲーム画面クラス
class MainScene : public BaseScene{
	bool reverseFlg;	// 反転フラグ
	void SetKeys();	// キーの判定条件のセット
public:
	MainScene();	// コンストラクタ
	~MainScene();	// デストラクタ
	void Update() override;	// 更新
	void Draw() override;	// 描画
};