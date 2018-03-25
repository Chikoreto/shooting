#pragma once

//タスククラス
class Task {
public:
	virtual ~Task() {}				//デストラクタ
	virtual void Initialize() {}	//初期化
	virtual void Finalize() {}		//終了処理
	virtual void Update() {}		//更新
	virtual void Draw() {}			//描画
};