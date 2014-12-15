#pragma once
#include "common.h"

// �Z�[�u���鋤�ʃf�[�^
struct SaveData{
};

// �Z�[�u���Ȃ����ʃf�[�^
struct UnSaveData{
	int gameTime;	// �Q�[���i�s����
};

// ���ʃf�[�^
class CommonData{
public:
	static SaveData saveData;	// �Z�[�u�Ɋ܂߂�f�[�^
	static UnSaveData unSaveData;	// �Z�[�u�Ɋ܂߂Ȃ��f�[�^
	static bool Initialize();	// �f�[�^�̏������i����������true�j
	static bool Finalize();	// �f�[�^�̏I�������i����������true�j
	static bool Save(string path);	// �f�[�^�̃Z�[�u�i����������true�j
	static bool Load(string path);	// �f�[�^�̃��[�h�i����������true�j
};
