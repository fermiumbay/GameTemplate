#include "Game.h"

// メイン処理
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);	// メモリリーク検出

	//初期処理（エラー発生すると終了）
	if (SetWindowIconID(101) != 0){ return 0; }	// アイコン画像の埋め込み
	if (SetOutApplicationLogValidFlag(false) != 0){ return 0; }	// ログ出力を禁止する
	if (SetGraphMode(InfoData::WindowSize().x, InfoData::WindowSize().y, InfoData::WindowColorBitNum()) != 0){ return 0; }	// 解像度の設定
	if (SetMainWindowText(InfoData::GameTitle().c_str())){ return 0; }	// タイトルバーの初期テキストを決定
	if (ChangeWindowMode(InfoData::WindowMode()) != 0){ return 0; }	//ウィンドウモードに設定
	if (DxLib_Init() != 0){ return 0; }	//DXライブラリ初期化処理
	if (SetDrawScreen(DX_SCREEN_BACK) != 0){ return 0; }	//描画先を裏画面に設定
	if (SetChangeScreenModeGraphicsSystemResetFlag(false)){ return 0; }	// スクリーンモード変更による画像関係の設定初期化を禁止

	Random::DefaultRand();	// 乱数の初期化
	CommonData::Initialize();	// データの初期化
	KeyInput::Initialize();	// キー入力の初期化
	Game game;	// ゲームオブジェクト
	
	//繰り返し処理（エラー発生すると終了）
	do{
		if(ScreenFlip() != 0){break;}	//裏画面を表画面に反映
		if(ProcessMessage() != 0){break;}	//Windowsとの同期
		if(ClearDrawScreen() != 0){break;}	//画面を消去
		game.Play();	// ゲーム処理の実行
	}while(!game.Exit());	// ゲームの終了

	CommonData::Finalize();	// 共通データの終了処理
    DxLib_End();    // DXライブラリ終了処理
    return 0;
}
