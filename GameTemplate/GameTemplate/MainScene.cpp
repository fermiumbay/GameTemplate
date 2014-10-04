#include "MainScene.h"
using namespace common;

MainScene::MainScene(){
	font["�e�L�X�g"] = Font::Create("���C���I", Vector2d(10, 10), 32);
	pic["�҂񂭂�"] = Graphic::Create("..\\..\\..\\�҂񂭂肿���\\�҂񂭂肿���\\bossface7.png", common::GetWindowCenter(), true);
	reverseFlg = false;
	SetKeys();
}

MainScene::~MainScene(){
}

void MainScene::Update(){
	BaseScene::Update();

	if (KeyInput::GetKey(Left, HasBePushed)){
		pic["�҂񂭂�"]->pos.x -= 3;
	}
	if (KeyInput::GetKey(Right, HasBePushed)){
		pic["�҂񂭂�"]->pos.x += 3;
	}
	if (KeyInput::GetKey(Up, HasBePushed)){
		pic["�҂񂭂�"]->pos.y -= 3;
	}
	if (KeyInput::GetKey(Down, HasBePushed)){
		pic["�҂񂭂�"]->pos.y += 3;
	}
	if (KeyInput::GetKey(OK, PushedNow)){
		reverseFlg ^= 1;	// ���]
		SetKeys();
	}
}

void MainScene::Draw(){
	BaseScene::Draw();

	pic["�҂񂭂�"]->Draw();

	if (!reverseFlg){
		font["�e�L�X�g"]->Print("�ʏ�");
	}
	else{
		font["�e�L�X�g"]->Print("���]");
	}
}

void MainScene::SetKeys(){
	if (!reverseFlg){
		// �ʏ�
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
		// ���]
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