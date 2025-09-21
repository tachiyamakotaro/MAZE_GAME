#include "stdafx.h"
#include "SlipWall.h"

SlipWall::SlipWall()
{

}

SlipWall::~SlipWall()
{

}

bool SlipWall::Start()
{
	m_modelRender.Init("Assets/modelData/slipWall.tkm");
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetScale(m_scale);
	m_modelRender.Update();
	return true;
}

void SlipWall::Update()
{

}

void SlipWall::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
