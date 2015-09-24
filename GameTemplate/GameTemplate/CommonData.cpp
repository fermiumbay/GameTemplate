#include "CommonData.h"

SaveData CommonData::saveData;
UnSaveData CommonData::unSaveData;

bool CommonData::Initialize(){
	unSaveData.gameTime = 0;
	return true;
}

bool CommonData::Finalize(){
	return true;
}

bool CommonData::Save(string path){
	return false;
}

bool CommonData::Load(string path){
	return false;
}
