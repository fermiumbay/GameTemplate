#include "MainScene.h"

MainScene::MainScene(){
	SetFontSize(24);	// 負荷が重いらしいので、頻繁に呼び出さないよう注意
	ChangeFont("メイリオ");	// 負荷が重いらしいので、頻繁に呼び出さないよう注意
	text = "キャンセルキーで終了します";
}

MainScene::~MainScene(){
}

void MainScene::Update(){
	BaseScene::Update();

	if (KeyInput::GetKeyCancel(PushedNow)){
		EndGame();
	}
}

void MainScene::Draw(){
	BaseScene::Draw();

	DrawFormatString(10, 10, GetColor(255, 255, 255), text.c_str());
}
