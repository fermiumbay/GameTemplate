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
	GameBehavior::Update();
	sceneTime++;
	CommonData::unSaveData.gameTime++;
}

void BaseScene::Draw(){
	GameBehavior::Draw();
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

void BaseScene::SetFade(int r, int g, int b){
	fade_r = r;
	fade_g = g;
	fade_b = b;
}

void BaseScene::SetDefaultFade(){
	SetFade(255, 255, 255);
}
