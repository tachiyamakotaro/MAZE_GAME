#include "stdafx.h"
#include "GoalPedestal.h"

namespace
{
	const char* GOAL_PEDESTAL_INIT = "Assets/modelData/GoalPedestal.tkm";
}

GoalPedestal::GoalPedestal()
{

}

GoalPedestal::~GoalPedestal()
{

}

bool GoalPedestal::Start()
{
	m_modelRender.Init(GOAL_PEDESTAL_INIT);
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetScale(m_scale);
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	return true;
}

void GoalPedestal::Update()
{

}

void GoalPedestal::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
