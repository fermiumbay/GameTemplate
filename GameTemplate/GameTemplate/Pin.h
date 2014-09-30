#pragma once
#include "Behavior.h"

class Pin : public Behavior{
	enum State{
		move,
		rotate,
		end,
	};
	bool endflg;
public:
	Pin();
	~Pin();
	void Update() override;
	void Draw() override;
	bool GetEndFlg();
};

