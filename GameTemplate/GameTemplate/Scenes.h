#pragma once
#include "MainScene.h"

// �V�[����`
struct Scenes{
	// �V�[���I�u�W�F�N�g�̎󂯎��֐�
	inline static BaseScene *GetSceneObject(string name){
		BaseScene *ret = NULL;

		// �V�K�V�[����ǉ�����ꍇ�́A�����ɖ��߂�ǉ����Ă���
		if(name == "Main")	ret = new MainScene();

		return ret;
	}
};
