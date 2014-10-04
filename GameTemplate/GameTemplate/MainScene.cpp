#include "MainScene.h"
using namespace common;

MainScene::MainScene(){
	font["テキスト"] = Font::Create("メイリオ", Vector2d(10, 10), 32);
	pic["ぴんくり"] = Graphic::Create("..\\..\\..\\ぴんくりちゃん\\ぴんくりちゃん\\bossface7.png", common::GetWindowCenter(), true);
	reverseFlg = false;
	SetKeys();
}

MainScene::~MainScene(){
}

void MainScene::Update(){
	BaseScene::Update();

	if (KeyInput::GetKey(Left, HasBePushed)){
		pic["ぴんくり"]->pos.x -= 3;
	}
	if (KeyInput::GetKey(Right, HasBePushed)){
		pic["ぴんくり"]->pos.x += 3;
	}
	if (KeyInput::GetKey(Up, HasBePushed)){
		pic["ぴんくり"]->pos.y -= 3;
	}
	if (KeyInput::GetKey(Down, HasBePushed)){
		pic["ぴんくり"]->pos.y += 3;
	}
	if (KeyInput::GetKey(OK, PushedNow)){
		reverseFlg ^= 1;	// 反転
		SetKeys();
	}
}

void MainScene::Draw(){
	BaseScene::Draw();

	pic["ぴんくり"]->Draw();

	if (!reverseFlg){
		font["テキスト"]->Print("通常");
	}
	else{
		font["テキスト"]->Print("反転");
	}
}

void MainScene::SetKeys(){
	if (!reverseFlg){
		// 通常
		KeyInput::SetKeyCond(Left, []{
			return CheckHitKey(KEY_INPUT_LEFT) != 0;
		});
		KeyInput::SetKeyCond(Right, []{
			return CheckHitKey(KEY_INPUT_RIGHT) != 0;
		});
		KeyInput::SetKeyCond(Up, []{
			return CheckHitKey(KEY_INPUT_UP) != 0;
		});
		KeyInput::SetKeyCond(Down, []{
			return CheckHitKey(KEY_INPUT_DOWN) != 0;
		});
	}
	else{
		// 反転
		KeyInput::SetKeyCond(Left, []{
			return CheckHitKey(KEY_INPUT_RIGHT) != 0;
		});
		KeyInput::SetKeyCond(Right, []{
			return CheckHitKey(KEY_INPUT_LEFT) != 0;
		});
		KeyInput::SetKeyCond(Up, []{
			return CheckHitKey(KEY_INPUT_DOWN) != 0;
		});
		KeyInput::SetKeyCond(Down, []{
			return CheckHitKey(KEY_INPUT_UP) != 0;
		});
	}
}