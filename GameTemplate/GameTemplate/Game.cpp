#include "Game.h"

Game::Game(){
}

Game::~Game(){
}

void Game::Play(){
	sm.Update();
	sm.Draw();
}

bool Game::Exit(){
	return sm.GetExitFlg();
}
