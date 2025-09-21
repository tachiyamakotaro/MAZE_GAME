#include "stdafx.h"
#include "GameOverFloor.h"

GameOverFloor::GameOverFloor()
{

}

GameOverFloor::~GameOverFloor()
{

}

bool GameOverFloor::Start()
{
	m_modelRender.Init("Assets/modelData/gameOver.tkm");
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetScale(m_scale);
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	return true;
}

void GameOverFloor::Update()
{

}

void GameOverFloor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}