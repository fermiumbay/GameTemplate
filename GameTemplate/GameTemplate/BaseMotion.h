#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector2.h"

// 動きを与えるクラスたち
namespace Motion{
	// モーションクラスの基底
	template <class ValueType>
	class BaseMotion{
		bool finished;	// 動作終了
		BaseMotion(const BaseMotion&) {}
		BaseMotion& operator=(const BaseMotion&);
	protected:
		ValueType value;	// 値
		int time;	// 経過時間
		void Finished(){
			finished = true;
		};	// 終了した
	public:
		BaseMotion() : time(0), finished(false) {}
		virtual ~BaseMotion(){}
		void Initialize(){
			time = 0;
			finished = false;
		}// 初期化
		virtual void Update(){
			time++;
		}	// 更新
		ValueType GetValue(){
			return value;
		}	// 値の取得
		bool IsFinished(){
			return finished;
		}	// 終了したか
	};
}
