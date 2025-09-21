#pragma once
class WarpGhostObj :public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	Vector3 m_position;
	Vector3 m_scale;
	Quaternion m_rotation;

	PhysicsGhostObject m_warpGhostObj01;
	PhysicsGhostObject m_warpGhostObj02;

	ModelRender m_modelRender;
};

