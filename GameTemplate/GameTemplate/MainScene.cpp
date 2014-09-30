#include "MainScene.h"

MainScene::MainScene(){
	SetFontSize(24);	// ���ׂ��d���炵���̂ŁA�p�ɂɌĂяo���Ȃ��悤����
	ChangeFont("���C���I");	// ���ׂ��d���炵���̂ŁA�p�ɂɌĂяo���Ȃ��悤����
	text = "�L�����Z���L�[�ŏI�����܂�";

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
