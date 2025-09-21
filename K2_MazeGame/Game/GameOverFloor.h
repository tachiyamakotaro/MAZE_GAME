#pragma once
class GameOverFloor :public IGameObject
{
public:
	GameOverFloor();
	~GameOverFloor();
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;

	ModelRender				m_modelRender;				//���f�������_���[�B
	Vector3					m_position;					//���W�B
	Vector3					m_scale;					//�傫���B
	Quaternion				m_rotation;					//��]�B
	PhysicsStaticObject		m_physicsStaticObject;		//�ÓI�����I�u�W�F�N�g�B
};

