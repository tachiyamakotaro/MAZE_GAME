#pragma once

class GameCamera;

class Player :public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Move();
	void Jump();
	void Rotation();
	void Animation();
	void Render(RenderContext& rc);

	/// <summary>
	/// ���W��ݒ�B
	/// </summary>
	/// <param name="position">���W�B</param>
	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}
	/// <summary>
	/// ���W���擾�B
	/// </summary>
	/// <returns>���W�B</returns>
	const Vector3& GetPosition() const
	{
		return m_position;
	}
	/// <summary>
	/// �������W��ݒ�B
	/// </summary>
	/// <param name="startPosition">�������W�B</param>
	void SetStartPosition(const Vector3& startPosition)
	{
		m_startPosition = startPosition;
	}
	///<summary>
	///	�ړ����x�����Z
	/// </summary>
	/// <param name="addMoveSpeed">���Z����ړ����x</param>
	void AddMoveSpeed(const Vector3& addMoveSpeed)
	{
		m_moveSpeed += addMoveSpeed;
	}
	///<summary>
	///	�L�����N�^�[�R���g���[���[
	/// </summary>
	/// <returns>�L�����N�^�[�R���g���[���[</returns>
	CharacterController& GetCharacterController()
	{
		return m_characterController;
	}

	Vector3 m_position;
	CharacterController m_characterController;
	Vector3 m_moveSpeed;
	Quaternion m_rotation;
	Vector3 m_startPosition;
	bool m_moveFlag = false;
	int m_animationState = 0;

	SoundSource* m_jumpSe;

	enum EnAnimationClip {
		enAnimationClip_Idle,
		enAnimationClip_Run,
		enAnimationClip_Jump,
		enAnimationClip_Clear,
		enAnimationClip_Death,
		enAnimationClip_Num,
	};
	AnimationClip m_animationClips[enAnimationClip_Num];
	ModelRender m_modelRender;
	bool m_renderFlag = true;
};

