#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector2.h"

// 動きを与えるクラスたち
namespace Motion{

	// モーションクラスの基底
	class MotionBase{
		bool finished;	// 動作終了
		MotionBase(const MotionBase&) {}
		MotionBase& operator=(const MotionBase&);
	protected:
		double value;	// 値
		int time;	// 経過時間
		void Finished();	// 終了した
	public:
		MotionBase();
		virtual ~MotionBase(){}
		void Initialize();	// 初期化
		virtual void Update();	// 更新
		double GetValue();	// 値の取得
		bool IsFinished();	// 終了したか
	};

	// 二次曲線
	class Curve : public MotionBase{
		int finishTime;	// 終了する時間
		double a, p, q;	// 定数(a(x-p)^2+q)
	public:
		Curve(Vector2d vertexPos);
		void Update() override;
		bool PassedVertex();	// 頂点通った
	};

	// 減衰振動
	class Wave : public MotionBase {
		int finishTime;	// 終了する時間
		bool neverfinishFlg;	// 終了しないフラグ
		double setValue;	// 収束する値
		double a, b, c, d;	// 定数（ae^(-bt)sin(ct+d)）
	public:
		Wave(double setValue, double a, double b, double c, double d);
		void Update() override;
	};
}
