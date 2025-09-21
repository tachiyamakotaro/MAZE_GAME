#pragma once

#include "level3DRender/LevelRender.h"

class Player;
class GameCamera;
class Title;
class Game;
class GameOverFloor;

class GameOver :public IGameObject
{
public:
	GameOver();
	~GameOver();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void GameOverBGM();
	void ProduceLevel();
	void FontSet();
	void FontFade();
	void RestartOrTitle();

private:
	
	RenderingEngine m_renderingEngine;
	LevelRender m_levelRender;
	ModelRender m_modelRender;
	FontRender m_gameOverFontRender;
	FontRender m_restartFontRender;
	FontRender m_titleBackFontRender;
	float m_fontAlpha = 0.0f;
	float m_restartAndTitleAlpha = 0.0f;

	Player* m_player = nullptr;
	GameCamera* m_gameCamera = nullptr;
	Title* m_title = nullptr;
	Game* m_game = nullptr;
	SoundSource* m_gameOverBgm = nullptr;

	std::vector<GameOverFloor*> m_gameOverFloors;
};

