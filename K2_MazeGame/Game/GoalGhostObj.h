#pragma once

//ゴーストオブジェクトを使用するには、ファイルをインクルードする必要がある。
#include"physics/PhysicsGhostObject.h"

class GoalGhostObj :public IGameObject
{
public:
	bool Start();
	void Update();

	PhysicsGhostObject m_goalGhostObj;
};

