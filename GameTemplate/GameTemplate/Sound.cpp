#include "Sound.h"

Sound::Sound(const TCHAR *path, bool loopFlg, int loopPos){
	this->handle = new int(LoadSoundMem(path));
	this->loopFlg = loopFlg;
	SetLoopPos(loopPos);
	SetSoundCurrentTime(0, *(this->handle));
}

Sound::~Sound(){
	DeleteSoundMem(*handle);
	delete handle;
}

void Sound::SetLoopFlg(bool loopFlg){
	this->loopFlg = loopFlg;
	if(this->loopFlg){
		SetLoopPosSoundMem(this->loopPos, *(this->handle));
	}
}

void Sound::SetLoopPos(int loopPos){
	this->loopPos = loopPos;
	if(this->loopFlg){
		SetLoopPosSoundMem(this->loopPos, *(this->handle));
	}
}

void Sound::Play(int playPos){
	if(playPos != -1){
		// �Đ��ʒu���w�肵�čĐ�
		SetSoundCurrentTime(playPos, *handle);
	}
	if(loopFlg){
		PlaySoundMem(*handle, DX_PLAYTYPE_LOOP, 0);
	}
	else{
		// ���[�v���Ȃ��T�E���h�͍Đ��ʒu��0�Ɏw�肵���ꍇ�̂ݍĐ��ʒu���߂�悤�ɂ���
		PlaySoundMem(*handle, DX_PLAYTYPE_BACK, playPos == 0);
	}
}

void Sound::Stop(){
	StopSoundMem(*handle);
}

bool Sound::IsPlaying(){
	if(CheckSoundMem(*handle) == 1)
		return true;
	else
		return false;
}

int Sound::GetPlayPos(){
	return GetSoundCurrentTime(*handle);
}

void Sound::SetPan(int pan){
	SetPanSoundMem(pan, *handle);
}

void Sound::SetVolume(int volume){
	ChangeVolumeSoundMem(volume, *handle);
}

void Sound::SetSpeed(int speed){
	ResetFrequencySoundMem(*handle);	// ���ꂵ�Ȃ��ƃT���v�����O���g���������Ȃ�
	int frequency = GetFrequencySoundMem(*handle);
	SetFrequencySoundMem(frequency * speed / 100, *handle);
}

void Sound::SetFrequency(int frequency){
	SetFrequencySoundMem(frequency, *handle);
}

BGM::BGM(const TCHAR *path, int loopPos) : Sound(path, true, loopPos){

}

SE::SE(const TCHAR *path) : Sound(path, false){
	
}

void SE::Play(int playPos){
	if (playPos == -1){
		playPos = 0;
	}
	Sound::Play(playPos);
}