#include "stdafx.h"
#include "GameOver.h"
#include "Player.h"
#include "GameCamera.h"
#include "GameOverFloor.h"
#include "Title.h"
#include "Game.h"
#include "SoundManager.h"

namespace
{
	const float GAMEOVER_FONT_SIZE = 5.0f;
	const Vector3 GAMEOVER_FONT_POS = Vector3(-550.0f, 350.0f, 0.0f);

	const float RESTART_FONT_SIZE = 1.5f;
	const Vector3 RESTART_FONT_POS = Vector3(350.0f, -320.0f, 0.0f);

	const float TITLE_FONT_SIZE = 1.5f;
	const Vector3 TITLE_FONT_POS = Vector3(415.0f, -400.0f, 0.0f);
}

GameOver::GameOver()
{

}

GameOver::~GameOver()
{
	DeleteGO(m_player);
	DeleteGO(m_gameCamera);
	DeleteGO(m_gameOverBgm);
	for (auto gameOverFloor : m_gameOverFloors)
	{
		DeleteGO(gameOverFloor);
	}
}

void GameOver::ProduceLevel()
{
	m_levelRender.Init("Assets/level3D/gameOverLevel.tkl", [&](LevelObjectData& objData)
	{
			if (objData.EqualObjectName(L"unityChan") == true)
			{
				m_player = NewGO<Player>(0, "player");
				m_player->SetPosition(objData.position);
				m_player->SetStartPosition(objData.position);
				return true;
			}

			else if (objData.EqualObjectName(L"gameOver") == true)
			{
				auto gameOverFloor = NewGO<GameOverFloor>(0, "gameOverFloor");
				gameOverFloor->m_position = objData.position;
				gameOverFloor->m_rotation = objData.rotation;
				gameOverFloor->m_scale = objData.scale;
				m_gameOverFloors.push_back(gameOverFloor);
				return true;
			}

			return false;
	});
}

bool GameOver::Start()
{
	ProduceLevel();
	GameOverBGM();
	FontSet();
	//m_player->m_position = Vector3(0.0f, 0.0f, 0.0f);
	m_gameCamera = NewGO<GameCamera>(1, "gameCamera");	
	m_gameCamera->m_fixedCameraFlag = true;
	//m_gameCamera->m_cameraPos = m_gameCamera->cameraPos_OutGame;

	m_player->m_moveFlag = true;
	m_player->m_animationState = 4;
	//トーンマップを無効にする。
	g_renderingEngine->DisableTonemap();
	//g_renderingEngine->DisableIBLTextureForAmbient();
	return true;
}

void GameOver::GameOverBGM()
{
	SoundManager*sound=FindGO<SoundManager>("soundManager");
	m_gameOverBgm = sound->PlayingSound(Sound::enSound_GameOverBGM);
	m_gameOverBgm->Play(false);
}

void GameOver::FontSet()
{
	m_gameOverFontRender.SetText(L"GAME OVER");
	m_gameOverFontRender.SetPosition(GAMEOVER_FONT_POS);
	m_gameOverFontRender.SetScale(GAMEOVER_FONT_SIZE);

	m_restartFontRender.SetText(L"RESTART: START");
	m_restartFontRender.SetPosition(RESTART_FONT_POS);
	m_restartFontRender.SetScale(RESTART_FONT_SIZE);

	m_titleBackFontRender.SetText(L"TITLE: SELECT");
	m_titleBackFontRender.SetPosition(TITLE_FONT_POS);
	m_titleBackFontRender.SetScale(TITLE_FONT_SIZE);
}

void GameOver::Update()
{
	FontFade();
	RestartOrTitle();
	m_modelRender.Update();
}

void GameOver::FontFade()
{
	m_fontAlpha += 0.15f * g_gameTime->GetFrameDeltaTime();
	if (m_fontAlpha >= 1.0f)
	{
		m_fontAlpha = 1.0f;
		m_restartAndTitleAlpha += 0.3f * g_gameTime->GetFrameDeltaTime();
		if (m_restartAndTitleAlpha >= 1.0f)
		{
			m_restartAndTitleAlpha = 1.0f;
		}
	}
}

void GameOver::RestartOrTitle()
{
	if (m_restartAndTitleAlpha >= 1.0f) {
		if (g_pad[0]->IsTrigger(enButtonSelect))
		{
			NewGO<Title>(0, "title");
			DeleteGO(this);
		}
		if (g_pad[0]->IsTrigger(enButtonStart))
		{
			m_game = NewGO<Game>(0, "game");
			DeleteGO(this);
		}
	}
}

void GameOver::Render(RenderContext& rc)
{
	m_levelRender.Draw(rc);

	m_gameOverFontRender.Draw(rc);
	m_gameOverFontRender.SetColor({ m_fontAlpha, m_fontAlpha, m_fontAlpha, m_fontAlpha });

	m_restartFontRender.Draw(rc);
	m_restartFontRender.SetColor({ m_restartAndTitleAlpha, m_restartAndTitleAlpha, m_restartAndTitleAlpha, m_restartAndTitleAlpha });

	m_titleBackFontRender.Draw(rc);
	m_titleBackFontRender.SetColor({ m_restartAndTitleAlpha, m_restartAndTitleAlpha, m_restartAndTitleAlpha, m_restartAndTitleAlpha });
}
