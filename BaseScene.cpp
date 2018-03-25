#include "BaseScene.h"
#include "DxLib.h"

//コンストラクタ
BaseScene::BaseScene(ISceneChanger* changer) {
	mSceneChanger = changer;
}
