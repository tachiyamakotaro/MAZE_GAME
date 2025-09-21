#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Clear.h"
#include"SoundManager.h"

namespace
{
	const Vector3 FONT_POS = { -300.0f,-100.0f,0.0f };
	const float FONT_SCALE = 1.5f;
	const float FONT_BLINK_SPEED = 0.6f;
	const float FADE_IN_LIMIT = 0.0f;
	const float FADE_OUT_LIMIT = 1.0f;
}

Title::Title()
{

}

Title::~Title()
{
	DeleteGO(m_titleBgm);
}

bool Title::Start()
{
	m_spriteRender.Init("Assets/sprite/K2-Maze_Title02.DDS", 1920.0f, 1080.0f);

	m_fontRender.SetText(L"   GAME START  \n PRESS A BUTTON");
	m_fontRender.SetPosition({ FONT_POS });
	m_fontRender.SetScale(FONT_SCALE);
	
	TitleBgm();

	return true;
}

void Title::TitleBgm()
{
	SoundManager* sound = FindGO<SoundManager>("soundManager");
	m_titleBgm = sound->PlayingSound(Sound::enSound_TitleBGM);
	m_titleBgm->SetVolume(0.5f);
}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}

	FontFade();

	m_spriteRender.Update();
}

void Title::FontFade()
{
	switch (m_state)
	{
	case enState_FadeIn:
		m_fadeAlpha -= FONT_BLINK_SPEED * g_gameTime->GetFrameDeltaTime();
		if (m_fadeAlpha <= FADE_IN_LIMIT)
		{
			m_fadeAlpha = FADE_IN_LIMIT;
			m_state = enState_FadeOut;
		}
		break;
	case enState_FadeOut:
		m_fadeAlpha += FONT_BLINK_SPEED * g_gameTime->GetFrameDeltaTime();
		if (m_fadeAlpha >= FADE_OUT_LIMIT)
		{
			m_fadeAlpha = FADE_OUT_LIMIT;
			m_state = enState_FadeIn;
		}
		break;
	}
}

void Title::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
	
	m_fontRender.SetColor({ m_fadeAlpha,m_fadeAlpha,0.0f,m_fadeAlpha });
	m_fontRender.Draw(rc);
	
}
