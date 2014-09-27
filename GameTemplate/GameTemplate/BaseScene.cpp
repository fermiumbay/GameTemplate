#include "BaseScene.h"

BaseScene::BaseScene(){
	sceneTime = 0;
	endGameFlg = false;
	changeSceneFlg = false;
	changeSceneName = "";
	pic.clear();
	sound.clear();
	SetDefaultFade();
}

BaseScene::~BaseScene(){
	for(map<string, Graphic*>::iterator it = pic.begin(); it != pic.end(); it++){
		delete (*it).second;
	}
	for(map<string, Sound*>::iterator it = sound.begin(); it != sound.end(); it++){
		delete (*it).second;
	}
}

void BaseScene::EndGame(){
	endGameFlg = true;
}

void BaseScene::ChangeScene(string name){
	changeSceneFlg = true;
	changeSceneName = name;
}

void BaseScene::Update(){
	sceneTime++;
	CommonData::unSaveData.gameTime++;
}

void BaseScene::Draw(){
	SetDrawBright(fade_r, fade_g, fade_b);
}

int BaseScene::GetSceneTime(){
	return sceneTime;
}

bool BaseScene::GetChangeSceneFlg(){
	return changeSceneFlg;
}

string BaseScene::GetChangeSceneName(){
	return changeSceneName;
}

bool BaseScene::GetEndGameFlg(){
	return endGameFlg;
}

void BaseScene::DeletePic(string name){
	delete pic[name];
	pic.erase(name);
}

void BaseScene::DeleteSound(string name){
	delete sound[name];
	sound.erase(name);
}

void BaseScene::SetFade(int r, int g, int b){
	fade_r = r;
	fade_g = g;
	fade_b = b;
}

void BaseScene::SetDefaultFade(){
	SetFade(255, 255, 255);
}
