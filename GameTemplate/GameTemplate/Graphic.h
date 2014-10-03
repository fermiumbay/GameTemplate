#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include <string>
#include <vector>
#include <math.h>
using namespace std;

// �O���t�B�b�N�n���h���|�C���^
struct GraphicHandle{
	int* handle;	// �n���h���|�C���^
	Vector2 divNum;	// �����C���X�^���X��
	Vector2 patternNum;	// �����p�^�[����
	GraphicHandle(){}
	GraphicHandle(int* h) : handle(h){}
};

// �O���t�B�b�N�f�ރN���X
class Graphic{
	GraphicHandle gh;	// �摜�n���h���Q
	int width;	// �摜���T�C�Y�i�������͕������ꂽ�P�̂̃T�C�Y�j
	int height;	// �摜�c�T�C�Y�i�������͕������ꂽ�P�̂̃T�C�Y�j
	bool centerPosFlg;	// ���W�𒆐S���W�Ŏw��
	int color_red;	// �F����
	int color_green;	// �F����
	int color_blue;	// �F����

	void SetValues(Vector2d pos, int fade, Vector2d zoom, double angle, bool centerPosFlg, bool trans);	// �l�̃Z�b�g�i�������Ɏg�p�j
	Graphic(){}
	Graphic(const Graphic&) {}
	~Graphic(){}
	Graphic& operator=(const Graphic&);
public:
	void Draw(int id = 0, Vector2d addPos = Vector2d());	// �`��
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

	// �P�̉摜�Q
	static Graphic* Create(string path, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �P�̉摜�ǂݍ��݁i�P�̃C���X�^���X�j
	static Graphic* Create(string path, Vector2 oneSize, Vector2 patternNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �����摜�ǂݍ��݁i�P�̃C���X�^���X�j
	static Graphic* Create(GraphicHandle handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �P�̃n���h���ǂݍ��݁i�P�̃C���X�^���X�j
	inline static Graphic* Create(string path, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �P�̉摜�ǂݍ��݁i�P�̃C���X�^���X�j�i�������W�j
	inline static Graphic* Create(string path, Vector2 oneSize, Vector2 patternNum, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �����摜�ǂݍ��݁i�P�̃C���X�^���X�j�i�������W�j
	inline static Graphic* Create(GraphicHandle handle, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �P�̃n���h���ǂݍ��݁i�P�̃C���X�^���X�j�i�������W�j
	static GraphicHandle CreateHandle(string path);	// �P�̓ǂݍ��݃n���h���ԍ��𐶐�����i�P�̃C���X�^���X�j
	static GraphicHandle CreateHandle(string path, Vector2 oneSize, Vector2 patternNum);	// �����ǂݍ��݃n���h���ԍ��𐶐�����i�P�̃C���X�^���X�j
	static void Delete(Graphic* graph);	// �摜�폜�i�P�̃C���X�^���X�j
	static void Delete(GraphicHandle handle);	// �n���h���̎w���摜���폜�i�P�̃C���X�^���X�j

	// �����摜�Q
	static vector<Graphic*> CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �P�̉摜�ǂݍ��݁i�����C���X�^���X�j
	static vector<Graphic*> CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2 patternNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �����摜�ǂݍ��݁i�����C���X�^���X�j
	static vector<Graphic*> CreateDiv(GraphicHandle handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �P�̃n���h���ǂݍ��݁i�����C���X�^���X�j
	inline static vector<Graphic*> CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �P�̉摜�ǂݍ��݁i�����C���X�^���X�j�i�������W�j
	inline static vector<Graphic*> CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2 patternNum, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �����摜�ǂݍ��݁i�����C���X�^���X�j�i�������W�j
	inline static vector<Graphic*> CreateDiv(GraphicHandle gh, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// �P�̃n���h���ǂݍ��݁i�����C���X�^���X�j�i�������W�j
	static GraphicHandle CreateDivHandle(string path, Vector2 oneSize, Vector2 divNum);	// �P�̓ǂݍ��݃n���h���ԍ��𐶐�����i�����C���X�^���X�j
	static GraphicHandle CreateDivHandle(string path, Vector2 oneSize, Vector2 divNum, Vector2 patternNum);	// �����ǂݍ��݃n���h���ԍ��𐶐�����i�����C���X�^���X�j
	static void DeleteDiv(vector<Graphic*> graph);	// �摜�폜�i�����C���X�^���X�j
	static void DeleteDiv(GraphicHandle handle);	// �n���h���̎w���摜���폜�i�����C���X�^���X�j

	static void DeleteHandle(GraphicHandle handle);	// �n���h���폜
};
