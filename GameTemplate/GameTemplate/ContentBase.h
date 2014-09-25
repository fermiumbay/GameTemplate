#pragma once
#include "DxLib.h"

// 素材クラス
class ContentBase{
protected:
	int *handle;	// ハンドルポインタ
public:
	ContentBase();
	virtual ~ContentBase() = 0;
};
