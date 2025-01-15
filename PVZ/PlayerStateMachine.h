#pragma once

#include <vector>

#include "Action.h"

template<typename T>

class PlayerStateMachine
{
	std::vector<Action<T>*> mActions;
	int mCurrentState;

	T* mOwner;

public:
	PlayerStateMachine(T* owner, int stateCount);
	~PlayerStateMachine();

	void Update();
	void SetState(int state);
	int GetCurrentState() const { return mCurrentState; }

	template<typename U>
	U* CreateAction(int state);

};

#include "PlayerStateMachine.inl"

