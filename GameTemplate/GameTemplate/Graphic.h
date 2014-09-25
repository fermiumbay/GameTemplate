#pragma once
#include "common.h"
#include "ContentBase.h"

// グラフィック素材クラス
class Graphic : public ContentBase{
	int width;	// 画像横サイズ（分割時は分割された単体のサイズ）
	int height;	// 画像縦サイズ（分割時は分割された単体のサイズ）
	int divNumX;	// 分割数X
	int divNumY;	// 分割数Y
	bool divType;	// 分割タイプ
	bool centerPosFlg;	// 座標を中心座標で指定
	int color_red;	// 色調赤
	int color_green;	// 色調緑
	int color_blue;	// 色調青
	bool handleNotDeleteFlg;	// 既存ハンドルを使用しているため、消滅時にハンドルを破棄しないフラグ
public:
	Graphic();
	Graphic(const TCHAR *path, Vector2 pos = Vector2(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2 zoom = Vector2(100, 100), double angle = 0.0);	// 単体読み込み
	Graphic(const TCHAR *path, Vector2 oneSize, Vector2 divNum, Vector2 pos = Vector2(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2 zoom = Vector2(100, 100), double angle = 0.0);	// 分割読み込み
	Graphic(int *handle, Vector2 pos = Vector2(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2 zoom = Vector2(100, 100), double angle = 0.0);	// 単体読み込み（既存ハンドルの使用）
	Graphic(int *handle, Vector2 oneSize, Vector2 divNum, Vector2 pos = Vector2(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2 zoom = Vector2(100, 100), double angle = 0.0);	// 分割読み込み（既存ハンドルの使用）
	~Graphic();	// 削除
	void Draw(int number = 0, Vector2 addPos = Vector2());	// 描画（分割時は画像番号を指定）
	Vector2 pos;	// 表示座標
	int fade;	// 不透明度（0～256）
	double angle;	// 回転角度（反時計回り）[rad]
	bool trans;	// 透明色あり
	bool turnFlg;	// 左右反転あり
	int GetWidth();	// 横サイズ取得
	int GetHeight();	// 縦サイズ取得
	Vector2 zoom;	// 拡大率[％]（横と縦）
	void SetZoom(Vector2 zoom);	// 拡大率を設定（横と縦の比率を別々に）
	void SetZoom(int zoom = 100);	// 拡大率を設定
	void SetColor(int red = 0, int green = 0, int blue = 0);	// 色調設定
	inline void SetDefaultColor();	// 色調を元に戻す（白）
};
