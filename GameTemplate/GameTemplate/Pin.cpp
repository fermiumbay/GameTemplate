#include "Pin.h"

Pin::Pin(){
	ChangeState(State::move);
	pic["‚Ò‚ñ"] = new Graphic("..\\..\\..\\‚Ò‚ñ‚­‚è‚¿‚á‚ñ\\‚Ò‚ñ‚­‚è‚¿‚á‚ñ\\bossface7.png", common::GetWindowCenter(), true);
	endflg = false;
}

Pin::~Pin(){
}

void Pin::Update(){
	GameBehavior::Update();
	switch (GetState()){
	case State::move:
		pic["‚Ò‚ñ"]->pos = Vector2(static_cast<int>(320.0 + 100.0*cos(0.03*GetStateTime())), static_cast<int>(240.0 + 100.0*sin(0.03*GetStateTime())));
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
	GameBehavior::Draw();
	pic["‚Ò‚ñ"]->Draw();
	string text, t;
	stringstream ss;
	ss << GetStateTime();
	ss >> t;
	switch (GetState()){
	case State::move:
		text = "State:move " + t;
		break;
	case State::rotate:
		text = "State:rotate " + t;
		break;
	case State::end:
		text = "State:end " + t;
		break;
	}
	DrawFormatString(50, 200, GetColor(255, 255, 255), text.c_str());
}

bool Pin::GetEndFlg(){
	return endflg;
}
