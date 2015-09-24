#pragma once
#include "Scenes.h"

class SceneManager{
public:

	// �R���X�g���N�^
	SceneManager();

	// �f�X�g���N�^
	~SceneManager();

	// �X�V
	void Update();

	// �`��
	void Draw();

	// �Q�[���I���t���O�擾
	bool GetExitFlg();

private:

	// ���݂̃V�[������
	string currentScene;

	// �V�[��
	BaseScene* scene;

	// ���݂̃V�[�������
	void CloseScene();

	// �V�K�V�[����ǂݍ���
	void NewScene();

	// �Q�[���I���t���O
	bool exitFlg;

};
