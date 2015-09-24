#pragma once
#include "Scenes.h"

class SceneManager{
public:

	// コンストラクタ
	SceneManager();

	// デストラクタ
	~SceneManager();

	// 更新
	void Update();

	// 描画
	void Draw();

	// ゲーム終了フラグ取得
	bool GetExitFlg();

private:

	// 現在のシーン名称
	string currentScene;

	// シーン
	BaseScene* scene;

	// 現在のシーンを閉じる
	void CloseScene();

	// 新規シーンを読み込む
	void NewScene();

	// ゲーム終了フラグ
	bool exitFlg;

};
