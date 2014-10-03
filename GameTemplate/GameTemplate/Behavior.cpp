#include "Behavior.h"

Behavior::Behavior(){
	pic.clear();
	picDiv.clear();
	picHandle.clear();
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
		Graphic::DeleteDiv((*it).second);
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

void Behavior::DeletePicDiv(string name){
	Graphic::DeleteDiv(picDiv[name]);
	picDiv.erase(name);
}

void Behavior::DeletePicHandle(string name){
	Graphic::DeleteHandle(picHandle[name]);
	picHandle.erase(name);
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
