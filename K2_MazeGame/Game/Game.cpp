#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "Floor.h"
#include "Wall.h"
#include "GoalPedestal.h"
#include "AppRoachingWall.h"
#include "SlipFloor.h"
#include "SlipWall.h"
#include "HintBox.h"
#include "GoalGhostObj.h"
#include "HintGhostObj.h"
#include "Clear.h"
#include "GameOver.h"
#include "AppFloor.h"
#include "AppFloorGhostObj.h"
#include "WarpGhostObj.h"
#include "NothingGhostObj.h"
#include "AppRoachingGhostObj.h"

#include "SoundManager.h"

namespace
{
	const float SCREEN_TRANSITION_TIME = 5.0f;
	const float FALLING_DEATH = -2000.0f;
	const Vector3 WARP_POINT01 = Vector3( 0.0f,600.0f,2400.0f );
	const Vector3 WARP_POINT02 = Vector3({ 1000.0f,1000.0f,1000.0f });
	const Vector3 IN_GAME_CAMERA(0.0f, 0.0f, -10.0f);
	const Vector3 FONT_POS = { -300.0f,100.0f,0.0f };
	const float FONT_SCALE = 2.0f;
	const Vector3 TIMER_FONT_POS(300.f, 500.0f, 0.0f);
	const float TIMER_FONT_SCALE(2.0f);
	const Vector3 GOAL_FONT_POS(-400.0f, 100.0f, 0.0f);
	const float GOAL_FONT_SCALE(5.0f);

	const char* LEVEL_INIT = "Assets/level3D/testLevel.tkl";
}

Game::Game()
{

}

Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_gameCamera);
	DeleteGO(m_skyCube);
	DeleteGO(m_goalGhostObj);
	DeleteGO(m_appFloorGhostObj);
	DeleteGO(m_warpGhostObj);
	DeleteGO(m_nothingGhostObj);
	DeleteGO(m_hintGhostObj);
	DeleteGO(m_gameBgm);
	
	for (auto floor : m_floors)
	{
		DeleteGO(floor);
	}

	for (auto wall : m_walls)
	{
		DeleteGO(wall);
	}

	for (auto slipFloor:m_slipFloors)
	{
		DeleteGO(slipFloor);
	}

	for (auto slipWall : m_slipWalls)
	{
		DeleteGO(slipWall);
	}

	for (auto appFloor : m_appFloors)
	{
		DeleteGO(appFloor);
	}

	for (auto appRochingWall : m_appRoachingWalls)
	{
		DeleteGO(appRochingWall);
	}

	for (auto hintBox : m_hintBoxs)
	{
		DeleteGO(hintBox);
	}

	for (auto goalPedestal : m_goalPedestals)
	{
		DeleteGO(goalPedestal);
	}
}

bool Game::Start()
{
	//m_modelRender.Init("Assets/modelData/unityChan.tkm");

	g_renderingEngine->EnableTonemap();
	
	m_player = NewGO<Player>(2,"player");

	m_gameCamera = NewGO<GameCamera>(1,"gameCamera");
	//m_gameCamera->m_cameraPos = m_gameCamera->cameraPos_InGame;

	InGameBgm();

	ProduceLevel();

	InitSkyCube();

	MakeGoalObj();

	MakeAppFloorObj();

	MakeWarpObj();

	MakeNothingGhost();

	NothingFont();

	GoalFont();

	MakeAppRoachingGhost();

	MakeHintGhost();

	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	return true;
}

void Game::InGameBgm()
{
	m_sound = FindGO<SoundManager>("soundManager");
	m_gameBgm = m_sound->PlayingSound(Sound::enSound_InGameBGM);
	m_gameBgm->SetVolume(0.5f);
}

