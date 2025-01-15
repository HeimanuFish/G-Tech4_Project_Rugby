#pragma once

#include "Entity.h"
#include "Ball.h"

template<typename T>
class StateMachine;

class Player : public Entity
{
	StateMachine<Player>* mpStateMachine;

	enum State 
	{
		Idle,
		Running,
		Passing,
		Pursuing,
		Keeping,

		Count
	};

	int mAreaIndex;

public:

	int mTeam;
	void SetAreaIndex(int index) { mAreaIndex = index; }
	const char* GetStateName(State state) const;

	void SelectPlayer();
	void UnselectPlayer();

	void Stop();
	void Pass();
	void Intercept();

	bool GetIsSelected();

	Ball GetBallinHand();

	
protected:

	Ball mballinhand;
	void OnInitialize() override;
	void OnUpdate() override;
	void OnCollision(Entity* pCollidedWith) override;



	bool IsSelected;

	/*friend class PlayerAction_Idle;
	friend class PlayerAction_Reloading;
	friend class PlayerAction_Shooting;

	friend class PlayerCondition_FullAmmo;
	friend class PlayerCondition_NoAmmo;
	friend class PlayerCondition_ZombieOnLane;*/
};
