#pragma once
#include "DxLib.h"
#include "includes.h"

// 乱数クラス
class Random{
public:

	// 乱数初期化
	static const void DefaultRand();

	// 初期値を指定して乱数初期化
	static const void SetDefaultRand(int value);

	// 初期値を指定して乱数初期化（SetDefaultRandと同義）
	static const void DefaultRand(int value);

	// 乱数取得（0～value-1）
	static const int Rand(int value);

	// 乱数取得（min～max）
	static const int Rand(int min, int max);

	// 実数乱数取得（min～max）
	static const double DRand(double min, double max);

	// メルセンヌツイスタの取得
	static std::mt19937 GetMt();

private:

	static std::mt19937 mt;	// メルセンヌツイスタ

};
