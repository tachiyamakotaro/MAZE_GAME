#include "stdafx.h"
#include "WarpGhostObj.h"

namespace 
{
	const Vector3 WARP_GHOST_POS01 = Vector3(380.0f, -675.0f, -20.0f);
	const Vector3 WARP_GHOST_POS02 = Vector3(-3700.0f, -200.0f, 1000.0f);

	const float WARP_GHOST_SCALE = 200.0f;

	//const char* WARP_INIT = "Assets/modelData/";
}

bool WarpGhostObj::Start()
{
	//ゴーストオブジェクトの初期化
	m_warpGhostObj01.CreateBox(Vector3(WARP_GHOST_POS01), Quaternion::Identity, Vector3::One * WARP_GHOST_SCALE);
	m_warpGhostObj02.CreateBox(Vector3(WARP_GHOST_POS02), Quaternion::Identity, Vector3::One * WARP_GHOST_SCALE);

	return true;
}

void WarpGhostObj::Update()
{

}

void WarpGhostObj::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
}