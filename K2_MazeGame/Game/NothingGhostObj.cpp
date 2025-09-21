#include "stdafx.h"
#include "NothingGhostObj.h"

namespace
{
	const Vector3 NOTHING_GHOST_POS = Vector3(-350.0f, -340.0f, 1000.0f);
	const float NOTHING_GHOST_SCALE = 400.0f;
}

bool NothingGhostObj::Start()
{
	m_nothingGhostObj.CreateBox(Vector3(NOTHING_GHOST_POS), Quaternion::Identity, Vector3::One * NOTHING_GHOST_SCALE);
	return true;
}

void NothingGhostObj::Update()
{

}
