#include "Pin.h"
using namespace common;

Pin::Pin(){
	ChangeState(State::move);
	pic["ぴん"] = Graphic::Create("..\\..\\..\\ぴんくりちゃん\\ぴんくりちゃん\\bossface7.png", common::GetWindowCenter(), true);
	endflg = false;

	pic["単体"] = Graphic::Create("..\\..\\..\\ぴんくりちゃん\\ぴんくりちゃん\\bossface7.png");
	picd["分割"] = Graphic::Create("..\\..\\..\\ぴんくりちゃん\\ぴんくりちゃん\\bossface7.png", Vector2(180 / 3, 180 / 2), Vector2(3, 2));
	pich["単体"] = Graphic::CreateHandle("..\\..\\..\\ぴんくりちゃん\\ぴんくりちゃん\\bossface7.png");
	picdh["分割"] = Graphic::CreateHandle("..\\..\\..\\ぴんくりちゃん\\ぴんくりちゃん\\bossface7.png", Vector2(180 / 3, 180 / 2), Vector2(3, 2));
	pic["単体ハンドル"] = Graphic::Create(pich["単体"]);
	picd["分割ハンドル"] = Graphic::Create(picdh["分割"]);

	//// 画像の置換サンプル
	//DeletePic("単体");
	//DeletePicd("分割");
	//DeletePich("単体");
	//DeletePicdh("分割");
	//DeletePic("単体ハンドル");
	//DeletePicd("分割ハンドル");
	//pic["単体"] = Graphic::Create("..\\..\\..\\ぴんくりちゃん\\ぴんくりちゃん\\hface1.png");
	//picd["分割"] = Graphic::Create("..\\..\\..\\ぴんくりちゃん\\ぴんくりちゃん\\hface1.png", Vector2(180 / 3, 180 / 2), Vector2(3, 2));
	//pich["単体"] = Graphic::CreateHandle("..\\..\\..\\ぴんくりちゃん\\ぴんくりちゃん\\hface1.png");
	//picdh["分割"] = Graphic::CreateHandle("..\\..\\..\\ぴんくりちゃん\\ぴんくりちゃん\\hface1.png", Vector2(180 / 3, 180 / 2), Vector2(3, 2));
	//pic["単体ハンドル"] = Graphic::Create(pich["単体"]);
	//picd["分割ハンドル"] = Graphic::Create(picdh["分割"]);

	pic["単体"]->pos = Vector2d(50, 50);
	pic["単体ハンドル"]->pos = Vector2d(50, 200);
	for (int i = 0; i < picd["分割"].size(); i++){
		picd["分割"][i]->pos = Vector2d(100 + 70 * i, 100);
	}
	for (int i = 0; i < picd["分割ハンドル"].size(); i++){
		picd["分割ハンドル"][i]->pos = Vector2d(100 + 70 * i, 250);
	}

	//// フォントの設定
	//ChangeFont("メイリオ");
	//SetFontSize(32);
	//SetFontThickness(2);
	//ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);

	//// フォントを生成
	//fontHandle[0] = CreateFontToHandle("メイリオ", 48, 2, DX_FONTTYPE_NORMAL);	// ノーマルフォント
	//fontHandle[1] = CreateFontToHandle("メイリオ", 48, 2, DX_FONTTYPE_EDGE);	// エッジつきフォント
	//fontHandle[2] = CreateFontToHandle("メイリオ", 48, 2, DX_FONTTYPE_ANTIALIASING);	// アンチエイリアスフォント
	//fontHandle[3] = CreateFontToHandle("メイリオ", 48, 2, DX_FONTTYPE_ANTIALIASING_4X4);	// アンチエイリアスフォント(4x4サンプリング)
	//fontHandle[4] = CreateFontToHandle("メイリオ", 48, 2, DX_FONTTYPE_ANTIALIASING_8X8);	// アンチエイリアスフォント(8x8サンプリング)
	//fontHandle[5] = CreateFontToHandle("メイリオ", 48, 2, DX_FONTTYPE_ANTIALIASING_EDGE);	// アンチエイリアス＆エッジ付きフォント
	//fontHandle[6] = CreateFontToHandle("メイリオ", 48, 2, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);	// アンチエイリアス＆エッジ付きフォント(4x4サンプリング)
	//fontHandle[7] = CreateFontToHandle("メイリオ", 48, 2, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);	// アンチエイリアス＆エッジ付きフォント(8x8サンプリング))
	//text2[0] = "ノーマルフォント";
	//text2[1] = "エッジつきフォント";
	//text2[2] = "アンチエイリアスフォント";
	//text2[3] = "アンチエイリアスフォント(4x4サンプリング)";
	//text2[4] = "アンチエイリアスフォント(8x8サンプリング)";
	//text2[5] = "アンチエイリアス＆エッジ付きフォント";
	//text2[6] = "アンチエイリアス＆エッジ付きフォント(4x4サンプリング)";
	//text2[7] = "アンチエイリアス＆エッジ付きフォント(8x8サンプリング))";

	// フォントを作成
	font["文字1"] = Font::Create("メイリオ", Vector2d(50, 50), 48, 2, false, FontType::normal);
	font["文字2"] = Font::Create("メイリオ", Vector2d(50, 50 + 48), 48, 2, true, FontType::normal);
	font["文字3"] = Font::Create("メイリオ", Vector2d(50, 50 + 48 * 2), 48, 2, false, FontType::antialiasing);
	font["文字4"] = Font::Create("メイリオ", Vector2d(50, 50 + 48 * 3), 48, 2, false, FontType::antialiasing_4x4);
	font["文字5"] = Font::Create("メイリオ", Vector2d(50, 50 + 48 * 4), 48, 2, false, FontType::antialiasing_8x8);
	font["文字6"] = Font::Create("メイリオ", Vector2d(50, 50 + 48 * 5), 48, 2, true, FontType::antialiasing);
	font["文字7"] = Font::Create("メイリオ", Vector2d(50, 50 + 48 * 6), 48, 2, true, FontType::antialiasing_4x4);
	font["文字8"] = Font::Create("メイリオ", Vector2d(50, 50 + 48 * 7), 48, 2, true, FontType::antialiasing_8x8);
	for (int i = 1; i <= 8; i++){
		font["文字" + convert<int, string>(i)]->SetColor(0, 64 + 24 * i - 1, 0);
		font["文字" + convert<int, string>(i)]->SetEdgeColor(64 + 24 * i - 1, 0, 0);
	}

	sound["BGM"] = Sound::CreateBGM("C:\\Users\\フェルミウム湾\\Documents\\Visual Studio 2013\\Projects\\Helmet\\Helmet\\dat\\Sound\\tw029.mp3");
	sound["SE"] = Sound::CreateSE("C:\\Users\\フェルミウム湾\\Documents\\Visual Studio 2013\\Projects\\Helmet\\Helmet\\dat\\Sound\\bigshot1.wav");
	sound["BGM"]->Play();
	sound["SE"]->Play();
}

