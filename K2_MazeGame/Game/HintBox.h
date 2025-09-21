#pragma once

class Player;
class Game;

class HintBox:public IGameObject
{
public:
	HintBox();
	~HintBox();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	ModelRender m_modelRender;
	FontRender  m_hintFont;
	Vector3 m_position;
	Vector3 m_scale;
	Quaternion m_rotation;
	bool m_eraceFlag=true;

	Player* m_player;
	Game* m_game;

	/*enum ShowHint {
		showHint_TheEndOfPathWay,
		showHint_SlipFloor,
		showHint_GoDown,
		showHint_NotDis,
	};
	ShowHint m_hint = showHint_NotDis;*/
};

