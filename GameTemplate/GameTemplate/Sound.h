#pragma once
#include "DxLib.h"
#include "includes.h"

// �T�E���h�f�ރN���X
class Sound{
public:

	// ���[�v�̉ۂ�ݒ�
	void SetLoopFlg(bool loopFlg);

	// ���[�v�ʒu��ݒ�mms�n
	void SetLoopPos(int loopPos);

	// �Đ��i�P��[ms]�j�i�����ȗ��Ō��݂̍Đ��ʒu����ĊJ�j
	virtual void Play(int playPos = -1);

	// ��~�i�Đ��ʒu���ێ�����ꍇ��stayFlg��true�j
	void Stop(bool stayFlg = false);

	// �Đ����ł��邩���ׂ�
	bool IsPlaying();

	// �Đ��ʒu���擾
	int GetPlayPos();

	// �p���ݒ�i-10000�`10000�j
	void SetPan(int pan = 0);

	// ���ʐݒ�i0�`255�j
	void SetVolume(int volume = 255);

	// �����ݒ�[��]�i100KHz�𒴂��鑬���i�T���v�����O���g��44100Hz����226���܂Łj�ɂ͂ł��Ȃ��j
	void SetSpeed(int speed = 100);

	// �Đ����g���ݒ�[Hz]
	void SetFrequency(int frequency = -1);

	// BGM�쐬
	static Sound* CreateBGM(string path = "", int loopPos = 0);

	// SE�쐬
	static Sound* CreateSE(string path = "");

	// ���y�폜
	static void Delete(Sound* sound);

protected:

	Sound() {}
	~Sound() {}
	Sound(const Sound&) {}
	Sound& operator=(const Sound&) {}

	// ���y�쐬
	static Sound* Create(string path = "", bool loopFlg = false, int loopPos = 0, bool seFlg = false);

private:

	// �n���h��
	int handle;

	// ���[�v�ʒu
	int loopPos;

	// ���[�v�t���O
	bool loopFlg;

	// ���ʉ��t���O
	bool seFlg;
};
