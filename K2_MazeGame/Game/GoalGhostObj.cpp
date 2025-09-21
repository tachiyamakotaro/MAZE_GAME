#include "stdafx.h"
#include "GoalGhostObj.h"

namespace
{
	const Vector3 GOAL_GHOST_POS = Vector3(-2300.0f, -200.0f, 3700.0f);
	const float GOAL_GHOST_SCALE =  200.0f;
}

bool GoalGhostObj::Start()
{
	//ゴーストオブジェクトの初期化
	m_goalGhostObj.CreateBox(Vector3(GOAL_GHOST_POS), Quaternion::Identity, Vector3::One * GOAL_GHOST_SCALE);

	return true;
}

void GoalGhostObj::Update()
{
	
}