Pin::~Pin(){
}

void Pin::Update(){
	Behavior::Update();
	switch (GetState()){
	case State::move:

		pic["ぴん"]->pos = Vector2d(320.0 + 100.0*cos(0.03*GetStateTime()), 240.0 + 100.0*sin(0.03*GetStateTime()));
		if (KeyInput::GetKey(OK, PushedNow)){
			ChangeState(State::rotate);
		}
		if (KeyInput::GetKey(Cancel, PushedNow)){
			ChangeState(State::end);
		}
		break;
	case State::rotate:
		pic["ぴん"]->angle += 0.03;
		if (KeyInput::GetKey(OK, PushedNow)){
			ChangeState(State::move);
		}
		if (KeyInput::GetKey(Cancel, PushedNow)){
			ChangeState(State::end);
		}
		break;
	case State::end:
		pic["ぴん"]->fade -= 2;
		if (pic["ぴん"]->fade < 0){
			endflg = true;
		}
		break;
	}
}

void Pin::Draw(){
	Behavior::Draw();
	pic["ぴん"]->Draw();
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
	pic["単体"]->Draw();
	pic["単体ハンドル"]->Draw();
	for (vector<Graphic*>::iterator it = picd["分割"].begin(); it != picd["分割"].end(); it++){
		(*it)->Draw();
	}
	for (vector<Graphic*>::iterator it = picd["分割ハンドル"].begin(); it != picd["分割ハンドル"].end(); it++){
		(*it)->Draw();
	}
	//DrawFormatString(50, 200, GetColor(255, 255, 255), text.c_str());
	//for (int i = 0; i < 8; i++){
	//	DrawStringToHandle(50, 50+48*i, text2[i].c_str(), GetColor(255, 255, 255), fontHandle[i], GetColor(0, 0, 255));
	//}
	for (int i = 1; i <= 8; i++){
		font["文字" + convert<int, string>(i)]->Print("もじもじ"+convert<int,string>(i), Vector2d(GetStateTime(), 0));
		font["文字" + convert<int, string>(i)]->pos++;
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
