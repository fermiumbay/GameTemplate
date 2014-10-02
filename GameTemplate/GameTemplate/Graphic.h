#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include <string>
#include <vector>
#include <math.h>
using namespace std;

// �O���t�B�b�N�n���h��
struct GraphicHandle{
	int handle;
	GraphicHandle(){}
	GraphicHandle(int h) : handle(h){}
};

// �O���t�B�b�N�f�ރN���X
class Graphic{
	GraphicHandle gh;	// �摜�n���h��
	int width;	// �摜���T�C�Y�i�������͕������ꂽ�P�̂̃T�C�Y�j
	int height;	// �摜�c�T�C�Y�i�������͕������ꂽ�P�̂̃T�C�Y�j
	bool centerPosFlg;	// ���W�𒆐S���W�Ŏw��
	int color_red;	// �F����
	int color_green;	// �F����
	int color_blue;	// �F����

	Graphic(){}
	Graphic(const Graphic&) {}
	~Graphic(){}
	Graphic& operator=(const Graphic&);
public:
	void Draw(Vector2d addPos = Vector2d());	// �`��
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

	static Graphic* Create(string path, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �P�̓ǂݍ���
	static vector<Graphic*> Create(string path, Vector2 oneSize, Vector2 divNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �����ǂݍ���
	static Graphic* Create(GraphicHandle handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �P�̃n���h���ǂݍ���
	static vector<Graphic*> Create(GraphicHandle* handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �����n���h���ǂݍ���
	static Graphic* Create(string path, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �P�̓ǂݍ��݁i�������W�j
	static vector<Graphic*> Create(string path, Vector2 oneSize, Vector2 divNum, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �����ǂݍ��݁i�������W�j
	static Graphic* Create(GraphicHandle gh, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �P�̃n���h���ǂݍ��݁i�������W�j
	static vector<Graphic*> Create(GraphicHandle* gh, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �����n���h���ǂݍ��݁i�������W�j
	static GraphicHandle CreateHandle(string path);	// �n���h���ԍ��𐶐�����i�P�̓ǂݍ��݁j
	static GraphicHandle* CreateHandle(string path, Vector2 oneSize, Vector2 divNum);	// �n���h���ԍ��𐶐�����i�����ǂݍ��݁j
	static void Delete(Graphic* graph);	// �P�̉摜�폜
	static void Delete(vector<Graphic*> graph);	// �����摜�폜
	static void Delete(GraphicHandle handle);	// �n���h���̎w���P�̉摜���폜
	static void Delete(GraphicHandle* handle);	// �n���h���̎w�������摜���폜
};
