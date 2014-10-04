#pragma once
#include "DxLib.h"
#include <string>
using namespace std;

// �T�E���h�f�ރN���X
class Sound{
	int handle;	// �n���h��
	int loopPos;	// ���[�v�ʒu
	bool loopFlg;	// ���[�v�t���O
	bool seFlg;	// ���ʉ��t���O
protected:
	Sound(){}
	~Sound(){}
	Sound(const Sound&){}
	Sound& operator=(const Sound&);
	static Sound* Create(string path = "", bool loopFlg = false, int loopPos = 0, bool seFlg = false);	// ���y�쐬
public:
	void SetLoopFlg(bool loopFlg);	// ���[�v�̉ۂ�ݒ�
	void SetLoopPos(int loopPos);	// ���[�v�ʒu��ݒ�mms�n
	virtual void Play(int playPos = -1);	// �Đ��i�P��[ms]�j�i�����ȗ��Ō��݂̍Đ��ʒu����ĊJ�j
	void Stop(bool stayFlg = false);	// ��~�i�Đ��ʒu���ێ�����ꍇ��stayFlg��true�j
	bool IsPlaying();	// �Đ����ł��邩���ׂ�
	int GetPlayPos();	// �Đ��ʒu���擾
	void SetPan(int pan = 0);	// �p���ݒ�i-10000�`10000�j
	void SetVolume(int volume = 255);	// ���ʐݒ�i0�`255�j
	void SetSpeed(int speed = 100);	// �����ݒ�[��]�i100KHz�𒴂��鑬���i�T���v�����O���g��44100Hz����226���܂Łj�ɂ͂ł��Ȃ��j
	void SetFrequency(int frequency = -1);	// �Đ����g���ݒ�[Hz]

	static Sound* CreateBGM(string path = "", int loopPos = 0);
	static Sound* CreateSE(string path = "");
	static void Delete(Sound* sound);	// ���y�폜
};
