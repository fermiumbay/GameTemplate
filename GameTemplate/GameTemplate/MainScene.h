#pragma once
#include "BaseScene.h"

// �Q�[����ʃN���X
class MainScene : public BaseScene{
	enum State{
		a,
		b,
		c,
	};
	string text;	// �\������e�L�X�g
public:
	MainScene();	// �R���X�g���N�^
	~MainScene();	// �f�X�g���N�^
	void Update() override;	// �X�V
	void Draw() override;	// �`��
};
