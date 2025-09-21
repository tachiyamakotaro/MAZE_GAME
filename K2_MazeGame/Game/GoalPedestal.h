#pragma once
class GoalPedestal:public IGameObject
{
public:
	GoalPedestal();
	~GoalPedestal();
	bool Start();
	void Update();
	void Render(RenderContext& rc) override;

	ModelRender				m_modelRender;				//モデルレンダラー。
	Vector3					m_position;					//座標。
	Vector3					m_scale;					//大きさ。
	Quaternion				m_rotation;					//回転。
	PhysicsStaticObject		m_physicsStaticObject;		//静的物理オブジェクト。
};

