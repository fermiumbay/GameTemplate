#include "Pin.h"
using namespace common;

Pin::Pin(){
	ChangeState(State::move);
	pic["�҂�"] = Graphic::Create("..\\..\\..\\�҂񂭂肿���\\�҂񂭂肿���\\bossface7.png", common::GetWindowCenter(), true);
	endflg = false;

	pic["�P��"] = Graphic::Create("..\\..\\..\\�҂񂭂肿���\\�҂񂭂肿���\\bossface7.png");
	picd["����"] = Graphic::Create("..\\..\\..\\�҂񂭂肿���\\�҂񂭂肿���\\bossface7.png", Vector2(180 / 3, 180 / 2), Vector2(3, 2));
	pich["�P��"] = Graphic::CreateHandle("..\\..\\..\\�҂񂭂肿���\\�҂񂭂肿���\\bossface7.png");
	picdh["����"] = Graphic::CreateHandle("..\\..\\..\\�҂񂭂肿���\\�҂񂭂肿���\\bossface7.png", Vector2(180 / 3, 180 / 2), Vector2(3, 2));
	pic["�P�̃n���h��"] = Graphic::Create(pich["�P��"]);
	picd["�����n���h��"] = Graphic::Create(picdh["����"]);

	//// �摜�̒u���T���v��
	//DeletePic("�P��");
	//DeletePicd("����");
	//DeletePich("�P��");
	//DeletePicdh("����");
	//DeletePic("�P�̃n���h��");
	//DeletePicd("�����n���h��");
	//pic["�P��"] = Graphic::Create("..\\..\\..\\�҂񂭂肿���\\�҂񂭂肿���\\hface1.png");
	//picd["����"] = Graphic::Create("..\\..\\..\\�҂񂭂肿���\\�҂񂭂肿���\\hface1.png", Vector2(180 / 3, 180 / 2), Vector2(3, 2));
	//pich["�P��"] = Graphic::CreateHandle("..\\..\\..\\�҂񂭂肿���\\�҂񂭂肿���\\hface1.png");
	//picdh["����"] = Graphic::CreateHandle("..\\..\\..\\�҂񂭂肿���\\�҂񂭂肿���\\hface1.png", Vector2(180 / 3, 180 / 2), Vector2(3, 2));
	//pic["�P�̃n���h��"] = Graphic::Create(pich["�P��"]);
	//picd["�����n���h��"] = Graphic::Create(picdh["����"]);

	pic["�P��"]->pos = Vector2d(50, 50);
	pic["�P�̃n���h��"]->pos = Vector2d(50, 200);
	for (int i = 0; i < picd["����"].size(); i++){
		picd["����"][i]->pos = Vector2d(100 + 70 * i, 100);
	}
	for (int i = 0; i < picd["�����n���h��"].size(); i++){
		picd["�����n���h��"][i]->pos = Vector2d(100 + 70 * i, 250);
	}

	//// �t�H���g�̐ݒ�
	//ChangeFont("���C���I");
	//SetFontSize(32);
	//SetFontThickness(2);
	//ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);

	//// �t�H���g�𐶐�
	//fontHandle[0] = CreateFontToHandle("���C���I", 48, 2, DX_FONTTYPE_NORMAL);	// �m�[�}���t�H���g
	//fontHandle[1] = CreateFontToHandle("���C���I", 48, 2, DX_FONTTYPE_EDGE);	// �G�b�W���t�H���g
	//fontHandle[2] = CreateFontToHandle("���C���I", 48, 2, DX_FONTTYPE_ANTIALIASING);	// �A���`�G�C���A�X�t�H���g
	//fontHandle[3] = CreateFontToHandle("���C���I", 48, 2, DX_FONTTYPE_ANTIALIASING_4X4);	// �A���`�G�C���A�X�t�H���g(4x4�T���v�����O)
	//fontHandle[4] = CreateFontToHandle("���C���I", 48, 2, DX_FONTTYPE_ANTIALIASING_8X8);	// �A���`�G�C���A�X�t�H���g(8x8�T���v�����O)
	//fontHandle[5] = CreateFontToHandle("���C���I", 48, 2, DX_FONTTYPE_ANTIALIASING_EDGE);	// �A���`�G�C���A�X���G�b�W�t���t�H���g
	//fontHandle[6] = CreateFontToHandle("���C���I", 48, 2, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);	// �A���`�G�C���A�X���G�b�W�t���t�H���g(4x4�T���v�����O)
	//fontHandle[7] = CreateFontToHandle("���C���I", 48, 2, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);	// �A���`�G�C���A�X���G�b�W�t���t�H���g(8x8�T���v�����O))
	//text2[0] = "�m�[�}���t�H���g";
	//text2[1] = "�G�b�W���t�H���g";
	//text2[2] = "�A���`�G�C���A�X�t�H���g";
	//text2[3] = "�A���`�G�C���A�X�t�H���g(4x4�T���v�����O)";
	//text2[4] = "�A���`�G�C���A�X�t�H���g(8x8�T���v�����O)";
	//text2[5] = "�A���`�G�C���A�X���G�b�W�t���t�H���g";
	//text2[6] = "�A���`�G�C���A�X���G�b�W�t���t�H���g(4x4�T���v�����O)";
	//text2[7] = "�A���`�G�C���A�X���G�b�W�t���t�H���g(8x8�T���v�����O))";

	// �t�H���g���쐬
	font["����1"] = Font::Create("���C���I", Vector2d(50, 50), 48, 2, false, FontType::normal);
	font["����2"] = Font::Create("���C���I", Vector2d(50, 50 + 48), 48, 2, true, FontType::normal);
	font["����3"] = Font::Create("���C���I", Vector2d(50, 50 + 48 * 2), 48, 2, false, FontType::antialiasing);
	font["����4"] = Font::Create("���C���I", Vector2d(50, 50 + 48 * 3), 48, 2, false, FontType::antialiasing_4x4);
	font["����5"] = Font::Create("���C���I", Vector2d(50, 50 + 48 * 4), 48, 2, false, FontType::antialiasing_8x8);
	font["����6"] = Font::Create("���C���I", Vector2d(50, 50 + 48 * 5), 48, 2, true, FontType::antialiasing);
	font["����7"] = Font::Create("���C���I", Vector2d(50, 50 + 48 * 6), 48, 2, true, FontType::antialiasing_4x4);
	font["����8"] = Font::Create("���C���I", Vector2d(50, 50 + 48 * 7), 48, 2, true, FontType::antialiasing_8x8);
	for (int i = 1; i <= 8; i++){
		font["����" + convert<int, string>(i)]->SetColor(0, 64 + 24 * i - 1, 0);
		font["����" + convert<int, string>(i)]->SetEdgeColor(64 + 24 * i - 1, 0, 0);
	}

	sound["BGM"] = Sound::CreateBGM("C:\\Users\\�t�F���~�E���p\\Documents\\Visual Studio 2013\\Projects\\Helmet\\Helmet\\dat\\Sound\\tw029.mp3");
	sound["SE"] = Sound::CreateSE("C:\\Users\\�t�F���~�E���p\\Documents\\Visual Studio 2013\\Projects\\Helmet\\Helmet\\dat\\Sound\\bigshot1.wav");
	sound["BGM"]->Play();
	sound["SE"]->Play();
}

