#pragma once
#include "BaseScene.h"

// �Q�[����ʃN���X
class MainScene : public BaseScene{
public:
	MainScene();	// �R���X�g���N�^
	~MainScene();	// �f�X�g���N�^
	void Update() override;	// �X�V
	void Draw() override;	// �`��
};
