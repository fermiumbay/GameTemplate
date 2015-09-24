#pragma once
#include "BaseMotion.h"

// モーションを設定する
namespace Motion{

	// 二次曲線
	class Curve : public BaseMotion<double> {
	public:

		// 二次曲線
		Curve() : BaseMotion<double>() {}

		// 初期化
		void Initialize(Vector2d vertexPos);

		// 更新
		void Update() override;

		// 頂点通った
		bool PassedVertex();

	private:

		// 終了する時間
		int finishTime;

		// 定数(a(x-p)^2+q)
		double a, p, q;

	};

	// 減衰振動
	class Wave : public BaseMotion<double> {
	public:

		// 減衰振動
		Wave() : BaseMotion<double>() {}

		// 初期化
		void Initialize(double setValue, double a, double b, double c, double d);

		// 更新
		void Update() override;

	private:

		// 終了する時間
		int finishTime;

		// 終了しないフラグ
		bool neverfinishFlg;

		// 収束する値
		double setValue;

		// 定数（ae^(-bt)sin(ct+d)）
		double a, b, c, d;

	};

}
