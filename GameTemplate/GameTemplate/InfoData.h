#pragma once
#include <string>
#include "Vector2.h"
using namespace std;

// �Œ���f�[�^�i�Q�[�����ɕω����Ȃ����j
namespace InfoData{
	// �Q�[���^�C�g��
	inline static const string GameTitle(){
		return "�V�K�v���W�F�N�g";
	}

	// �E�B���h�E�T�C�Y
	inline static const Vector2 WindowSize(){
		return Vector2(640, 480);
	}

	// �E�B���h�E�̃J���[�r�b�g��
	inline static const int WindowColorBitNum(){
		return 32;
	}

	// �E�B���h�E���[�h�t���O
	inline static const bool WindowMode(){
		return true;
	}

	// �����V�[������
	inline static const string DefaultScene(){
		return "Main";
	}
};
