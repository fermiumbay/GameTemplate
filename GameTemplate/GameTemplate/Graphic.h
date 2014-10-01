#pragma once
#include "ContentBase.h"
#include "Vector2.h"
#include <string>
#include <math.h>
using namespace std;

// �O���t�B�b�N�f�ރN���X
class Graphic : public ContentBase{
	int width;	// �摜���T�C�Y�i�������͕������ꂽ�P�̂̃T�C�Y�j
	int height;	// �摜�c�T�C�Y�i�������͕������ꂽ�P�̂̃T�C�Y�j
	bool centerPosFlg;	// ���W�𒆐S���W�Ŏw��
	int color_red;	// �F����
	int color_green;	// �F����
	int color_blue;	// �F����
	bool handleNotDeleteFlg;	// �����n���h�����g�p���Ă��邽�߁A���Ŏ��Ƀn���h����j�����Ȃ��t���O
public:
	Graphic();
	Graphic(string path, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �P�̓ǂݍ���
	Graphic(string path, Vector2 oneSize, Vector2 divNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �����ǂݍ���
	Graphic(int *handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �ǂݍ��݁i�����n���h���̎g�p�j
	Graphic(string path, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �������W�I�[�o�[���[�h
	Graphic(string path, Vector2 oneSize, Vector2 divNum, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �������W�I�[�o�[���[�h
	Graphic(int *handle, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �������W�I�[�o�[���[�h
	~Graphic();	// �폜
	void Draw(int number = 0, Vector2d addPos = Vector2d());	// �`��i�������͉摜�ԍ����w��j
	Vector2d pos;	// �\�����W
	int fade;	// �s�����x�i0�`256�j
	double angle;	// ��]�p�x�i�����v���j[rad]
	bool trans;	// �����F����
	bool turnFlg;	// ���E���]����
	int GetWidth();	// ���T�C�Y�擾
	int GetHeight();	// �c�T�C�Y�擾
	Vector2d zoom;	// �g�嗦[��]�i���Əc�j
	void SetZoom(Vector2d zoom);	// �g�嗦��ݒ�i���Əc�̔䗦��ʁX�Ɂj
	void SetZoom(double zoom = 100.0);	// �g�嗦��ݒ�
	void SetColor(int red = 0, int green = 0, int blue = 0);	// �F���ݒ�
	inline void SetDefaultColor();	// �F�������ɖ߂��i���j
	static int* CreateHandle(string path);	// �n���h���ԍ��𐶐�����i�P�̓ǂݍ��݁j
	static int* CreateHandle(string path, Vector2 oneSize, Vector2 divNum);	// �n���h���ԍ��𐶐�����i�����ǂݍ��݁j
	static void DeleteHandle(int* handle);	// �n���h���ԍ����폜����
};
