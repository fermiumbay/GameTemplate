#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include <string>
#include <vector>
#include <math.h>
using namespace std;

// グラフィックハンドル
struct GraphicHandle{
	int handle;
	GraphicHandle(){}
	GraphicHandle(int h) : handle(h){}
};

// グラフィック素材クラス
class Graphic{
	GraphicHandle gh;	// 画像ハンドル
	int width;	// 画像横サイズ（分割時は分割された単体のサイズ）
	int height;	// 画像縦サイズ（分割時は分割された単体のサイズ）
	bool centerPosFlg;	// 座標を中心座標で指定
	int color_red;	// 色調赤
	int color_green;	// 色調緑
	int color_blue;	// 色調青

	Graphic(){}
	Graphic(const Graphic&) {}
	~Graphic(){}
	Graphic& operator=(const Graphic&);
public:
	void Draw(Vector2d addPos = Vector2d());	// 描画
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

	static Graphic* Create(string path, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 単体読み込み
	static vector<Graphic*> Create(string path, Vector2 oneSize, Vector2 divNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 分割読み込み
	static Graphic* Create(GraphicHandle handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 単体ハンドル読み込み
	static vector<Graphic*> Create(GraphicHandle* handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 分割ハンドル読み込み
	static Graphic* Create(string path, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 単体読み込み（整数座標）
	static vector<Graphic*> Create(string path, Vector2 oneSize, Vector2 divNum, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 分割読み込み（整数座標）
	static Graphic* Create(GraphicHandle gh, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 単体ハンドル読み込み（整数座標）
	static vector<Graphic*> Create(GraphicHandle* gh, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 分割ハンドル読み込み（整数座標）
	static GraphicHandle CreateHandle(string path);	// ハンドル番号を生成する（単体読み込み）
	static GraphicHandle* CreateHandle(string path, Vector2 oneSize, Vector2 divNum);	// ハンドル番号を生成する（分割読み込み）
	static void Delete(Graphic* graph);	// 単体画像削除
	static void Delete(vector<Graphic*> graph);	// 分割画像削除
	static void Delete(GraphicHandle handle);	// ハンドルの指す単体画像を削除
	static void Delete(GraphicHandle* handle);	// ハンドルの指す分割画像を削除
};
