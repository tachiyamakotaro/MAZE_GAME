#pragma once
class NothingGhostObj:public IGameObject
{
public:
	bool Start();
	void Update();
	
	PhysicsGhostObject m_nothingGhostObj;
};

