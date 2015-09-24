#pragma once
#include "DxLib.h"
#include "includes.h"

// サウンド素材クラス
class Sound{
public:

	// ループの可否を設定
	void SetLoopFlg(bool loopFlg);

	// ループ位置を設定［ms］
	void SetLoopPos(int loopPos);

	// 再生（単位[ms]）（引数省略で現在の再生位置から再開）
	virtual void Play(int playPos = -1);

	// 停止（再生位置を維持する場合はstayFlgをtrue）
	void Stop(bool stayFlg = false);

	// 再生中であるか調べる
	bool IsPlaying();

	// 再生位置を取得
	int GetPlayPos();

	// パン設定（-10000～10000）
	void SetPan(int pan = 0);

	// 音量設定（0～255）
	void SetVolume(int volume = 255);

	// 速さ設定[％]（100KHzを超える速さ（サンプリング周波数44100Hzだと226％まで）にはできない）
	void SetSpeed(int speed = 100);

	// 再生周波数設定[Hz]
	void SetFrequency(int frequency = -1);

	// BGM作成
	static Sound* CreateBGM(string path = "", int loopPos = 0);

	// SE作成
	static Sound* CreateSE(string path = "");

	// 音楽削除
	static void Delete(Sound* sound);

protected:

	Sound() {}
	~Sound() {}
	Sound(const Sound&) {}
	Sound& operator=(const Sound&) {}

	// 音楽作成
	static Sound* Create(string path = "", bool loopFlg = false, int loopPos = 0, bool seFlg = false);

private:

	// ハンドル
	int handle;

	// ループ位置
	int loopPos;

	// ループフラグ
	bool loopFlg;

	// 効果音フラグ
	bool seFlg;
};
