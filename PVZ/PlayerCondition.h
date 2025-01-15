#pragma once

#include "Condition.h"
#include "Player.h"

class PlayerCondition_ZombieOnLane : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};

class PlayerCondition_NoAmmo : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};

class PlayerCondition_FullAmmo : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};
