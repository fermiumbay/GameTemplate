#include "MainScene.h"

MainScene::MainScene(){
	font["テキスト"] = Font::Create("メイリオ", Vector2d(10, 10), 24);
}

MainScene::~MainScene(){
}

void MainScene::Update(){
	BaseScene::Update();

	if (KeyInput::GetKey(Cancel, PushedNow)){
		EndGame();
	}
}

void MainScene::Draw(){
	BaseScene::Draw();

	font["テキスト"]->Print("キャンセルキーで終了します");
}
