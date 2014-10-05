#include "BaseObject.h"

BaseObject::BaseObject(){
	pic.clear();
	picDiv.clear();
	picHandle.clear();
	sound.clear();
	font.clear();
	state = State::none;
	stateTime = 0;
}

BaseObject::~BaseObject(){
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

void BaseObject::Update(){
	stateTime++;
}

void BaseObject::Draw(){
}

void BaseObject::DeletePic(string name){
	Graphic::Delete(pic[name]);
	pic.erase(name);
}

void BaseObject::DeletePicDiv(string name){
	Graphic::DeleteDiv(picDiv[name]);
	picDiv.erase(name);
}

void BaseObject::DeletePicHandle(string name){
	Graphic::Delete(picHandle[name]);
	picHandle.erase(name);
}

void BaseObject::DeleteSound(string name){
	Sound::Delete(sound[name]);
	sound.erase(name);
}

void BaseObject::DeleteFont(string name){
	Font::Delete(font[name]);
	font.erase(name);
}

BaseObject::State BaseObject::GetState(){
	return state;
}

int BaseObject::GetStateTime(){
	return stateTime;
}
