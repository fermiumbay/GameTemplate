#pragma once
#include "MainScene.h"

// シーン定義
struct Scenes{
	// シーンオブジェクトの受け取り関数
	inline static BaseScene *GetSceneObject(string name){
		BaseScene *ret = NULL;

		// 新規シーンを追加する場合は、ここに命令を追加していく
		if(name == "Main")	ret = new MainScene();

		return ret;
	}
};
