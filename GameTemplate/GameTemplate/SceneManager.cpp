#include "SceneManager.h"

void SceneManager::NewScene(){
	scene = Scenes::GetSceneObject(currentScene);
	ClearDrawScreen();
}

void SceneManager::CloseScene(){
	delete scene;
}

SceneManager::SceneManager(){
	exitFlg = false;
	currentScene = InfoData::DefaultScene();
	NewScene();
}

SceneManager::~SceneManager(){
	CloseScene();
}

void SceneManager::Update(){
	if(scene->GetEndGameFlg()){
		exitFlg = true;
	}
	if(scene->GetChangeSceneFlg()){
		string tmp = scene->GetChangeSceneName();
		CloseScene();
		currentScene = tmp;
		NewScene();
	}
	scene->Update();
}

void SceneManager::Draw(){
	scene->Draw();
}

bool SceneManager::GetExitFlg(){
	return exitFlg;
}
