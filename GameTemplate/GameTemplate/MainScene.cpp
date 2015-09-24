#include "MainScene.h"

MainScene::MainScene() : BaseScene() {
	font["フォント"] = Font::Create("メイリオ", Vector2d(10, 10), 24);
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

	font["フォント"]->Print("キャンセルキーで終了します");
}
