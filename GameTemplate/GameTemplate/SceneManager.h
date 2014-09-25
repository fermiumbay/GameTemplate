#pragma once
#include "common.h"
#include "Scenes.h"

class SceneManager{
	string currentScene;	// ���݂̃V�[������
	BaseScene* scene;	// �V�[��
	void CloseScene();	// ���݂̃V�[�������
	void NewScene();	// �V�K�V�[����ǂݍ���
	bool exitFlg;	// �Q�[���I���t���O
public:
	SceneManager();
	~SceneManager();
	void Update();	// �X�V
	void Draw();	// �`��
	bool GetExitFlg();	// �Q�[���I���t���O�擾
};

