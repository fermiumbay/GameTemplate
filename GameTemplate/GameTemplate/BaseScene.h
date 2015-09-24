#pragma once
#include "BaseObject.h"

// �V�[�����N���X
class BaseScene : public BaseObject{
public:

	// �R���X�g���N�^
	BaseScene();

	// �f�X�g���N�^
	virtual ~BaseScene();

	// �X�V
	virtual void Update();

	// �`��
	virtual void Draw();

	// �Q�[���I���t���O�擾
	bool GetEndGameFlg();

	// �V�[���ύX�t���O�擾
	bool GetChangeSceneFlg();

	// �V�[���ύX��̃V�[�����擾
	string GetChangeSceneName();

protected:

	// �V�[���J�n����̌o�ߎ��Ԏ擾
	int GetSceneTime();

	// �Q�[�����I������
	void EndGame();

	// �V�[����ύX����
	void ChangeScene(string name);

	// ��ʐF��
	Color screenFade;

	// �F���ύX
	void SetFade(Color c);

	// �F�������ɖ߂�
	void SetDefaultFade();

private:

	// �V�[���J�n����̌o�ߎ���
	int sceneTime;

	// �Q�[���I���t���O
	bool endGameFlg;

	// �V�[���ύX�t���O
	bool changeSceneFlg;

	// �V�[���ύX��̃V�[����
	string changeSceneName;

};
