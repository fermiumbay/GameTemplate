#include "BaseObject.h"

BaseObject::BaseObject(){
	pic.clear();
	picDiv.clear();
	picHandle.clear();
	sound.clear();
	font.clear();
	screen.clear();
	state = State::none;
	stateTime = 0;
	threadVector.clear();
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
	for (auto data : font) {
		Font::Delete(data.second);
	}
	for (auto data : screen) {
		Screen::Delete(data.second);
	}
	ClearThread();
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

void BaseObject::DeleteFont(string name) {
	Font::Delete(font[name]);
	font.erase(name);
}

void BaseObject::DeleteScreen(string name) {
	Screen::Delete(screen[name]);
	screen.erase(name);
}

BaseObject::State BaseObject::GetState(){
	return state;
}

int BaseObject::GetStateTime(){
	return stateTime;
}

void BaseObject::AddThread(function<void()> func){
	threadVector.push_back(new thread(func));
}

int BaseObject::GetThreadTotalNum(){
	return threadVector.size();
}

int BaseObject::GetFinishedThreadNum(){
	int ret = 0;
	for (auto data : threadVector){
		DWORD param;
		GetExitCodeThread(data->native_handle(), &param);
		if (param != STILL_ACTIVE){
			ret++;
		}
	}
	return ret;
}

void BaseObject::ClearThread(){
	for (auto data : threadVector){
		data->join();
		delete data;
	}
	threadVector.clear();
}

bool BaseObject::AllThreadFinished(){
	return GetFinishedThreadNum() == GetThreadTotalNum();
}
