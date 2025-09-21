#pragma once
class SlipWall :public IGameObject
{
public:
	SlipWall();
	~SlipWall();
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
	ModelRender				m_modelRender;				//モデルレンダラー。
	Vector3					m_position;					//座標。
	Vector3					m_scale;					//大きさ。
	Quaternion				m_rotation;					//回転。
};

