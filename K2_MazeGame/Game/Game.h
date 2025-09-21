#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class GameCamera;
class Floor;
class Wall;
class GoalPedestal;
class SlipFloor;
class SlipWall;
class AppFloor;
class AppRoachingWall;
class GoalGhostObj;
class Clear;
class GameOver;
class AppFloorGhostObj;
class WarpGhostObj;
class NothingGhostObj;
class AppRoachingGhostObj;
class HintBox;
class HintGhostObj;

class SoundManager;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void InGameBgm();
	void MakeGoalObj();
	void MakeAppFloorObj();
	void MakeWarpObj();
	void MakeNothingGhost();
	void MakeAppRoachingGhost();
	void MakeHintGhost();
	void NothingFont();
	void GoalFont();
	void GoalFlag();
	void AppFloorFlag();
	void GameOverFlag();
	void WarpFlag();
	void NothingFlag();
	void AppRoachingFlag();
	void ProduceLevel();
	void InitSkyCube();
	void TimeLimit();
	void ShowHint();
	void StartTimer();

private:
	RenderingEngine m_renderingEngine;
	ModelRender m_modelRender;
	FontRender m_fontRender;
	FontRender m_timerFontRender;
	FontRender m_goalFontRender;
	Vector3 m_pos;
	LevelRender m_levelRender;
	bool m_goalFlag = false;
	float m_clearTimer = 0.0f;
	float m_fontAlpha = 1.0f;
	float m_goalFontAlpha = 0.0f;
	/*float m_appRoachingSpeed=100.0f;
	bool  m_appRoachingFlag=false;*/
	float m_startTimer = 3.0f;
	float m_timer = 180.0f;
	

	Player* m_player = nullptr;
	GameCamera* m_gameCamera = nullptr;
	SkyCube* m_skyCube = nullptr;
	GoalGhostObj* m_goalGhostObj = nullptr;
	Clear* m_clear = nullptr;
	GameOver* m_gameOver = nullptr;
	AppFloor* m_appFloor = nullptr;
	AppRoachingWall* m_appRoachingWall = nullptr;
	AppFloorGhostObj* m_appFloorGhostObj = nullptr;
	WarpGhostObj* m_warpGhostObj = nullptr;
	NothingGhostObj* m_nothingGhostObj = nullptr;
	AppRoachingGhostObj* m_appRoachingGhostObj = nullptr;
	HintGhostObj* m_hintGhostObj = nullptr;
	HintBox* m_hintBox = nullptr;
	SoundManager* m_sound = nullptr;
	SoundSource* m_gameBgm=nullptr;
	SoundSource* m_clearSe = nullptr;
	SoundSource* m_breakSe = nullptr;
	SoundSource* m_warpSe = nullptr;

	std::vector<Floor*> m_floors;
	std::vector<Wall*> m_walls;
	std::vector<GoalPedestal*> m_goalPedestals;
	std::vector<SlipFloor*> m_slipFloors;
	std::vector<SlipWall*> m_slipWalls;
	std::vector<AppFloor*> m_appFloors;
	std::vector<AppRoachingWall*> m_appRoachingWalls;
	std::vector<HintBox*> m_hintBoxs;
};

