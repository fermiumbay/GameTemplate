#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include "Color.h"
#include "includes.h"

// フォントタイプ
enum FontType{
	normal,	// 通常
	antialiasing,	// アンチエイリアス（標準）
	antialiasing_4x4,	// アンチエイリアス（4x4サンプリング）
	antialiasing_8x8,	// アンチエイリアス（8x8サンプリング）
};

// フォントクラス
class Font{
public:

	// フォント座標
	Vector2d pos;

	// 文字色設定
	void SetColor(Color c);

	// エッジ色設定
	void SetEdgeColor(Color c);

	// テキスト表示
	void Print(string text, Vector2d addPos = Vector2d(), Color color = Color::None(), Color edgeColor = Color::None());

	// フォント作成
	static Font* Create(string fontName, Vector2d pos = Vector2d(), int size = 16, int thick = 1, bool edgeFlg = false, FontType fontType = FontType::antialiasing);

	// フォント削除
	static void Delete(Font* font);

private:

	// ハンドル
	int handle;

	// 文字色
	Color color;

	// エッジ色
	Color edgeColor;

	Font() {}
	Font(const Font&) {}
	~Font() {}
	Font& operator=(const Font&) {}

};
