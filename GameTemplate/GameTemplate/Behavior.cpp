#include "Behavior.h"

Behavior::Behavior(){
	pic.clear();
	sound.clear();
	state = State::none;
	stateTime = 0;
}

Behavior::~Behavior(){
	for (map<string, Graphic*>::iterator it = pic.begin(); it != pic.end(); it++){
		delete (*it).second;
	}
	for (map<string, Sound*>::iterator it = sound.begin(); it != sound.end(); it++){
		delete (*it).second;
	}
}

void Behavior::Update(){
	stateTime++;
}

void Behavior::Draw(){
}

void Behavior::DeletePic(string name){
	delete pic[name];
	pic.erase(name);
}

void Behavior::DeleteSound(string name){
	delete sound[name];
	sound.erase(name);
}

Behavior::State Behavior::GetState(){
	return state;
}

int Behavior::GetStateTime(){
	return stateTime;
}
