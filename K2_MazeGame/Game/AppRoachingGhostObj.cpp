#include "stdafx.h"
#include "AppRoachingGhostObj.h"
#include "SoundManager.h"

namespace
{
	const Vector3 APPROACHING_GHOST_POS01 = Vector3(-3500.0f, -200.0f, 1000.0f);
	const float APPROACHING_GHOST_SCALE01 = 350.0f;

	const Vector3 APPROACHING_GHOST_POS02 = Vector3(-2500.0f, -200.0f, 2500.0f);
	const float APPROACHING_GHOST_SCALE02 = 150.0f;
}

bool AppRoachingGhostObj::Start()
{
	MakeGhostObj();

	return true;
}

void AppRoachingGhostObj::MakeGhostObj()
{
	m_appRoachingGhostObj01.CreateBox(Vector3(APPROACHING_GHOST_POS01), Quaternion::Identity, Vector3::One * APPROACHING_GHOST_SCALE01);

	m_appRoachingGhostObj02.CreateBox(Vector3(APPROACHING_GHOST_POS02), Quaternion::Identity, Vector3::One * APPROACHING_GHOST_SCALE02);
}

void AppRoachingGhostObj::Update()
{
	BreakFlag();
	BreakSeFlag();
}

void AppRoachingGhostObj::BreakFlag()
{
	switch (m_break)
	{
	case breakGhostObj_01:
		m_appRoachingGhostObj01.Release();
		break;

	case breakGhostObj_02:
		m_appRoachingGhostObj02.Release();
		break;

	default:
		break;
	}
}

void AppRoachingGhostObj::BreakSeFlag()
{
	if (m_break != m_prevBreak && m_break != breakGhostObj_Not)
	{
		BreakSe();
	}

	m_prevBreak = m_break;
}

void AppRoachingGhostObj::BreakSe()
{
	SoundManager*sound =FindGO<SoundManager>("soundManager");
	m_breakSe = sound->PlayingSound(Sound::enSound_BreakSE);
	m_breakSe->Play(false);
	m_breakSe->SetVolume(1.5f);
}
