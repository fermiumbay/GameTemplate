#pragma once
#include "DxLib.h"

// �f�ރN���X
class ContentBase{
protected:
	int *handle;	// �n���h���|�C���^
public:
	ContentBase();
	virtual ~ContentBase() = 0;
};
