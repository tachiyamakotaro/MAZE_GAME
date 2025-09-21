#include "stdafx.h"
#include "Clear.h"
#include "Player.h"
#include "GameCamera.h"
#include "Title.h"
#include "Wall.h"
#include "SoundManager.h"

namespace
{
	const float GAMECLEAR_FONT_SIZE = 5.0f;
	const Vector3 GAMECLEAR_FONT_POS = Vector3(-550.0f, 350.0f, 0.0f);

	const float TITLE_FONT_SIZE = 1.5f;
	const Vector3 TITLE_FONT_POS = Vector3(415.0f, -400.0f, 0.0f);
}

Clear::Clear()
{

}

Clear::~Clear()
{
	DeleteGO(m_player);
	DeleteGO(m_gameCamera);
	for (auto wall : m_walls)
	{
		DeleteGO(wall);
	}
}

void Clear::ProduceLevel()
{
	m_levelRender.Init("Assets/level3D/clearLevel.tkl",[&](LevelObjectData& objData)
	{
			if (objData.EqualObjectName(L"wall") == true)
			{
				auto wall = NewGO<Wall>(0);
				wall->m_position = objData.position;
				wall->m_rotation = objData.rotation;
				wall->m_scale = objData.scale;
				m_walls.push_back(wall);
				return true;
			}

			if (objData.EqualObjectName(L"unityChan") == true)
			{
				m_player = NewGO<Player>(0, "player");
				m_player->SetPosition(objData.position);
				m_player->SetStartPosition(objData.position);
				return true;
			}

			return false;
	});
}

bool Clear::Start()
{
	ClearBgm();
	ProduceLevel();
	FontSet();
	ClearPlayerSet();
	ClearCameraSet();
	
	return true;
}

void Clear::ClearPlayerSet()
{
	m_player->m_renderFlag = true;
	m_player->m_rotation.SetRotationDegY(180.0f);
	m_player->m_moveFlag = true;
	m_player->m_modelRender.Update();
	m_player->m_modelRender.SetRotation(m_player->m_rotation);
	m_player->m_animationState = Player::enAnimationClip_Clear;
}

void Clear::ClearCameraSet()
{
	m_gameCamera = NewGO<GameCamera>(1, "gameCamera");
	/*m_gameCamera->m_toCameraPos.Set(0.0f, -50.0f, 50.0f);*/
	m_gameCamera->m_fixedCameraFlag = true;
	//m_gameCamera->m_springCamera.SetPosition(0.0f, 5.0f, -50.0f);
	//m_gameCamera->m_cameraPos = m_gameCamera->cameraPos_OutGame;
}

void Clear::ClearBgm()
{
	SoundManager* sound = FindGO<SoundManager>("soundManager");
	m_clearBgm = sound->PlayingSound(Sound::enSound_GameClearBGM);
	m_clearBgm->Play(false);
}

void Clear::FontSet()
{
	m_clearFontRender.SetText(L"GAME CLEAR");
	m_clearFontRender.SetPosition(GAMECLEAR_FONT_POS);
	m_clearFontRender.SetScale(GAMECLEAR_FONT_SIZE);

	m_titleBackFontRender.SetText(L"TITLE: SELECT");
	m_titleBackFontRender.SetPosition(TITLE_FONT_POS);
	m_titleBackFontRender.SetScale(TITLE_FONT_SIZE);
}

void Clear::Update()
{
	//m_spriteRender.Update();
	FontFade();
	TitleBack();
	m_modelRender.Update();
}

void Clear::FontFade()
{
	m_fontAlpha += 0.2f * g_gameTime->GetFrameDeltaTime();
	if (m_fontAlpha >= 1.0f)
	{
		m_fontAlpha = 1.0f;
		m_titleFontAlpha += 0.3f * g_gameTime->GetFrameDeltaTime();
		if (m_titleFontAlpha >= 1.0f)
		{
			m_titleFontAlpha = 1.0f;
		}
	}
}

void Clear::TitleBack()
{
	if (m_titleFontAlpha >= 1.0f)
	{
		if (g_pad[0]->IsTrigger(enButtonSelect))
		{
			NewGO<Title>(0, "title");
			DeleteGO(this);
		}
	}
}

void Clear::Render(RenderContext& rc)
{
	m_levelRender.Draw(rc);

	m_clearFontRender.Draw(rc);
	m_clearFontRender.SetColor({ m_fontAlpha, m_fontAlpha, 0.0f, m_fontAlpha });

	m_titleBackFontRender.Draw(rc);
	m_titleBackFontRender.SetColor({ m_titleFontAlpha, m_titleFontAlpha, m_titleFontAlpha, m_titleFontAlpha });
}