void Game::ProduceLevel()
{
	m_levelRender.Init(LEVEL_INIT, [&](LevelObjectData& objData)
	{
			if (objData.EqualObjectName(L"floor") == true)
			{
				auto floor = NewGO<Floor>(0);
				floor->m_position = objData.position;
				floor->m_rotation = objData.rotation;
				floor->m_scale = objData.scale;
				m_floors.push_back(floor);

				return true;
			}

			if (objData.EqualObjectName(L"wall") == true)
			{
				auto wall = NewGO<Wall>(0);
				wall->m_position = objData.position;
				wall->m_rotation = objData.rotation;
				wall->m_scale = objData.scale;
				m_walls.push_back(wall);
				return true;
			}

			if (objData.EqualObjectName(L"GoalPedestal") == true)
			{
				auto goalpedestal = NewGO<GoalPedestal>(0);
				goalpedestal->m_position = objData.position;
				goalpedestal->m_rotation = objData.rotation;
				goalpedestal->m_scale = objData.scale;
				m_goalPedestals.push_back(goalpedestal);
				return true;
			}

			if (objData.EqualObjectName(L"slipFloor") == true)
			{
				auto slipFloor = NewGO<SlipFloor>(0);
				slipFloor->m_position = objData.position;
				slipFloor->m_rotation = objData.rotation;
				slipFloor->m_scale = objData.scale;
				m_slipFloors.push_back(slipFloor);

				return true;
			}

			if (objData.EqualObjectName(L"slipWall") == true)
			{
				auto slipWall = NewGO<SlipWall>(0);
				slipWall->m_position = objData.position;
				slipWall->m_rotation = objData.rotation;
				slipWall->m_scale = objData.scale;
				m_slipWalls.push_back(slipWall);

				return true;
			}

			if (objData.EqualObjectName(L"testAppFloor") == true)
			{
				auto appFloor = NewGO<AppFloor>(0);
				appFloor->m_position = objData.position;
				appFloor->m_rotation = objData.rotation;
				appFloor->m_scale = objData.scale;
				m_appFloors.push_back(appFloor);
				return true;
			}

			if (objData.EqualObjectName(L"appRoachingWall") == true)
			{
				auto appRoachingWall = NewGO<AppRoachingWall>(0);
				appRoachingWall->m_position = objData.position;
				appRoachingWall->m_rotation = objData.rotation;
				appRoachingWall->m_scale = objData.scale;
				m_appRoachingWalls.push_back(appRoachingWall);
				return true;
			}

			if (objData.EqualObjectName(L"hint") == true)
			{
				auto hintBox = NewGO<HintBox>(0);
				hintBox->m_position = objData.position;
				hintBox->m_rotation = objData.rotation;
				hintBox->m_scale = objData.scale;
				m_hintBoxs.push_back(hintBox);
				return true;
			}

			return false;
	});
}

void Game::InitSkyCube()
{
	m_skyCube = NewGO<SkyCube>(0);
	m_skyCube->SetLuminance(0.2f);
	m_skyCube->SetType(enSkyCubeType_SpaceToon_2);
}

void Game::MakeGoalObj()
{
	m_goalGhostObj = NewGO<GoalGhostObj>(0, "goalGhostObj");
}

void Game::MakeAppFloorObj()
{
	//m_appFloorGhostObj = FindGO<AppFloorGhostObj>("appFloorGhostObj");
	m_appFloorGhostObj = NewGO<AppFloorGhostObj>(0, "appFloorGhostObj");
}

void Game::MakeWarpObj()
{
	m_warpGhostObj = NewGO<WarpGhostObj>(0, "warpGhostObj");

}

void Game::MakeNothingGhost()
{
	m_nothingGhostObj = NewGO<NothingGhostObj>(0, "nothingGhostObj");
}

void Game::NothingFont()
{
	m_fontRender.SetText(L"Ç±Ç±Ç…ÇÕâΩÇ‡Ç»Ç¢ÇÊ");
	m_fontRender.SetPosition({ FONT_POS });
	m_fontRender.SetScale(FONT_SCALE);

}

void Game::GoalFont()
{
	m_goalFontRender.SetText(L"ÉSÅ[ÉãÅI");
	m_goalFontRender.SetPosition({ GOAL_FONT_POS });
	m_goalFontRender.SetScale(GOAL_FONT_SCALE);
}

void Game::MakeAppRoachingGhost()
{
	m_appRoachingGhostObj = NewGO<AppRoachingGhostObj>(0, "appRoachingGhostObj");
}

void Game::MakeHintGhost()
{
	m_hintGhostObj = NewGO<HintGhostObj>(0, "hintGhostObj");
}

