#include "Screen.h"

stack<int> Screen::handleStack;

Screen* Screen::Create(Vector2 size) {
	Screen* screen = new Screen();
	int handle = MakeScreen(size.x, size.y, TRUE);
	while (CheckHandleASyncLoad(handle) == TRUE) {
		ProcessMessage();
		Sleep(1);
	}

	screen->gh.handle = new int[1];
	screen->gh.handle[0] = handle;
	screen->gh.divNum = Vector2(1, 1);
	screen->gh.patternNum = Vector2(1, 1);
	return screen;
}

void Screen::Delete(Screen* screen) {
	Graphic::DeleteHandle(screen->gh);
	delete screen;
}

Screen* Screen::CreateByDisplay(Vector2 first, Vector2 last) {
	Screen* screen = Screen::Create(last - first + 1);
	GetDrawScreenGraph((int)first.x, (int)first.y, (int)(last.x + 1), (int)(last.y + 1), *screen->GetHandle().handle);
	return screen;
}

void Screen::Draw(function<void()> func) {
	handleStack.push(*gh.handle);
	SetDrawScreenByHandleStack();
	func();
	handleStack.pop();
	SetDrawScreenByHandleStack();
}

GraphicHandle Screen::GetHandle() {
	return gh;
}

void Screen::Clear() {
	handleStack.push(*gh.handle);
	SetDrawScreenByHandleStack();
	ClearDrawScreen();
	handleStack.pop();
	SetDrawScreenByHandleStack();
}

void Screen::SetDrawScreenByHandleStack() {
	if (handleStack.size() > 0) {
		SetDrawScreen(handleStack.top());
	}
	else {
		SetDrawScreen(DX_SCREEN_BACK);
	}
}
