#pragma once

#include "Entity.h"
#include "Player.h"

class Ball : public Entity
{

public:

	bool GetIsHolding();
	void SetPlayerHolder(Player* newPlayer);
	bool IsHolding;

protected:
	void OnInitialize() override;
	void OnUpdate() override;

	void OnCollision(Entity* pCollidedWith) override;

	bool IsLaunched;
	Player* mPlayerholder;
};

