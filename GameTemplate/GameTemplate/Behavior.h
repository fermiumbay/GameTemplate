#pragma once
#include "CommonData.h"

// ゲームにおける様々な振る舞いを行うオブジェクトの基底
class Behavior{
	virtual enum State{none};	// 状態の種類
	State state;	// 現在の状態
	int stateTime;	// 現在の状態になってからの経過時間
protected:
	map<string, Graphic*> pic;	// 画像
	map<string, vector<Graphic*>> picDiv;	// 分割画像
	map<string, GraphicHandle> picHandle;	// 画像ハンドル
	map<string, GraphicHandle*> picDivHandle;	// 分割画像ハンドル
	map<string, Sound*> sound;	// 音楽
	map<string, Font*> font;	// フォント
	void DeletePic(string name);	// 画像の削除
	void DeletePicDiv(string name);	// 分割画像の削除
	void DeletePicHandle(string name);	// 画像ハンドルの削除
	void DeletePicDivHandle(string name);	// 分割画像ハンドルの削除
	void DeleteSound(string name);	// 音楽の削除
	void DeleteFont(string name);	// フォントの削除
	State GetState();	// 状態の取得
	int GetStateTime();	// 現在の状態になってからの経過時間取得

	// 状態の変更
	template<class NewState>
	void ChangeState(NewState state){
		this->state = static_cast<Behavior::State>(state);
		stateTime = 0;
	}

public:
	Behavior();
	virtual ~Behavior();
	virtual void Update();	// 更新
	virtual void Draw();	// 描画
};
