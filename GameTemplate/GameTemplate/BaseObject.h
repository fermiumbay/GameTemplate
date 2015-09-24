#pragma once
#include "CommonData.h"

// ゲームにおける様々な振る舞いを行うオブジェクトの基底
class BaseObject{

	// 状態の種類
	enum State { none };

public:

	// コンストラクタ
	BaseObject();

	// デストラクタ
	virtual ~BaseObject();

	// 更新
	virtual void Update();

	// 描画
	virtual void Draw();

protected:

	// 画像
	map<string, Graphic*> pic;

	// 分割画像
	map<string, vector<Graphic*>> picDiv;

	// 画像ハンドル
	map<string, GraphicHandle> picHandle;

	// 音楽
	map<string, Sound*> sound;

	// フォント
	map<string, Font*> font;

	// スクリーン
	map<string, Screen*> screen;

	// 画像の削除
	void DeletePic(string name);

	// 分割画像の削除
	void DeletePicDiv(string name);

	// 画像ハンドルの削除
	void DeletePicHandle(string name);

	// 音楽の削除
	void DeleteSound(string name);

	// フォントの削除
	void DeleteFont(string name);

	// スクリーンの削除
	void DeleteScreen(string name);

	// 状態の取得
	State GetState();

	// 現在の状態になってからの経過時間取得
	int GetStateTime();

	// 並列処理スレッドの追加
	void AddThread(function<void()> thread);

	// 追加されているスレッド総数
	int GetThreadTotalNum();

	// 追加されているスレッドのうち終了したスレッド数
	int GetFinishedThreadNum();

	// 追加されている全スレッドが終了した
	bool AllThreadFinished();

	// 全スレッド消去
	void ClearThread();

	// 状態の変更
	template<class NewState>
	void ChangeState(NewState state){
		this->state = static_cast<BaseObject::State>(state);
		stateTime = 0;
	}

private:

	// 現在の状態
	State state;

	// 現在の状態になってからの経過時間
	int stateTime;

	// 並列読み込み用スレッド配列
	vector<thread*> threadVector;	
};
