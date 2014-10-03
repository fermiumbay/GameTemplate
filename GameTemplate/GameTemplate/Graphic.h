#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include <string>
#include <vector>
#include <math.h>
using namespace std;

// グラフィックハンドルポインタ
struct GraphicHandle{
	int* handle;	// ハンドルポインタ
	Vector2 divNum;	// 分割インスタンス数
	Vector2 patternNum;	// 分割パターン数
	GraphicHandle(){}
	GraphicHandle(int* h) : handle(h){}
};

// グラフィック素材クラス
class Graphic{
	GraphicHandle gh;	// 画像ハンドル群
	int width;	// 画像横サイズ（分割時は分割された単体のサイズ）
	int height;	// 画像縦サイズ（分割時は分割された単体のサイズ）
	bool centerPosFlg;	// 座標を中心座標で指定
	int color_red;	// 色調赤
	int color_green;	// 色調緑
	int color_blue;	// 色調青

	void SetValues(Vector2d pos, int fade, Vector2d zoom, double angle, bool centerPosFlg, bool trans);	// 値のセット（初期化に使用）
	Graphic(){}
	Graphic(const Graphic&) {}
	~Graphic(){}
	Graphic& operator=(const Graphic&);
public:
	void Draw(int id = 0, Vector2d addPos = Vector2d());	// 描画
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

	// 単体画像群
	static Graphic* Create(string path, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 単体画像読み込み（単体インスタンス）
	static Graphic* Create(string path, Vector2 oneSize, Vector2 patternNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 分割画像読み込み（単体インスタンス）
	static Graphic* Create(GraphicHandle handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 単体ハンドル読み込み（単体インスタンス）
	inline static Graphic* Create(string path, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 単体画像読み込み（単体インスタンス）（整数座標）
	inline static Graphic* Create(string path, Vector2 oneSize, Vector2 patternNum, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 分割画像読み込み（単体インスタンス）（整数座標）
	inline static Graphic* Create(GraphicHandle handle, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 単体ハンドル読み込み（単体インスタンス）（整数座標）
	static GraphicHandle CreateHandle(string path);	// 単体読み込みハンドル番号を生成する（単体インスタンス）
	static GraphicHandle CreateHandle(string path, Vector2 oneSize, Vector2 patternNum);	// 分割読み込みハンドル番号を生成する（単体インスタンス）
	static void Delete(Graphic* graph);	// 画像削除（単体インスタンス）
	static void Delete(GraphicHandle handle);	// ハンドルの指す画像を削除（単体インスタンス）

	// 分割画像群
	static vector<Graphic*> CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 単体画像読み込み（分割インスタンス）
	static vector<Graphic*> CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2 patternNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 分割画像読み込み（分割インスタンス）
	static vector<Graphic*> CreateDiv(GraphicHandle handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 単体ハンドル読み込み（分割インスタンス）
	inline static vector<Graphic*> CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 単体画像読み込み（分割インスタンス）（整数座標）
	inline static vector<Graphic*> CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2 patternNum, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 分割画像読み込み（分割インスタンス）（整数座標）
	inline static vector<Graphic*> CreateDiv(GraphicHandle gh, Vector2 pos, bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0);	// 単体ハンドル読み込み（分割インスタンス）（整数座標）
	static GraphicHandle CreateDivHandle(string path, Vector2 oneSize, Vector2 divNum);	// 単体読み込みハンドル番号を生成する（分割インスタンス）
	static GraphicHandle CreateDivHandle(string path, Vector2 oneSize, Vector2 divNum, Vector2 patternNum);	// 分割読み込みハンドル番号を生成する（分割インスタンス）
	static void DeleteDiv(vector<Graphic*> graph);	// 画像削除（分割インスタンス）
	static void DeleteDiv(GraphicHandle handle);	// ハンドルの指す画像を削除（分割インスタンス）

	static void DeleteHandle(GraphicHandle handle);	// ハンドル削除
};
