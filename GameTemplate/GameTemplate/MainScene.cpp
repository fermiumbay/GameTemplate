#include "MainScene.h"

MainScene::MainScene(){
	SetFontSize(24);	// 負荷が重いらしいので、頻繁に呼び出さないよう注意
	ChangeFont("メイリオ");	// 負荷が重いらしいので、頻繁に呼び出さないよう注意
	text = "キャンセルキーで終了します";

	pin = new Pin();
	ChangeState(State::b);
}

MainScene::~MainScene(){
}

void MainScene::Update(){
	BaseScene::Update();

	//if (KeyInput::GetKey(Cancel, PushedNow)){
	//	EndGame();
	//}

	pin->Update();
	if (pin->GetEndFlg()){
		ChangeScene("Main");
	}
	stringstream ss;
	string i;
	ss << GetStateTime();
	ss >> i;
	switch (GetState()){
	case State::a:
		text = "a" + i;
		break;
	case State::b:
		text = "b" + i;
		break;
	case State::c:
		text = "c" + i;
		break;
	}
}

void MainScene::Draw(){
	BaseScene::Draw();

	pin->Draw();
	DrawFormatString(10, 10, GetColor(255, 255, 255), text.c_str());
}
