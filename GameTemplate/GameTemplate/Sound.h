#pragma once
#include "common.h"
#include "ContentBase.h"

// �T�E���h�f�ރN���X
class Sound : public ContentBase{
	int loopPos;
	bool loopFlg;
public:
	Sound(const TCHAR *path = "", bool loopFlg = false, int loopPos = 0);
	~Sound();
	void SetLoopFlg(bool loopFlg);	// ���[�v�̉ۂ�ݒ�
	void SetLoopPos(int loopPos);	// ���[�v�ʒu��ݒ�mms�n
	virtual void Play(int playPos = -1);	// �Đ��i�P��[ms]�j�i�����ȗ��Ō��݂̍Đ��ʒu����ĊJ�j
	void Stop();	// ��~
	bool IsPlaying();	// �Đ����ł��邩���ׂ�
	int GetPlayPos();	// �Đ��ʒu���擾
	void SetPan(int pan = 0);	// �p���ݒ�i-10000�`10000�j
	void SetVolume(int volume = 255);	// ���ʐݒ�i0�`255�j
	void SetSpeed(int speed = 100);	// �����ݒ�[��]�i100KHz�𒴂��鑬���i�T���v�����O���g��44100Hz����226���܂Łj�ɂ͂ł��Ȃ��j
	void SetFrequency(int frequency = -1);	// �Đ����g���ݒ�[Hz]
};

// BGM�N���X
struct BGM : public Sound{
	BGM(const TCHAR *path = "", int loopPos = 0);
};

// ���ʉ��N���X
struct SE : public Sound{
	SE(const TCHAR *path = "");
	void Play(int playPos) override;	// �Đ��i�P��[ms]�j�i�����ȗ��Œʏ�Đ��j
};
