#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include "Color.h"
#include "includes.h"

// ブレンドモード
enum BlendMode {
	alphaBlend = DX_BLENDMODE_ALPHA,	// アルファブレンド
	addBlend = DX_BLENDMODE_ADD,	// 加算ブレンド
};

// グラフィックハンドルポインタ
struct GraphicHandle {

	// ハンドルポインタ
	int* handle;

	// 分割インスタンス数
	Vector2 divNum;

	// 分割パターン数
	Vector2 patternNum;

	GraphicHandle() {}
	GraphicHandle(int* h) : handle(h) {}

};

// グラフィック素材クラス
class Graphic {

public:

	// 描画
	void Draw(int id = 0, Vector2d addPos = Vector2d());

	// 表示座標
	Vector2d pos;

	// 不透明度（0～256）
	int fade;

	// 回転角度（反時計回り）[rad]
	double angle;

	// 透明色あり
	bool trans;

	// 左右反転あり
	bool turnFlg;

	// ブレンドモード
	BlendMode blendMode;

	// バイリニア描画フラグ
	bool bilinearFlg;

	// 横サイズ取得
	int GetWidth();

	// 縦サイズ取得
	int GetHeight();

	// 拡大率[％]（横と縦）
	Vector2d zoom;

	// 拡大率を設定（横と縦の比率を別々に）
	void SetZoom(Vector2d zoom);

	// 拡大率を設定
	void SetZoom(double zoom = 100.0);

	// 色調設定
	void SetColor(Color c = Color::Black());

	// 色調を元に戻す（白）
	void SetDefaultColor();

	// 中心座標フラグ
	bool GetCenterPosFlg();

	/* ---- 単体インスタンスCreate ---- */

	// 単体画像読み込み（単体インスタンス）
	static Graphic* Create(string path, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blendMode = alphaBlend, bool bilinearFlg = true);

	// 分割画像読み込み（単体インスタンス）
	static Graphic* Create(string path, Vector2 oneSize, Vector2 patternNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blendMode = alphaBlend, bool bilinearFlg = true);

	// 単体ハンドル読み込み（単体インスタンス）
	static Graphic* Create(GraphicHandle handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blendMode = alphaBlend, bool bilinearFlg = true);

	// 単体読み込みハンドル番号を生成する（単体インスタンス）
	static GraphicHandle CreateHandle(string path);

	// 分割読み込みハンドル番号を生成する（単体インスタンス）
	static GraphicHandle CreateHandle(string path, Vector2 oneSize, Vector2 patternNum);

	/* ---- 分割インスタンスCreate ---- */

	// 単体画像読み込み（分割インスタンス）
	static vector<Graphic*> CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blendMode = alphaBlend, bool bilinearFlg = true);

	// 分割画像読み込み（分割インスタンス）
	static vector<Graphic*> CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2 patternNum, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blendMode = alphaBlend, bool bilinearFlg = true);

	// 単体ハンドル読み込み（分割インスタンス）
	static vector<Graphic*> CreateDiv(GraphicHandle handle, Vector2d pos = Vector2d(), bool centerPosFlg = false, bool trans = true, int fade = 256, Vector2d zoom = Vector2d(100.0, 100.0), double angle = 0.0, BlendMode blendMode = alphaBlend, bool bilinearFlg = true);

	// 単体読み込みハンドル番号を生成する（分割インスタンス）
	static GraphicHandle CreateDivHandle(string path, Vector2 oneSize, Vector2 divNum);

	// 分割読み込みハンドル番号を生成する（分割インスタンス）
	static GraphicHandle CreateDivHandle(string path, Vector2 oneSize, Vector2 divNum, Vector2 patternNum);

	/* ---- 削除 ---- */

	// 画像削除（単体インスタンス）
	static void Delete(Graphic* graph);

	// ハンドルの指す画像を削除
	static void Delete(GraphicHandle handle);

	// 画像削除（分割インスタンス）
	static void DeleteDiv(vector<Graphic*> graph);

	// ハンドルのみ削除
	static void DeleteHandle(GraphicHandle handle);

private:

	// 画像ハンドル群
	GraphicHandle gh;

	// 画像横サイズ（分割時は分割された単体のサイズ）
	int width;

	// 画像縦サイズ（分割時は分割された単体のサイズ）
	int height;

	// 座標を中心座標で指定
	bool centerPosFlg;

	// 色調
	Color color;

	// ハンドル指定によって作成されたフラグ
	bool createByHandleFlg;

	// 値のセット（初期化に使用）
	void SetValues(Vector2d pos, int fade, Vector2d zoom, double angle, bool centerPosFlg, bool trans, BlendMode blendMode, bool bilinearFlg);

	Graphic() {}
	Graphic(const Graphic&) {}
	~Graphic() {}
	Graphic& operator=(const Graphic&) {}

};
