#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include <string>
using namespace std;

// �t�H���g�^�C�v
enum FontType{
	normal,	// �ʏ�
	antialiasing,	// �A���`�G�C���A�X�i�W���j
	antialiasing_4x4,	// �A���`�G�C���A�X�i4x4�T���v�����O�j
	antialiasing_8x8,	// �A���`�G�C���A�X�i8x8�T���v�����O�j
};

// �t�H���g�N���X
class Font{
	int handle;	// �n���h��
	int color_r;	// �����FR
	int color_g;	// �����FG
	int color_b;	// �����FB
	int edgeColor_r;	// �G�b�W�FR
	int edgeColor_g;	// �G�b�W�FG
	int edgeColor_b;	// �G�b�W�FB

	Font(){}
	Font(const Font&){}
	~Font(){}
	Font& operator=(const Font&);
public:
	Vector2d pos;	// �t�H���g���W

	void SetColor(int r, int g, int b);	// �����F�ݒ�
	void SetEdgeColor(int r, int g, int b);	// �G�b�W�F�ݒ�
	void Print(string text, Vector2d addPos = Vector2d());	// �e�L�X�g�\��

	static Font* Create(string fontName, Vector2d pos = Vector2d(), int size = 16, int thick = 1, bool edgeFlg = false, FontType fontType = FontType::antialiasing);	// �t�H���g�쐬
	static void Delete(Font* font);	// �t�H���g�폜
};
