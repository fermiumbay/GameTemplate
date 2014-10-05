#pragma once
#include "BaseMotion.h"

// モーションを設定する
namespace Motion{
	// 二次曲線
	class Curve : public BaseMotion<double>{
		int finishTime;	// 終了する時間
		double a, p, q;	// 定数(a(x-p)^2+q)
	public:
		Curve(Vector2d vertexPos);
		void Update() override;
		bool PassedVertex();	// 頂点通った
	};

	// 減衰振動
	class Wave : public BaseMotion<double>{
		int finishTime;	// 終了する時間
		bool neverfinishFlg;	// 終了しないフラグ
		double setValue;	// 収束する値
		double a, b, c, d;	// 定数（ae^(-bt)sin(ct+d)）
	public:
		Wave(double setValue, double a, double b, double c, double d);
		void Update() override;
	};
}
