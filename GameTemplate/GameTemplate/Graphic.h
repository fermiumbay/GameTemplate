#pragma once
#include "ContentBase.h"
#include "Vector2.h"
#include <string>
#include <math.h>
using namespace std;

// グラフィック素材クラス
class Graphic : public ContentBase{
	int width;	// 画像横サイズ（分割時は分割された単体のサイズ）
	int height;	// 画像縦サイズ（分割時は分割された単体のサイズ）
	bool centerPosFlg;	// 座標を中心座標で指定
	int color_red;	// 色調赤
	int color_green;	// 色調緑
	int color_blue;	// 色調青
	bool handleNotDeleteFlg;	// 既存ハンドルを使用しているため、消滅時にハンドルを破棄しないフラグ
public:
	Graphic();
	Graphic(string path, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 単体読み込み
	Graphic(string path, Vector2 oneSize, Vector2 divNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 分割読み込み
	Graphic(int *handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 読み込み（既存ハンドルの使用）
	Graphic(string path, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 整数座標オーバーロード
	Graphic(string path, Vector2 oneSize, Vector2 divNum, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 整数座標オーバーロード
	Graphic(int *handle, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 整数座標オーバーロード
	~Graphic();	// 削除
	void Draw(int number = 0, Vector2d addPos = Vector2d());	// 描画（分割時は画像番号を指定）
	Vector2d pos;	// 表示座標
	int fade;	// 不透明度（0～256）
	double angle;	// 回転角度（反時計回り）[rad]
	bool trans;	// 透明色あり
	bool turnFlg;	// 左右反転あり
	int GetWidth();	// 横サイズ取得
	int GetHeight();	// 縦サイズ取得
	Vector2d zoom;	// 拡大率[％]（横と縦）
	void SetZoom(Vector2d zoom);	// 拡大率を設定（横と縦の比率を別々に）
	void SetZoom(double zoom = 100.0);	// 拡大率を設定
	void SetColor(int red = 0, int green = 0, int blue = 0);	// 色調設定
	inline void SetDefaultColor();	// 色調を元に戻す（白）
	static int* CreateHandle(string path);	// ハンドル番号を生成する（単体読み込み）
	static int* CreateHandle(string path, Vector2 oneSize, Vector2 divNum);	// ハンドル番号を生成する（分割読み込み）
	static void DeleteHandle(int* handle);	// ハンドル番号を削除する
};
