#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include <string>
using namespace std;

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
	int color_r;	// 文字色R
	int color_g;	// 文字色G
	int color_b;	// 文字色B
	int edgeColor_r;	// エッジ色R
	int edgeColor_g;	// エッジ色G
	int edgeColor_b;	// エッジ色B

	Font(){}
	Font(const Font&){}
	~Font(){}
	Font& operator=(const Font&);
public:
	Vector2d pos;	// フォント座標

	void SetColor(int r, int g, int b);	// 文字色設定
	void SetEdgeColor(int r, int g, int b);	// エッジ色設定
	void Print(string text, Vector2d addPos = Vector2d());	// テキスト表示

	static Font* Create(string fontName, Vector2d pos = Vector2d(), int size = 16, int thick = 1, bool edgeFlg = false, FontType fontType = FontType::antialiasing);	// フォント作成
	static void Delete(Font* font);	// フォント削除
};
