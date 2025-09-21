#include "stdafx.h"
#include "HintGhostObj.h"
#include "SoundManager.h"

namespace
{
	const Vector3 HINT_GHOST_POS_01(400.0f, 250.0f, 1400.0f);
	const Vector3 HINT_GHOST_POS_02(400.0f, 100.0f, 300.0f);
	const Vector3 HINT_GHOST_POS_03(25.0f, 600.0f, 1900.0f);
	const Vector3 HINT_GHOST_POS_04(-1000.0f, 50.0f, 1000.0f);
	const Vector3 HINT_GHOST_POS_05(-2900.0f, -200.0f, 1650.0f);

	const float   HiNT_GHOST_SCALE(200.0f);

	const Vector3 HINT_POS = Vector3(-900.0f, 400.0f, 0.0f);
	const float   HINT_SCALE = 1.5f;
}

HintGhostObj::HintGhostObj()
{

}

HintGhostObj::~HintGhostObj()
{

}

bool HintGhostObj::Start()
{
	MakeGhostObj();
	return true;
}

void HintGhostObj::MakeGhostObj()
{
	m_hintGhostObject01.CreateBox(Vector3(HINT_GHOST_POS_01), Quaternion::Identity, Vector3::One * HiNT_GHOST_SCALE);
	m_hintGhostObject02.CreateBox(Vector3(HINT_GHOST_POS_02), Quaternion::Identity, Vector3::One * HiNT_GHOST_SCALE);
	m_hintGhostObject03.CreateBox(Vector3(HINT_GHOST_POS_03), Quaternion::Identity, Vector3::One * HiNT_GHOST_SCALE);
	m_hintGhostObject04.CreateBox(Vector3(HINT_GHOST_POS_04), Quaternion::Identity, Vector3::One * HiNT_GHOST_SCALE);
	m_hintGhostObject05.CreateBox(Vector3(HINT_GHOST_POS_05), Quaternion::Identity, Vector3::One * HiNT_GHOST_SCALE);
}

void HintGhostObj::Update()
{
	HintFont();

	HintSeFlag();
}

void HintGhostObj::HintFont()
{
	
	switch (m_hint)
	{
	case showHint_TheEndOfPathWay:
		m_hintFont.SetText(L"スタート地点横の通路に行こう");
		m_hintFont.SetPosition({ HINT_POS });
		m_hintFont.SetScale(HINT_SCALE);

		m_hintGhostObject01.Release();
		break;

	case showHint_SlipFloor:
		m_hintFont.SetText(L"下に降りてみよう");
		m_hintFont.SetPosition({ HINT_POS });
		m_hintFont.SetScale(HINT_SCALE);

		m_hintGhostObject02.Release();
		break;

	case showHint_WallSus:
		m_hintFont.SetText(L"壊れた坂の近くの壁が怪しい気がする");
		m_hintFont.SetPosition({ HINT_POS });
		m_hintFont.SetScale(HINT_SCALE);

		m_hintGhostObject03.Release();
		break;

	case showHint_GoDown:
		m_hintFont.SetText(L"下に何かありそう");
		m_hintFont.SetPosition({ HINT_POS });
		m_hintFont.SetScale(HINT_SCALE);

		m_hintGhostObject04.Release();
		break;

	case showHint_Maze:
		m_hintFont.SetText(L"最後の迷路だ、頑張って進もう");
		m_hintFont.SetPosition({ HINT_POS });
		m_hintFont.SetScale(HINT_SCALE);

		m_hintGhostObject05.Release();

	case showHint_NotDis:
		m_hintAlpha = 0.0f;
		break;

	default:
		break;
	}

	if (m_hint != showHint_NotDis)
	{
		m_hintAlpha = 1.0f;
	}
}

void HintGhostObj::HintSeFlag()
{
	if (m_hint != m_prevHint && m_hint != showHint_NotDis)
	{
		HintSe();
	}

	m_prevHint = m_hint;
}

void HintGhostObj::HintSe()
{
	SoundManager* sound = FindGO<SoundManager>("soundManager");
	m_hintSe = sound->PlayingSound(Sound::enSound_HintSE);
	m_hintSe->Play(false);
}

void HintGhostObj::Render(RenderContext& rc)
{
	m_hintFont.Draw(rc);
	m_hintFont.SetColor(m_hintAlpha, m_hintAlpha, 0.0f, m_hintAlpha);
}


