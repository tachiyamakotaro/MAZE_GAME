#pragma once

#include"physics/PhysicsGhostObject.h"

class HintGhostObj:public IGameObject
{
public:
	HintGhostObj();
	~HintGhostObj();
	bool Start();
	void Update();
	void MakeGhostObj();
	void HintFont();
	void HintSeFlag();
	void HintSe();
	void Render(RenderContext& rc);

	FontRender  m_hintFont;
	float m_hintAlpha=1.0f;

	SoundSource* m_hintSe;

	PhysicsGhostObject m_hintGhostObject01;
	PhysicsGhostObject m_hintGhostObject02;
	PhysicsGhostObject m_hintGhostObject03;
	PhysicsGhostObject m_hintGhostObject04;
	PhysicsGhostObject m_hintGhostObject05;

	enum ShowHint {
		showHint_TheEndOfPathWay,
		showHint_SlipFloor,
		showHint_WallSus,
		showHint_GoDown,
		showHint_Maze,
		showHint_NotDis,
	};
	ShowHint m_hint = showHint_NotDis;
	ShowHint m_prevHint = showHint_NotDis;
};

