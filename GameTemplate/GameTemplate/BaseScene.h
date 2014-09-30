#pragma once
#include "GameBehavior.h"
#include "CommonData.h"

// ���N���X
class BaseScene : public GameBehavior{
	int sceneTime;	// �V�[���J�n����̌o�ߎ���
	bool endGameFlg;	// �Q�[���I���t���O
	bool changeSceneFlg;	// �V�[���ύX�t���O
	string changeSceneName;	// �V�[���ύX��̃V�[����
protected:
	int GetSceneTime();	// �V�[���J�n����̌o�ߎ��Ԏ擾
	void EndGame();	// �Q�[�����I������
	void ChangeScene(string name);	// �V�[����ύX����
	int fade_r, fade_g, fade_b;	// ��ʐF��
	void SetFade(int r, int g, int b);	// �F���ύX
	void SetDefaultFade();	// �F�������ɖ߂�
public:
	BaseScene();
	virtual ~BaseScene();
	virtual void Update();	// �X�V
	virtual void Draw();	// �`��
	bool GetEndGameFlg();	// �Q�[���I���t���O�擾
	bool GetChangeSceneFlg();	// �V�[���ύX�t���O�擾
	string GetChangeSceneName();	// �V�[���ύX��̃V�[�����擾
};
