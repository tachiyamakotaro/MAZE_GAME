#pragma once

#include "sound/SoundSource.h"

class Title :public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void FontFade();
	void TitleBgm();

private:
	enum EnState
	{
		enState_FadeIn,
		enState_FadeOut,
	};
	EnState m_state = enState_FadeIn;
	SpriteRender m_spriteRender;
	FontRender m_fontRender;
	
	float m_fadeAlpha = 1.0f;

	SoundSource* m_titleBgm;
};

