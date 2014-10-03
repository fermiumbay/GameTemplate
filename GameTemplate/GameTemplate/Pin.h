#pragma once
#include "Behavior.h"

class Pin : public Behavior{
	enum State{
		move,
		motions,
		end,
	};
	bool endflg;
	Motion::Wave motion;
	Motion::Curve curve;
public:
	Pin();
	~Pin();
	void Update() override;
	void Draw() override;
	bool GetEndFlg();
};

