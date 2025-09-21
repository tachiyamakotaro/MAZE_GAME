#pragma once

#include"physics/PhysicsGhostObject.h"

class AppRoachingGhostObj:public IGameObject
{
public:
	bool Start();
	void Update();
	void MakeGhostObj();
	void BreakFlag();
	void BreakSeFlag();
	void BreakSe();

	enum BreakGhostObj {
		breakGhostObj_01,
		breakGhostObj_02,
		breakGhostObj_Not,
	};
	BreakGhostObj m_break = breakGhostObj_Not;
	BreakGhostObj m_prevBreak = breakGhostObj_Not;

	SoundSource* m_breakSe;

	PhysicsGhostObject m_appRoachingGhostObj01;
	PhysicsGhostObject m_appRoachingGhostObj02;

};

