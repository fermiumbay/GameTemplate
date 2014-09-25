#pragma once
#include "common.h"
#include "ContentBase.h"

// �O���t�B�b�N�f�ރN���X
class Graphic : public ContentBase{
	int width;	// �摜���T�C�Y�i�������͕������ꂽ�P�̂̃T�C�Y�j
	int height;	// �摜�c�T�C�Y�i�������͕������ꂽ�P�̂̃T�C�Y�j
	int divNumX;	// ������X
	int divNumY;	// ������Y
	bool divType;	// �����^�C�v
	bool centerPosFlg;	// ���W�𒆐S���W�Ŏw��
	int color_red;	// �F����
	int color_green;	// �F����
	int color_blue;	// �F����
	bool handleNotDeleteFlg;	// �����n���h�����g�p���Ă��邽�߁A���Ŏ��Ƀn���h����j�����Ȃ��t���O
public:
	Graphic();
	Graphic(const TCHAR *path, Vector2 pos = Vector2(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2 zoom = Vector2(100, 100), double angle = 0.0);	// �P�̓ǂݍ���
	Graphic(const TCHAR *path, Vector2 oneSize, Vector2 divNum, Vector2 pos = Vector2(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2 zoom = Vector2(100, 100), double angle = 0.0);	// �����ǂݍ���
	Graphic(int *handle, Vector2 pos = Vector2(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2 zoom = Vector2(100, 100), double angle = 0.0);	// �P�̓ǂݍ��݁i�����n���h���̎g�p�j
	Graphic(int *handle, Vector2 oneSize, Vector2 divNum, Vector2 pos = Vector2(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2 zoom = Vector2(100, 100), double angle = 0.0);	// �����ǂݍ��݁i�����n���h���̎g�p�j
	~Graphic();	// �폜
	void Draw(int number = 0, Vector2 addPos = Vector2());	// �`��i�������͉摜�ԍ����w��j
	Vector2 pos;	// �\�����W
	int fade;	// �s�����x�i0�`256�j
	double angle;	// ��]�p�x�i�����v���j[rad]
	bool trans;	// �����F����
	bool turnFlg;	// ���E���]����
	int GetWidth();	// ���T�C�Y�擾
	int GetHeight();	// �c�T�C�Y�擾
	Vector2 zoom;	// �g�嗦[��]�i���Əc�j
	void SetZoom(Vector2 zoom);	// �g�嗦��ݒ�i���Əc�̔䗦��ʁX�Ɂj
	void SetZoom(int zoom = 100);	// �g�嗦��ݒ�
	void SetColor(int red = 0, int green = 0, int blue = 0);	// �F���ݒ�
	inline void SetDefaultColor();	// �F�������ɖ߂��i���j
};
