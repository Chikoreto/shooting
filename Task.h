#pragma once

//�^�X�N�N���X
class Task {
public:
	virtual ~Task() {}				//�f�X�g���N�^
	virtual void Initialize() {}	//������
	virtual void Finalize() {}		//�I������
	virtual void Update() {}		//�X�V
	virtual void Draw() {}			//�`��
};