#include "Behavior.h"

Behavior::Behavior(){
	pic.clear();
	picd.clear();
	pich.clear();
	picdh.clear();
	sound.clear();
	font.clear();
	state = State::none;
	stateTime = 0;
}

Behavior::~Behavior(){
	for (map<string, Graphic*>::iterator it = pic.begin(); it != pic.end(); it++){
		Graphic::Delete((*it).second);
	}
	for (map<string, vector<Graphic*>>::iterator it = picd.begin(); it != picd.end(); it++){
		Graphic::Delete((*it).second);
	}
	for (map<string, GraphicHandle*>::iterator it = picdh.begin(); it != picdh.end(); it++){
		delete[] (*it).second;
	}
	for (map<string, Sound*>::iterator it = sound.begin(); it != sound.end(); it++){
		Sound::Delete((*it).second);
	}
	for (map<string, Font*>::iterator it = font.begin(); it != font.end(); it++){
		Font::Delete((*it).second);
	}
}

void Behavior::Update(){
	stateTime++;
}

void Behavior::Draw(){
}

void Behavior::DeletePic(string name){
	Graphic::Delete(pic[name]);
	pic.erase(name);
}

void Behavior::DeletePicd(string name){
	Graphic::Delete(picd[name]);
	picd.erase(name);
}

void Behavior::DeletePich(string name){
	pich.erase(name);
}

void Behavior::DeletePicdh(string name){
	delete[] picdh[name];
	picdh.erase(name);
}

void Behavior::DeleteSound(string name){
	Sound::Delete(sound[name]);
	sound.erase(name);
}

void Behavior::DeleteFont(string name){
	Font::Delete(font[name]);
	font.erase(name);
}

Behavior::State Behavior::GetState(){
	return state;
}

int Behavior::GetStateTime(){
	return stateTime;
}
