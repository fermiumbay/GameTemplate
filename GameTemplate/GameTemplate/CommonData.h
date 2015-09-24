#pragma once
#include "common.h"

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

	// セーブに含めるデータ
	static SaveData saveData;

	// セーブに含めないデータ
	static UnSaveData unSaveData;

	// データの初期化（成功したらtrue）
	static bool Initialize();

	// データの終了処理（成功したらtrue）
	static bool Finalize();

	// データのセーブ（成功したらtrue）
	static bool Save(string path);

	// データのロード（成功したらtrue）
	static bool Load(string path);
};