void Game::Update()
{
	StartTimer();

	TimeLimit();

	GoalFlag();

	AppFloorFlag();

	GameOverFlag();

	WarpFlag();

	NothingFlag();

	AppRoachingFlag();

	ShowHint();

	m_modelRender.Update();
}

void Game::StartTimer()
{
	//m_startTimer -= g_gameTime->GetFrameDeltaTime();
	///*if (m_gameCamera->m_toCameraPos.z < IN_GAME_CAMERA.z)
	//{
	//	m_gameCamera->m_toCameraPos.z += 1.0f;
	//}*/
	//if (m_startTimer <= 0.0f)
	//{
	//	m_startTimer = 0.0f;
	//	m_gameCamera->m_cameraMoveFlag = true;
	//	
	//}
}

void Game::TimeLimit()
{
	int sec = (int)m_timer;

	if (m_goalFlag != true) 
	{
		m_timer -= g_gameTime->GetFrameDeltaTime();
	}

	wchar_t text[256];
	swprintf_s(text, 256, L"éûä‘êßå¿ÅF%02d", sec);
	m_timerFontRender.SetText(text);
	m_timerFontRender.SetPosition(TIMER_FONT_POS);
	m_timerFontRender.SetScale(TIMER_FONT_SCALE);
	m_timerFontRender.SetColor(g_vec4Yellow);

	if (m_timer <= 0.0f)
	{
		NewGO<GameOver>(0, "gameOver");
		DeleteGO(this);
	}
}

void Game::GoalFlag()
{
	PhysicsWorld::GetInstance()->ContactTest(m_player->m_characterController, [&](const btCollisionObject& contactObject)
	{
		if (m_goalGhostObj->m_goalGhostObj.IsSelf(contactObject) == true)
		{
			//m_gameCamera->m_toCameraPos.Set(0.0f, 150.0f, -150.0f);
		
			m_goalFlag = true;
			m_clearSe = m_sound->PlayingSound(Sound::enSound_GameClearSE);
			m_clearSe->Play(false);
			DeleteGO(m_goalGhostObj);
			DeleteGO(m_gameBgm);
		}
	});

	if (m_goalFlag == true) {
		
		
		m_gameCamera->m_fixedCameraFlag = true;
		m_player->m_moveFlag = true;
		m_player->SetPosition(m_goalPedestals[0]->m_position);
		m_player->m_position.y += 10.0f;
		m_goalFontAlpha = 1.0f;
		m_fontAlpha = 0.0f;
		m_hintGhostObj->m_hint = m_hintGhostObj->showHint_NotDis;
		m_clearTimer += g_gameTime->GetFrameDeltaTime();
		//DeleteGO(this);
		if (m_clearTimer > SCREEN_TRANSITION_TIME)
		{
			DeleteGO(m_clearSe);
			m_clear = NewGO<Clear>(0, "clear");
			DeleteGO(this);
		}
	}
}

void Game::AppFloorFlag()
{
	PhysicsWorld::GetInstance()->ContactTest(m_player->m_characterController, [&](const btCollisionObject& contactObject)
	{
		if (m_appFloorGhostObj->m_appFloorGhostObj01.IsSelf(contactObject) == true)
		{
			m_appFloors[0]->m_appFloorFlag = false;
			m_breakSe = m_sound->PlayingSound(Sound::enSound_BreakSE);
			m_breakSe->SetVolume(1.5f);
			m_breakSe->Play(false);
			DeleteGO(m_appFloorGhostObj);
		}
	});
}

void Game::GameOverFlag()
{
	if (m_player->m_position.y <= FALLING_DEATH)
	{
		DeleteGO(m_player);
		DeleteGO(m_gameCamera);
		NewGO<GameOver>(0, "gameOver");
		DeleteGO(this);
	}

}

