#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class GameCamera;
class Title;
class Wall;

class Clear :public IGameObject
{
public:
	Clear();
	~Clear();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void ClearPlayerSet();
	void ClearCameraSet();
	void ClearBgm();
	void ProduceLevel();
	void FontSet();
	void FontFade();
	void TitleBack();

private:
	//SpriteRender m_spriteRender;
	LevelRender m_levelRender;
	ModelRender m_modelRender;
	FontRender m_clearFontRender;
	FontRender m_titleBackFontRender;
	float m_fontAlpha = 0.0f;
	float m_titleFontAlpha = 0.0f;

	Player* m_player = nullptr;
	GameCamera* m_gameCamera = nullptr;
	Title* m_title = nullptr;
	SoundSource* m_clearBgm=nullptr;

	std::vector<Wall*> m_walls;
};