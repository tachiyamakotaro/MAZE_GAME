#include "stdafx.h"
#include "AppRoachingWall.h"

namespace
{
	const char* APP_WALL_INIT = "Assets/modelData/appRoachingWall.tkm";

	//const float APP_ROACHING_SPEED = 100.0f;
}

AppRoachingWall::AppRoachingWall()
{

}

AppRoachingWall::~AppRoachingWall()
{

}

bool AppRoachingWall::Start()
{
	m_modelRender.Init(APP_WALL_INIT);
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetScale(m_scale);
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());

	m_collisionObject = NewGO<CollisionObject>(0, "collisionObject");

	m_collisionObject->CreateBox(m_position, Quaternion::Identity, m_scale);
	m_collisionObject->SetIsEnableAutoDelete(false);

	return true;
}

void AppRoachingWall::Update()
{
	AppRoaching();

	m_modelRender.SetPosition(m_position);
	m_modelRender.Update();

	m_collisionObject->SetPosition(m_position);
}

void AppRoachingWall::AppRoaching()
{
	if (m_appRoachingFlag == true)
	{
		m_physicsStaticObject.Release();
	}
	if (m_appRoachingFlag == false)
	{

	}
}

void AppRoachingWall::Render(RenderContext& rc)
{
	if (m_appRoachingFlag != true)
	{
		m_modelRender.Draw(rc);
	}
	if (m_appRoachingFlag == true)
	{

	}
}
