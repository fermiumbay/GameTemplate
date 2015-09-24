#pragma once
#include "BaseObject.h"

// シーン基底クラス
class BaseScene : public BaseObject{
public:

	// コンストラクタ
	BaseScene();

	// デストラクタ
	virtual ~BaseScene();

	// 更新
	virtual void Update();

	// 描画
	virtual void Draw();

	// ゲーム終了フラグ取得
	bool GetEndGameFlg();

	// シーン変更フラグ取得
	bool GetChangeSceneFlg();

	// シーン変更後のシーン名取得
	string GetChangeSceneName();

protected:

	// シーン開始からの経過時間取得
	int GetSceneTime();

	// ゲームを終了する
	void EndGame();

	// シーンを変更する
	void ChangeScene(string name);

	// 画面色調
	Color screenFade;

	// 色調変更
	void SetFade(Color c);

	// 色調を元に戻す
	void SetDefaultFade();

private:

	// シーン開始からの経過時間
	int sceneTime;

	// ゲーム終了フラグ
	bool endGameFlg;

	// シーン変更フラグ
	bool changeSceneFlg;

	// シーン変更後のシーン名
	string changeSceneName;

};
