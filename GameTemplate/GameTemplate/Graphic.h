#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include "Color.h"
#include "includes.h"

// �u�����h���[�h
enum BlendMode {
	alphaBlend = DX_BLENDMODE_ALPHA,	// �A���t�@�u�����h
	addBlend = DX_BLENDMODE_ADD,	// ���Z�u�����h
};

// �O���t�B�b�N�n���h���|�C���^
struct GraphicHandle {

	// �n���h���|�C���^
	int* handle;

	// �����C���X�^���X��
	Vector2 divNum;

	// �����p�^�[����
	Vector2 patternNum;

	GraphicHandle() {}
	GraphicHandle(int* h) : handle(h) {}

};

// �O���t�B�b�N�f�ރN���X
class Graphic {

public:

	// �`��
	void Draw(int id = 0, Vector2d addPos = Vector2d());

	// �\�����W
	Vector2d pos;

	// �s�����x�i0�`256�j
	int fade;

	// ��]�p�x�i�����v���j[rad]
	double angle;

	// �����F����
	bool trans;

	// ���E���]����
	bool turnFlg;

	// �u�����h���[�h
	BlendMode blendMode;

	// �o�C���j�A�`��t���O
	bool bilinearFlg;

	// ���T�C�Y�擾
	int GetWidth();

	// �c�T�C�Y�擾
	int GetHeight();

	// �g�嗦[��]�i���Əc�j
	Vector2d zoom;

	// �g�嗦��ݒ�i���Əc�̔䗦��ʁX�Ɂj
	void SetZoom(Vector2d zoom);

	// �g�嗦��ݒ�
	void SetZoom(double zoom = 100.0);

	// �F���ݒ�
	void SetColor(Color c = Color::Black());

	// �F�������ɖ߂��i���j
	void SetDefaultColor();

	// ���S���W�t���O
	bool GetCenterPosFlg();

	/* ---- �P�̃C���X�^���XCreate ---- */

	// �P�̉摜�ǂݍ��݁i�P�̃C���X�^���X�j
	static Graphic* Create(string path, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blendMode = alphaBlend, bool bilinearFlg = true);

	// �����摜�ǂݍ��݁i�P�̃C���X�^���X�j
	static Graphic* Create(string path, Vector2 oneSize, Vector2 patternNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blendMode = alphaBlend, bool bilinearFlg = true);

	// �P�̃n���h���ǂݍ��݁i�P�̃C���X�^���X�j
	static Graphic* Create(GraphicHandle handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blendMode = alphaBlend, bool bilinearFlg = true);

	// �P�̓ǂݍ��݃n���h���ԍ��𐶐�����i�P�̃C���X�^���X�j
	static GraphicHandle CreateHandle(string path);

	// �����ǂݍ��݃n���h���ԍ��𐶐�����i�P�̃C���X�^���X�j
	static GraphicHandle CreateHandle(string path, Vector2 oneSize, Vector2 patternNum);

	/* ---- �����C���X�^���XCreate ---- */

	// �P�̉摜�ǂݍ��݁i�����C���X�^���X�j
	static vector<Graphic*> CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blendMode = alphaBlend, bool bilinearFlg = true);

	// �����摜�ǂݍ��݁i�����C���X�^���X�j
	static vector<Graphic*> CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2 patternNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blendMode = alphaBlend, bool bilinearFlg = true);

	// �P�̃n���h���ǂݍ��݁i�����C���X�^���X�j
	static vector<Graphic*> CreateDiv(GraphicHandle handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blendMode = alphaBlend, bool bilinearFlg = true);

	// �P�̓ǂݍ��݃n���h���ԍ��𐶐�����i�����C���X�^���X�j
	static GraphicHandle CreateDivHandle(string path, Vector2 oneSize, Vector2 divNum);

	// �����ǂݍ��݃n���h���ԍ��𐶐�����i�����C���X�^���X�j
	static GraphicHandle CreateDivHandle(string path, Vector2 oneSize, Vector2 divNum, Vector2 patternNum);

	/* ---- �폜 ---- */

	// �摜�폜�i�P�̃C���X�^���X�j
	static void Delete(Graphic* graph);

	// �n���h���̎w���摜���폜
	static void Delete(GraphicHandle handle);

	// �摜�폜�i�����C���X�^���X�j
	static void DeleteDiv(vector<Graphic*> graph);

	// �n���h���̂ݍ폜
	static void DeleteHandle(GraphicHandle handle);

private:

	// �摜�n���h���Q
	GraphicHandle gh;

	// �摜���T�C�Y�i�������͕������ꂽ�P�̂̃T�C�Y�j
	int width;

	// �摜�c�T�C�Y�i�������͕������ꂽ�P�̂̃T�C�Y�j
	int height;

	// ���W�𒆐S���W�Ŏw��
	bool centerPosFlg;

	// �F��
	Color color;

	// �n���h���w��ɂ���č쐬���ꂽ�t���O
	bool createByHandleFlg;

	// �l�̃Z�b�g�i�������Ɏg�p�j
	void SetValues(Vector2d pos, int fade, Vector2d zoom, double angle, bool centerPosFlg, bool trans, BlendMode blendMode, bool bilinearFlg);

	Graphic() {}
	Graphic(const Graphic&) {}
	~Graphic() {}
	Graphic& operator=(const Graphic&) {}

};
