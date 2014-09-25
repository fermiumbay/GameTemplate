#pragma once
#include "common.h"
#include "CommonData.h"

// 基底クラス
class BaseScene{
	int sceneTime;	// シーン開始からの経過時間
	bool endGameFlg;	// ゲーム終了フラグ
	bool changeSceneFlg;	// シーン変更フラグ
	string changeSceneName;	// シーン変更後のシーン名
protected:
	int GetSceneTime();	// シーン開始からの経過時間取得
	void EndGame();	// ゲームを終了する
	void ChangeScene(string name);	// シーンを変更する
	map<string, Graphic*>	pic;	// 画像
	map<string, Sound*>	sound;	// 音楽
public:
	BaseScene();
	virtual ~BaseScene() = 0;
	virtual void Update();	// 更新
	virtual void Draw();	// 描画
	bool GetEndGameFlg();	// ゲーム終了フラグ取得
	bool GetChangeSceneFlg();	// シーン変更フラグ取得
	string GetChangeSceneName();	// シーン変更後のシーン名取得
};
