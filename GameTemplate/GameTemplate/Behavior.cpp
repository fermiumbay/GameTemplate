#include "Behavior.h"

Behavior::Behavior(){
	pic.clear();
	picDiv.clear();
	picHandle.clear();
	picDivHandle.clear();
	sound.clear();
	font.clear();
	state = State::none;
	stateTime = 0;
}

Behavior::~Behavior(){
	for (map<string, Graphic*>::iterator it = pic.begin(); it != pic.end(); it++){
		Graphic::Delete((*it).second);
	}
	for (map<string, vector<Graphic*>>::iterator it = picDiv.begin(); it != picDiv.end(); it++){
		Graphic::Delete((*it).second);
	}
	for (map<string, GraphicHandle*>::iterator it = picDivHandle.begin(); it != picDivHandle.end(); it++){
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
	Graphic::Delete(picDiv[name]);
	picDiv.erase(name);
}

void Behavior::DeletePich(string name){
	picHandle.erase(name);
}

void Behavior::DeletePicdh(string name){
	delete[] picDivHandle[name];
	picDivHandle.erase(name);
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
