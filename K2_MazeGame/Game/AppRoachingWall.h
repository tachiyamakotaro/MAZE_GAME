#pragma once
class AppRoachingWall:public IGameObject
{
public:
	AppRoachingWall();
	~AppRoachingWall();
	bool Start() override;
	void Update() override;
	void AppRoaching();
	void Render(RenderContext& rc) override;

	ModelRender				m_modelRender;				//���f�������_���[�B
	Vector3					m_position;					//���W�B
	Vector3					m_scale;					//�傫���B
	Quaternion				m_rotation;					//��]�B
	float					m_wallMoveSpeed;
	float m_appRoachingSpeed = 100.0f;
	bool  m_appRoachingFlag = false;

	PhysicsStaticObject		m_physicsStaticObject;		//�ÓI�����I�u�W�F�N�g�B
	CollisionObject* m_collisionObject = nullptr;
};

