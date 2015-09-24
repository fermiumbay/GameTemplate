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

	// �Z�[�u�Ɋ܂߂�f�[�^
	static SaveData saveData;

	// �Z�[�u�Ɋ܂߂Ȃ��f�[�^
	static UnSaveData unSaveData;

	// �f�[�^�̏������i����������true�j
	static bool Initialize();

	// �f�[�^�̏I�������i����������true�j
	static bool Finalize();

	// �f�[�^�̃Z�[�u�i����������true�j
	static bool Save(string path);

	// �f�[�^�̃��[�h�i����������true�j
	static bool Load(string path);
};
