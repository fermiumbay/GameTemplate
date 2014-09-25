#pragma once
#include "common.h"
#include "CommonData.h"

// ���N���X
class BaseScene{
	int sceneTime;	// �V�[���J�n����̌o�ߎ���
	bool endGameFlg;	// �Q�[���I���t���O
	bool changeSceneFlg;	// �V�[���ύX�t���O
	string changeSceneName;	// �V�[���ύX��̃V�[����
protected:
	int GetSceneTime();	// �V�[���J�n����̌o�ߎ��Ԏ擾
	void EndGame();	// �Q�[�����I������
	void ChangeScene(string name);	// �V�[����ύX����
	map<string, Graphic*>	pic;	// �摜
	map<string, Sound*>	sound;	// ���y
public:
	BaseScene();
	virtual ~BaseScene() = 0;
	virtual void Update();	// �X�V
	virtual void Draw();	// �`��
	bool GetEndGameFlg();	// �Q�[���I���t���O�擾
	bool GetChangeSceneFlg();	// �V�[���ύX�t���O�擾
	string GetChangeSceneName();	// �V�[���ύX��̃V�[�����擾
};