void Game::WarpFlag() 
{
	PhysicsWorld::GetInstance()->ContactTest(m_player->m_characterController, [&](const btCollisionObject& contactObject)
	{
		if (m_warpGhostObj->m_warpGhostObj01.IsSelf(contactObject) == true)
		{
			m_warpSe = m_sound->PlayingSound(Sound::enSound_WarpSE);
			m_warpSe->Play(false);
			m_player->m_position = WARP_POINT01;
			m_player->m_moveSpeed = Vector3::Zero;
			m_player->m_characterController.SetPosition(m_player->m_position);
			m_player->m_modelRender.SetPosition(m_player->m_position);
			m_gameCamera->m_springCamera.Refresh();
		}
		if (m_warpGhostObj->m_warpGhostObj02.IsSelf(contactObject) == true)
		{
			m_warpSe = m_sound->PlayingSound(Sound::enSound_WarpSE);
			m_warpSe->Play(false);
			m_player->m_position = WARP_POINT02;
			m_player->m_moveSpeed = Vector3::Zero;
			m_player->m_characterController.SetPosition(m_player->m_position);
			m_player->m_modelRender.SetPosition(m_player->m_position);
			m_gameCamera->m_springCamera.Refresh();
		}

	});
}

void Game::NothingFlag()
{
	PhysicsWorld::GetInstance()->ContactTest(m_player->m_characterController, [&](const btCollisionObject& contactObject)
	{
		if (m_nothingGhostObj->m_nothingGhostObj.IsSelf(contactObject) == true)
		{
			m_fontAlpha = 1.0f;
		}
	});
}

void Game::AppRoachingFlag()
{
	PhysicsWorld::GetInstance()->ContactTest(m_player->m_characterController, [&](const btCollisionObject& contactObject)
	{
		if (m_appRoachingGhostObj->m_appRoachingGhostObj01.IsSelf(contactObject) == true)
		{
			m_appRoachingWalls[2]->m_appRoachingFlag = true;
			m_appRoachingGhostObj->m_break = m_appRoachingGhostObj->breakGhostObj_01;
		}
		if (m_appRoachingGhostObj->m_appRoachingGhostObj02.IsSelf(contactObject) == true)
		{
			m_appRoachingWalls[1]->m_appRoachingFlag = true;
			m_appRoachingGhostObj->m_break = m_appRoachingGhostObj->breakGhostObj_02;
		}
	});
}

void Game::ShowHint()
{
	
	PhysicsWorld::GetInstance()->ContactTest(m_player->m_characterController, [&](const btCollisionObject& contactObject)
	{
			if (m_hintGhostObj->m_hintGhostObject01.IsSelf(contactObject) == true)
			{
				m_hintGhostObj->m_hint = m_hintGhostObj->showHint_TheEndOfPathWay;
				m_hintBoxs[0]->m_eraceFlag = false;
			}
			else if (m_hintGhostObj->m_hintGhostObject02.IsSelf(contactObject) == true)
			{
				m_hintGhostObj->m_hint = m_hintGhostObj->showHint_SlipFloor;
				m_hintBoxs[1]->m_eraceFlag = false;
			}
			else if (m_hintGhostObj->m_hintGhostObject03.IsSelf(contactObject) == true)
			{
				m_hintGhostObj->m_hint = m_hintGhostObj->showHint_WallSus;
				m_hintBoxs[3]->m_eraceFlag = false;
			}
			else if (m_hintGhostObj->m_hintGhostObject04.IsSelf(contactObject) == true)
			{
				m_hintGhostObj->m_hint = m_hintGhostObj->showHint_GoDown;
				m_hintBoxs[4]->m_eraceFlag = false;
			}
			else if (m_hintGhostObj->m_hintGhostObject05.IsSelf(contactObject) == true)
			{
				m_hintGhostObj->m_hint = m_hintGhostObj->showHint_Maze;
				m_hintBoxs[6]->m_eraceFlag = false;
			}
			
	});
	//m_hintGhostObj->m_hint = m_hintGhostObj->showHint_NotDis;
}

void Game::Render(RenderContext& rc)
{
	m_levelRender.Draw(rc);

	/*m_fontRender.SetColor({ m_fontAlpha,m_fontAlpha ,0.0f,m_fontAlpha });
	m_fontRender.Draw(rc);*/

	m_goalFontRender.SetColor({ m_goalFontAlpha,m_goalFontAlpha ,0.0f,m_goalFontAlpha });
	m_goalFontRender.Draw(rc);

	m_timerFontRender.SetColor({ 0.0f,0.0f,0.0f,m_fontAlpha });
	m_timerFontRender.Draw(rc);
}