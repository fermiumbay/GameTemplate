#pragma once
#include "common.h"
#include "Scenes.h"

class SceneManager{
	string currentScene;	// 現在のシーン名称
	BaseScene* scene;	// シーン
	void CloseScene();	// 現在のシーンを閉じる
	void NewScene();	// 新規シーンを読み込む
	bool exitFlg;	// ゲーム終了フラグ
public:
	SceneManager();
	~SceneManager();
	void Update();	// 更新
	void Draw();	// 描画
	bool GetExitFlg();	// ゲーム終了フラグ取得
};

