#include "stdafx.h"
#include "AppFloor.h"

namespace
{
	
}

AppFloor::AppFloor()
{

}

AppFloor::~AppFloor()
{

}

bool AppFloor::Start()
{
	m_modelRender.Init("Assets/modelData/testAppFloor.tkm");
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetScale(m_scale);
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	return true;
}

void AppFloor::Update()
{
	if (m_appFloorFlag == true)
	{

	}
	else if (m_appFloorFlag == false)
	{
		m_physicsStaticObject.Release();
	}
	m_modelRender.Update();
}

void AppFloor::Render(RenderContext& rc)
{
	if (m_appFloorFlag == true)
	{
		m_modelRender.Draw(rc);
	}
	if (m_appFloorFlag == false)
	{

	}
}
