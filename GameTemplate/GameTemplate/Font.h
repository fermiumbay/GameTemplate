#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include "Color.h"
#include "includes.h"

// �t�H���g�^�C�v
enum FontType{
	normal,	// �ʏ�
	antialiasing,	// �A���`�G�C���A�X�i�W���j
	antialiasing_4x4,	// �A���`�G�C���A�X�i4x4�T���v�����O�j
	antialiasing_8x8,	// �A���`�G�C���A�X�i8x8�T���v�����O�j
};

// �t�H���g�N���X
class Font{
public:

	// �t�H���g���W
	Vector2d pos;

	// �����F�ݒ�
	void SetColor(Color c);

	// �G�b�W�F�ݒ�
	void SetEdgeColor(Color c);

	// �e�L�X�g�\��
	void Print(string text, Vector2d addPos = Vector2d(), Color color = Color::None(), Color edgeColor = Color::None());

	// �t�H���g�쐬
	static Font* Create(string fontName, Vector2d pos = Vector2d(), int size = 16, int thick = 1, bool edgeFlg = false, FontType fontType = FontType::antialiasing);

	// �t�H���g�폜
	static void Delete(Font* font);

private:

	// �n���h��
	int handle;

	// �����F
	Color color;

	// �G�b�W�F
	Color edgeColor;

	Font() {}
	Font(const Font&) {}
	~Font() {}
	Font& operator=(const Font&) {}

};
