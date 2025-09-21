#include "stdafx.h"
#include "HintBox.h"
#include "Player.h"

namespace
{
	const char* HINT_BOX_INIT = "Assets/modelData/hint.tkm";

	/*const Vector3 HINT_POS = Vector3(-200.0f, 0.0f, 0.0f);
	const float   HINT_SCALE = 1.5f;*/
}

HintBox::HintBox()
{

}

HintBox::~HintBox()
{

}

bool HintBox::Start()
{
	m_modelRender.Init(HINT_BOX_INIT);
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetScale(m_scale);
	m_modelRender.Update();
	return true;
}

void HintBox::Update()
{
	m_modelRender.Update();
}

void HintBox::Render(RenderContext& rc)
{
	if (m_eraceFlag == true) 
	{
		m_modelRender.Draw(rc);
	}
	if (m_eraceFlag == false)
	{

	}
	m_hintFont.Draw(rc);
	m_hintFont.SetColor(1.0f, 1.0f, 0.0f, 1.0f);
}
