#pragma once
#include "includes.h"
#include "Graphic.h"

// スクリーンクラス
class Screen{
public:

	// サイズを指定してスクリーン生成
	static Screen* Create(Vector2 size);

	// スクリーン削除
	static void Delete(Screen* screen);

	// 描画先の画面をコピーしたものをスクリーンとして生成
	static Screen* CreateByDisplay(Vector2 first, Vector2 last);

	// 描画命令を入れるとスクリーンに投影される
	virtual void Draw(function<void()> func);

	// グラフィックハンドル取得
	GraphicHandle GetHandle();

	// 画面を完全クリア
	void Clear();

private:
	Screen() {}
	virtual ~Screen() {}
	Screen(const Screen&) {}
	const Screen& operator=(const Screen&) {}

	// スクリーンのグラフィックハンドル
	GraphicHandle gh;

	// 各レベルごとのハンドルスタック
	static stack<int> handleStack;

	// ハンドルスタックのトップのハンドルを描画先に設定
	void SetDrawScreenByHandleStack();
};
