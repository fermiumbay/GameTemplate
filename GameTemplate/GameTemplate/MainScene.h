#pragma once
#include "BaseScene.h"

// �Q�[����ʃN���X
class MainScene : public BaseScene{
	bool reverseFlg;	// ���]�t���O
	void SetKeys();	// �L�[�̔�������̃Z�b�g
public:
	MainScene();	// �R���X�g���N�^
	~MainScene();	// �f�X�g���N�^
	void Update() override;	// �X�V
	void Draw() override;	// �`��
};