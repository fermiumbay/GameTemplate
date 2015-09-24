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
	int handle;	// ハンドル
	Color color;	// 文字色
	Color edgeColor;	// エッジ色

	Font(){}
	Font(const Font&){}
	~Font(){}
	Font& operator=(const Font&);
public:
	Vector2d pos;	// フォント座標

	void SetColor(Color c);	// 文字色設定
	void SetEdgeColor(Color c);	// エッジ色設定
	void Print(string text, Vector2d addPos = Vector2d(), Color color = Color::None(), Color edgeColor = Color::None());	// テキスト表示

	static Font* Create(string fontName, Vector2d pos = Vector2d(), int size = 16, int thick = 1, bool edgeFlg = false, FontType fontType = FontType::antialiasing);	// フォント作成
	static void Delete(Font* font);	// フォント削除
};
