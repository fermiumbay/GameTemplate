#include "Pin.h"
using namespace common;

Pin::Pin(){
	ChangeState(State::move);
	pic["‚Ò‚ñ"] = new Graphic("..\\..\\..\\‚Ò‚ñ‚­‚è‚¿‚á‚ñ\\‚Ò‚ñ‚­‚è‚¿‚á‚ñ\\bossface7.png", common::GetWindowCenter(), true);
	endflg = false;
}

Pin::~Pin(){
}

void Pin::Update(){
	Behavior::Update();
	Vector2d vd;
	Vector2 v;
	switch (GetState()){
	case State::move:

		pic["‚Ò‚ñ"]->pos = Vector2d(320.0 + 100.0*cos(0.03*GetStateTime()), 240.0 + 100.0*sin(0.03*GetStateTime()));
		if (KeyInput::GetKey(OK, PushedNow)){
			ChangeState(State::rotate);
		}
		if (KeyInput::GetKey(Cancel, PushedNow)){
			ChangeState(State::end);
		}
		break;
	case State::rotate:
		pic["‚Ò‚ñ"]->angle += 0.03;
		if (KeyInput::GetKey(OK, PushedNow)){
			ChangeState(State::move);
		}
		if (KeyInput::GetKey(Cancel, PushedNow)){
			ChangeState(State::end);
		}
		break;
	case State::end:
		pic["‚Ò‚ñ"]->fade -= 2;
		if (pic["‚Ò‚ñ"]->fade < 0){
			endflg = true;
		}
		break;
	}
}

void Pin::Draw(){
	Behavior::Draw();
	pic["‚Ò‚ñ"]->Draw();
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
	DrawFormatString(50, 200, GetColor(255, 255, 255), text.c_str());
}

bool Pin::GetEndFlg(){
	return endflg;
}
