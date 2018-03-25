#include "DxLib.h"
#include "KeyInput.h"
#include"SceneMgr.h"
#include"ComonConstant.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	
	int white = GetColor(255, 255, 255);
	
	SceneMgr sceneMgr;
	sceneMgr.Initialize();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		//“ü—ÍXV
		KeyInput::Instace()->Update();
		sceneMgr.Update();
		sceneMgr.Draw();
	}
	DxLib_End();
	return 0;
}

