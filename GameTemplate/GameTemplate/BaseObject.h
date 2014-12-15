#pragma once
#include "CommonData.h"

// ゲームにおける様々な振る舞いを行うオブジェクトの基底
class BaseObject{
	virtual enum State{ none };	// 状態の種類
	State state;	// 現在の状態
	int stateTime;	// 現在の状態になってからの経過時間
	vector<future<void>*> futureVector;	// 並列読み込み用フューチャー配列
protected:
	map<string, Graphic*> pic;	// 画像
	map<string, vector<Graphic*>> picDiv;	// 分割画像
	map<string, GraphicHandle> picHandle;	// 画像ハンドル
	map<string, Sound*> sound;	// 音楽
	map<string, Font*> font;	// フォント
	void DeletePic(string name);	// 画像の削除
	void DeletePicDiv(string name);	// 分割画像の削除
	void DeletePicHandle(string name);	// 画像ハンドルの削除
	void DeleteSound(string name);	// 音楽の削除
	void DeleteFont(string name);	// フォントの削除
	State GetState();	// 状態の取得
	int GetStateTime();	// 現在の状態になってからの経過時間取得
	void AddThread(function<void()> thread);	// 並列処理スレッドの追加
	int GetThreadTotalNum();	// 追加されているスレッド総数
	int GetFinishedThreadNum();	// 追加されているスレッドのうち終了したスレッド数
	bool AllThreadFinished();	// 追加されている全スレッドが終了した
	void WaitForThread();	// 全スレッド終了待ち
	void ClearThread();	// 全スレッド消去

	// 状態の変更
	template<class NewState>
	void ChangeState(NewState state){
		this->state = static_cast<BaseObject::State>(state);
		stateTime = 0;
	}

public:
	BaseObject();
	virtual ~BaseObject();
	virtual void Update();	// 更新
	virtual void Draw();	// 描画
};
