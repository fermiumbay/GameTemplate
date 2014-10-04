#pragma once
#include "DxLib.h"
#include <string>
using namespace std;

// サウンド素材クラス
class Sound{
	int handle;	// ハンドル
	int loopPos;	// ループ位置
	bool loopFlg;	// ループフラグ
	bool seFlg;	// 効果音フラグ
protected:
	Sound(){}
	~Sound(){}
	Sound(const Sound&){}
	Sound& operator=(const Sound&);
	static Sound* Create(string path = "", bool loopFlg = false, int loopPos = 0, bool seFlg = false);	// 音楽作成
public:
	void SetLoopFlg(bool loopFlg);	// ループの可否を設定
	void SetLoopPos(int loopPos);	// ループ位置を設定［ms］
	virtual void Play(int playPos = -1);	// 再生（単位[ms]）（引数省略で現在の再生位置から再開）
	void Stop(bool stayFlg = false);	// 停止（再生位置を維持する場合はstayFlgをtrue）
	bool IsPlaying();	// 再生中であるか調べる
	int GetPlayPos();	// 再生位置を取得
	void SetPan(int pan = 0);	// パン設定（-10000～10000）
	void SetVolume(int volume = 255);	// 音量設定（0～255）
	void SetSpeed(int speed = 100);	// 速さ設定[％]（100KHzを超える速さ（サンプリング周波数44100Hzだと226％まで）にはできない）
	void SetFrequency(int frequency = -1);	// 再生周波数設定[Hz]

	static Sound* CreateBGM(string path = "", int loopPos = 0);
	static Sound* CreateSE(string path = "");
	static void Delete(Sound* sound);	// 音楽削除
};
