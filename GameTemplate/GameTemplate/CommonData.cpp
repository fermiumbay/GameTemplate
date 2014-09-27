#include "CommonData.h"

// static変数の実体化（グローバル変数となる）
SaveData CommonData::saveData;
UnSaveData CommonData::unSaveData;

bool CommonData::Initialize(){
	unSaveData.gameTime = 0;
	return true;
}

bool CommonData::Finalization(){
	return true;
}

bool CommonData::Save(string path){
	return false;
}

bool CommonData::Load(string path){
	return false;
}
