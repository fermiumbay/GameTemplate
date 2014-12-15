#pragma once
#include "DxLib.h"
#include <random>

// 乱数クラス
class Random{
	static std::mt19937 mt;	// メルセンヌツイスタ
public:
	static const void DefaultRand();	// 乱数初期化
	static const void SetDefaultRand(int value);	// 初期値を指定して乱数初期化
	static const void DefaultRand(int value);	// 初期値を指定して乱数初期化（SetDefaultRandと同義）
	static const int Rand(int value);	// 乱数取得（0～value-1）
	static const int Rand(int min, int max);	// 乱数取得（min～max）
	static const double DRand(double min, double max);	// 実数乱数取得（min～max）
	static std::mt19937 GetMt();	// メルセンヌツイスタの取得
};
