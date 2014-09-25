#pragma once
#include "DxLib.h"
#include <time.h>

// 乱数クラス
class Random{
public:

	// 乱数初期化
	inline static const void DefaultRand(){
		SRand((int)time(NULL));
	}

	// 乱数の初期値設定
	inline static const void SetDefaultRand(int value){
		SRand(value);
	}

	// 乱数取得（0～value-1）
	inline static const int Rand(int value){
		return GetRand(value - 1);
	}

};
