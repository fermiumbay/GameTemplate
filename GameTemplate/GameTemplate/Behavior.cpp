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
	for (auto data : pic){
		Graphic::Delete(data.second);
	}
	for (auto data : picDiv){
		Graphic::DeleteDiv(data.second);
	}
	for (auto data : picHandle){
		Graphic::DeleteHandle(data.second);
	}
	for (auto data : sound){
		Sound::Delete(data.second);
	}
	for (auto data : font){
		Font::Delete(data.second);
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
	Graphic::Delete(picHandle[name]);
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
