#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include "Vector2.h"
using namespace std;

// セーブする共通データ
struct SaveData{
};

// セーブしない共通データ
struct UnSaveData{
	int gameTime;	// ゲーム進行時間
};

// 共通データ
class CommonData{
public:
	static SaveData saveData;	// セーブに含めるデータ
	static UnSaveData unSaveData;	// セーブに含めないデータ
	static bool Initialize();	// データの初期化（成功したらtrue）
	static bool Save(string path);	// データのセーブ（成功したらtrue）
	static bool Load(string path);	// データのロード（成功したらtrue）
};
