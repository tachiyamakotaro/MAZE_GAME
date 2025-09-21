#include "stdafx.h"
#include "Wall.h"

Wall::Wall()
{

}

Wall::~Wall()
{

}

bool Wall::Start()
{
	m_modelRender.Init("Assets/modelData/wall.tkm");
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetScale(m_scale);
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	return true;
}

void Wall::Update()
{

}

void Wall::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
