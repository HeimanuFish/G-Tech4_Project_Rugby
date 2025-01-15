#include "Zombie.h"

#include "RugbyScene.h"

#include <iostream>

void Zombie::OnInitialize()
{
	SetTag(RugbyScene::Tag::ZOMBIE);

	SetDirection(-1, 0, 50);
}

void Zombie::OnCollision(Entity* pCollidedWith)
{
	if (pCollidedWith->IsTag(RugbyScene::Tag::BALL) || pCollidedWith->IsTag(RugbyScene::Tag::PLAYER))
	{
		GetScene<RugbyScene>()->OnDestroyZombie(mLane);

		Destroy();
	}
}
