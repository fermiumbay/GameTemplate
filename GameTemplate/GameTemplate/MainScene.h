#pragma once
#include "BaseScene.h"

// �Q�[����ʃN���X
class MainScene : public BaseScene{
public:

	// �R���X�g���N�^
	MainScene();

	// �f�X�g���N�^
	~MainScene();

	// �X�V
	void Update() override;

	// �`��
	void Draw() override;

};
