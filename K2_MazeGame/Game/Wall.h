#pragma once
class Wall:public IGameObject
{
	public:
	Wall();
	~Wall();
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
	ModelRender				m_modelRender;				
	Vector3					m_position;					
	Vector3					m_scale;					
	Quaternion				m_rotation;					
	PhysicsStaticObject		m_physicsStaticObject;		
};

