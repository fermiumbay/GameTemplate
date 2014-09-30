#include "GameBehavior.h"

GameBehavior::GameBehavior(){
	pic.clear();
	sound.clear();
	state = State::none;
}

GameBehavior::~GameBehavior(){
	for (map<string, Graphic*>::iterator it = pic.begin(); it != pic.end(); it++){
		delete (*it).second;
	}
	for (map<string, Sound*>::iterator it = sound.begin(); it != sound.end(); it++){
		delete (*it).second;
	}
}

void GameBehavior::Update(){
	stateTime++;
}

void GameBehavior::Draw(){
}

void GameBehavior::DeletePic(string name){
	delete pic[name];
	pic.erase(name);
}

void GameBehavior::DeleteSound(string name){
	delete sound[name];
	sound.erase(name);
}

GameBehavior::State GameBehavior::GetState(){
	return state;
}

int GameBehavior::GetStateTime(){
	return stateTime;
}
