#include "CommonData.h"

// static�ϐ��̎��̉��i�O���[�o���ϐ��ƂȂ�j
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
