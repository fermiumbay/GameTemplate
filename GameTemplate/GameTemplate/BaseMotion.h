#pragma once
#include "Vector2.h"
#include "includes.h"

// 動きを与えるクラスたち
namespace Motion{

	// モーションクラスの基底
	template <class ValueType>
	class BaseMotion{
	public:

		// モーションクラスの基底
		BaseMotion() : time(0), finished(false) {}

		// デストラクタ
		virtual ~BaseMotion(){}

		// 初期化
		void Initialize(){
			time = 0;
			finished = false;
		}

		// 更新
		virtual void Update(){
			time++;
		}

		// 値の取得
		ValueType GetValue(){
			return value;
		}

		static ValueType GetValue() {
			return value;
		}

		// 終了したか
		bool IsFinished(){
			return finished;
		}

	protected:

		// 値
		ValueType value;

		// 経過時間
		int time;

		// 終了した
		void Finished() {
			finished = true;
		};

	private:

		// 動作終了
		bool finished;

		BaseMotion(const BaseMotion&) {}
		BaseMotion& operator=(const BaseMotion&) {}

	};

}
