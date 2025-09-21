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

	ModelRender				m_modelRender;				//モデルレンダラー。
	Vector3					m_position;					//座標。
	Vector3					m_scale;					//大きさ。
	Quaternion				m_rotation;					//回転。
	float					m_wallMoveSpeed;
	float m_appRoachingSpeed = 100.0f;
	bool  m_appRoachingFlag = false;

	PhysicsStaticObject		m_physicsStaticObject;		//静的物理オブジェクト。
	CollisionObject* m_collisionObject = nullptr;
};

