#pragma once

#include "Action.h"
#include "Player.h"

class PlantAction_Idle : public Action<Player>
{
public:
	void OnStart(Player* pPlayer) override {}
	void OnUpdate(Player* pPlayer) override {}
	void OnEnd(Player* pPlayer) override {}
};

class PlantAction_Shooting : public Action<Player>
{
	float mShootTimer = 0.0f;

public:
	void OnStart(Player* pPlayer) override;
	void OnUpdate(Player* pPlayer) override;
	void OnEnd(Player* pPlayer) override {};
};

class PlantAction_Reloading : public Action<Player>
{
	float mReloadTimer = 0.0f;

public:
	void OnStart(Player* pPlayer) override;
	void OnUpdate(Player* pPlayer) override;
	void OnEnd(Player* pPlayer) override {};

	friend Player;
};