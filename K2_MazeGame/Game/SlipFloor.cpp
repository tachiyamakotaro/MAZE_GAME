#include "stdafx.h"
#include "SlipFloor.h"

SlipFloor::SlipFloor()
{

}

SlipFloor::~SlipFloor()
{

}

bool SlipFloor::Start()
{
	m_modelRender.Init("Assets/modelData/slipFloor.tkm");
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetScale(m_scale);
	m_modelRender.Update();
	
	return true;
}

void SlipFloor::Update()
{

}

void SlipFloor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}