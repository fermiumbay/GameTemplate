#include "Sound.h"

Sound* Sound::Create(string path, bool loopFlg, int loopPos, bool seFlg){
	Sound* ret = new Sound();
	ret->handle = LoadSoundMem(path.c_str());
	ret->loopFlg = loopFlg;
	ret->SetLoopPos(loopPos);
	ret->seFlg = seFlg;
	SetSoundCurrentTime(0, ret->handle);
	return ret;
}

void Sound::Delete(Sound* sound){
	DeleteSoundMem(sound->handle);
	delete sound;
}

void Sound::SetLoopFlg(bool loopFlg){
	this->loopFlg = loopFlg;
	if (this->loopFlg){
		SetLoopPosSoundMem(this->loopPos, this->handle);
	}
}

void Sound::SetLoopPos(int loopPos){
	this->loopPos = loopPos;
	if (this->loopFlg){
		SetLoopPosSoundMem(this->loopPos, this->handle);
	}
}

void Sound::Play(int playPos){
	if (playPos != -1){
		// 再生位置を指定して再生
		SetSoundCurrentTime(playPos, handle);
	}
	else if (seFlg){
		playPos = 0;
	}
	if (loopFlg){
		PlaySoundMem(handle, DX_PLAYTYPE_LOOP, 0);
	}
	else{
		// ループしないサウンドは再生位置を0に指定した場合のみ再生位置が戻るようにする
		PlaySoundMem(handle, DX_PLAYTYPE_BACK, playPos == 0);
	}
}

void Sound::Stop(bool stayFlg){
	StopSoundMem(handle);
	if (!stayFlg){
		SetSoundCurrentTime(0, handle);
	}
}

bool Sound::IsPlaying(){
	if (CheckSoundMem(handle) == 1){
		return true;
	}
	else{
		return false;
	}
}

int Sound::GetPlayPos(){
	return GetSoundCurrentTime(handle);
}

void Sound::SetPan(int pan){
	SetPanSoundMem(pan, handle);
}

void Sound::SetVolume(int volume){
	ChangeVolumeSoundMem(volume, handle);
}

void Sound::SetSpeed(int speed){
	ResetFrequencySoundMem(handle);	// これしないとサンプリング周波数が得られない
	int frequency = GetFrequencySoundMem(handle);
	SetFrequencySoundMem(frequency * speed / 100, handle);
}

void Sound::SetFrequency(int frequency){
	SetFrequencySoundMem(frequency, handle);
}

Sound* Sound::CreateBGM(string path, int loopPos){
	return Create(path, true, loopPos, false);
}

Sound* Sound::CreateSE(string path){
	return Create(path, false, 0, true);
}
