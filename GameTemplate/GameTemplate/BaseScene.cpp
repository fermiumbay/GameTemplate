#include "BaseScene.h"

BaseScene::BaseScene(){
	sceneTime = 0;
	endGameFlg = false;
	changeSceneFlg = false;
	changeSceneName = "";
	SetDefaultFade();
}

BaseScene::~BaseScene(){
}

void BaseScene::EndGame(){
	endGameFlg = true;
}

void BaseScene::ChangeScene(string name){
	changeSceneFlg = true;
	changeSceneName = name;
}

void BaseScene::Update(){
	BaseObject::Update();
	sceneTime++;
	CommonData::unSaveData.gameTime++;
}

void BaseScene::Draw(){
	BaseObject::Draw();
	SetDrawBright(screenFade.GetR(), screenFade.GetG(), screenFade.GetB());
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

void BaseScene::SetFade(Color c){
	screenFade = c;
}

void BaseScene::SetDefaultFade(){
	SetFade(Color::White());
}
