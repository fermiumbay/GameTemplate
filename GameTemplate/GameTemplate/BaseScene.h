#pragma once
#include "BaseObject.h"

// ���N���X
class BaseScene : public BaseObject{
	int sceneTime;	// �V�[���J�n����̌o�ߎ���
	bool endGameFlg;	// �Q�[���I���t���O
	bool changeSceneFlg;	// �V�[���ύX�t���O
	string changeSceneName;	// �V�[���ύX��̃V�[����
protected:
	int GetSceneTime();	// �V�[���J�n����̌o�ߎ��Ԏ擾
	void EndGame();	// �Q�[�����I������
	void ChangeScene(string name);	// �V�[����ύX����
	Color screenFade;	// ��ʐF��
	void SetFade(Color c);	// �F���ύX
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
