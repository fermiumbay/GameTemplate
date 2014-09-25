#pragma once
#include "common.h"
#include "ContentBase.h"

// サウンド素材クラス
class Sound : public ContentBase{
	int loopPos;
	bool loopFlg;
public:
	Sound(const TCHAR *path = "", bool loopFlg = false, int loopPos = 0);
	~Sound();
	void SetLoopFlg(bool loopFlg);	// ループの可否を設定
	void SetLoopPos(int loopPos);	// ループ位置を設定［ms］
	virtual void Play(int playPos = -1);	// 再生（単位[ms]）（引数省略で現在の再生位置から再開）
	void Stop();	// 停止
	bool IsPlaying();	// 再生中であるか調べる
	int GetPlayPos();	// 再生位置を取得
	void SetPan(int pan = 0);	// パン設定（-10000～10000）
	void SetVolume(int volume = 255);	// 音量設定（0～255）
	void SetSpeed(int speed = 100);	// 速さ設定[％]（100KHzを超える速さ（サンプリング周波数44100Hzだと226％まで）にはできない）
	void SetFrequency(int frequency = -1);	// 再生周波数設定[Hz]
};

// BGMクラス
struct BGM : public Sound{
	BGM(const TCHAR *path = "", int loopPos = 0);
};

// 効果音クラス
struct SE : public Sound{
	SE(const TCHAR *path = "");
	void Play(int playPos) override;	// 再生（単位[ms]）（引数省略で通常再生）
};
