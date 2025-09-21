#include "stdafx.h"
#include "AppFloorGhostObj.h"

namespace
{
	const Vector3 APPFLOOR_GHOST_POS01(0.0f, 600.0f, 2100.0f);

	const Vector3 APPFLOOR_GHOST_SCALE01(400.0f, 200.0f, 200.0f);

	//const float APPFLOOR_GHOST_SCALE (200.0f);
}

bool AppFloorGhostObj::Start()
{
	m_appFloorGhostObj01.CreateBox(Vector3(APPFLOOR_GHOST_POS01), Quaternion::Identity, Vector3( APPFLOOR_GHOST_SCALE01));

	return true;
}

void AppFloorGhostObj::Update()
{

}