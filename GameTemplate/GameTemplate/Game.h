#pragma once
#include "SceneManager.h"

// �Q�[���N���X
class Game{
	SceneManager sm;	// �V�[���}�l�[�W���[
public:
	Game();	// �R���X�g���N�^
	~Game();	// �f�X�g���N�^
	void Play();	// �Q�[�����v���C
	bool Exit();	// �Q�[������߂�
};
