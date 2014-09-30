#pragma once
#include "Graphic.h"
#include "Sound.h"
#include <string>
#include <map>
using namespace std;

// ゲームにおける様々な振る舞いを行うオブジェクトの基底
class GameBehavior{
	virtual enum State{none};	// 状態の種類
	State state;	// 現在の状態
	int stateTime;	// 現在の状態になってからの経過時間
protected:
	map<string, Graphic*>	pic;	// 画像
	map<string, Sound*>	sound;	// 音楽
	void DeletePic(string name);	// 画像の削除
	void DeleteSound(string name);	// 音楽の削除
	inline State GetState();	// 状態の取得
	inline int GetStateTime();	// 現在の状態になってからの経過時間取得

	// 状態の変更
	template<class NewState>
	void ChangeState(NewState state){
		this->state = static_cast<GameBehavior::State>(state);
	}

public:
	GameBehavior();
	virtual ~GameBehavior();
	virtual void Update();	// 更新
	virtual void Draw();	// 描画
};
