#pragma once
#include "SceneManager.h"

// �Q�[���N���X
class Game {
public:

	// �R���X�g���N�^
	Game();

	// �f�X�g���N�^
	~Game();

	// �Q�[�����v���C
	void Play();

	// �Q�[������߂�
	bool Exit();
private:

	// �V�[���}�l�[�W���[
	SceneManager sm;

};
