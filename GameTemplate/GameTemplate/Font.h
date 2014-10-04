#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include <string>
#include "Color.h"
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
	Color color;	// �����F
	Color edgeColor;	// �G�b�W�F

	Font(){}
	Font(const Font&){}
	~Font(){}
	Font& operator=(const Font&);
public:
	Vector2d pos;	// �t�H���g���W

	void SetColor(Color c);	// �����F�ݒ�
	void SetEdgeColor(Color c);	// �G�b�W�F�ݒ�
	void Print(string text, Vector2d addPos = Vector2d(), Color color = Color::None(), Color edgeColor = Color::None());	// �e�L�X�g�\��

	static Font* Create(string fontName, Vector2d pos = Vector2d(), int size = 16, int thick = 1, bool edgeFlg = false, FontType fontType = FontType::antialiasing);	// �t�H���g�쐬
	static void Delete(Font* font);	// �t�H���g�폜
};