Pin::~Pin(){
}

void Pin::Update(){
	Behavior::Update();
	switch (GetState()){
	case State::move:

		pic["�҂�"]->pos = Vector2d(320.0 + 100.0*cos(0.03*GetStateTime()), 240.0 + 100.0*sin(0.03*GetStateTime()));
		if (KeyInput::GetKey(OK, PushedNow)){
			ChangeState(State::rotate);
		}
		if (KeyInput::GetKey(Cancel, PushedNow)){
			ChangeState(State::end);
		}
		break;
	case State::rotate:
		pic["�҂�"]->angle += 0.03;
		if (KeyInput::GetKey(OK, PushedNow)){
			ChangeState(State::move);
		}
		if (KeyInput::GetKey(Cancel, PushedNow)){
			ChangeState(State::end);
		}
		break;
	case State::end:
		pic["�҂�"]->fade -= 2;
		if (pic["�҂�"]->fade < 0){
			endflg = true;
		}
		break;
	}
}

void Pin::Draw(){
	Behavior::Draw();
	pic["�҂�"]->Draw();
	string text, t;
	switch (GetState()){
	case State::move:
		text = "State:move " + convert<int, string>(GetStateTime());
		break;
	case State::rotate:
		text = "State:rotate " + convert<int, string>(GetStateTime());
		break;
	case State::end:
		text = "State:end " + convert<int, string>(GetStateTime());
		break;
	}
	pic["�P��"]->Draw();
	pic["�P�̃n���h��"]->Draw();
	for (vector<Graphic*>::iterator it = picd["����"].begin(); it != picd["����"].end(); it++){
		(*it)->Draw();
	}
	for (vector<Graphic*>::iterator it = picd["�����n���h��"].begin(); it != picd["�����n���h��"].end(); it++){
		(*it)->Draw();
	}
	//DrawFormatString(50, 200, GetColor(255, 255, 255), text.c_str());
	//for (int i = 0; i < 8; i++){
	//	DrawStringToHandle(50, 50+48*i, text2[i].c_str(), GetColor(255, 255, 255), fontHandle[i], GetColor(0, 0, 255));
	//}
	for (int i = 1; i <= 8; i++){
		font["����" + convert<int, string>(i)]->Print("��������"+convert<int,string>(i), Vector2d(GetStateTime(), 0));
		font["����" + convert<int, string>(i)]->pos++;
	}
	if (GetStateTime() == 120){
		sound["BGM"]->Stop(true);
	}
	if (GetStateTime() == 180){
		sound["BGM"]->Play();
	}
}

bool Pin::GetEndFlg(){
	return endflg;
}
