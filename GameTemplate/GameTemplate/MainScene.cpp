#include "MainScene.h"

MainScene::MainScene(){
	SetFontSize(24);	// 負荷が重いらしいので、頻繁に呼び出さないよう注意
	ChangeFont("メイリオ");	// 負荷が重いらしいので、頻繁に呼び出さないよう注意
	text = "キャンセルキーで終了します";

	//ChangeState(State::c);
	//switch (GetState()){
	//case State::a:
	//	text = "a";
	//	break;
	//case State::b:
	//	text = "b";
	//	break;
	//case State::c:
	//	text = "c";
	//	break;
	//}
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

	//DrawFormatString(10, 10+GetStateTime(), GetColor(255, 255, 255), text.c_str());
	//if (GetStateTime() > 100){
	//	ChangeState(State::b);
	//}
}
