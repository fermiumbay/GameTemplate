#pragma once
#include "GameBehavior.h"

class Pin : public GameBehavior{
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

