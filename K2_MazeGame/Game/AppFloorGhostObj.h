#pragma once

//�S�[�X�g�I�u�W�F�N�g���g�p����ɂ́A�t�@�C�����C���N���[�h����K�v������B
#include"physics/PhysicsGhostObject.h"

class AppFloorGhostObj :public IGameObject
{
public:
	bool Start();
	void Update();
	PhysicsGhostObject m_appFloorGhostObj01;
};

