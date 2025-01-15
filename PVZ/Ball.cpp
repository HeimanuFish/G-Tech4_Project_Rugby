#include "Ball.h"
#include <ios>

#include "RugbyScene.h"

bool Ball::GetIsHolding()
{
	return IsHolding;
}

void Ball::SetPlayerHolder(Player* newPlayer)
{
	mPlayerholder = newPlayer;
}

void Ball::OnInitialize()
{
	SetTag(RugbyScene::Tag::BALL);
	//SetRigidBody(false);
	//SetDirection(1.0f, 0.0f, 100.0f);
}

void Ball::OnUpdate()
{

	if (mPlayerholder != nullptr)
	{
		SetPosition(mPlayerholder->GetPosition().x, mPlayerholder->GetPosition().y, 0.0, 0.5);
	}



}

void Ball::OnCollision(Entity* pCollidedWith)
{
	if (pCollidedWith->IsTag(RugbyScene::Tag::PLAYER))
	{

		Player* playerinCollision = dynamic_cast<Player*>(pCollidedWith);

		if (mPlayerholder != nullptr)
		{
			if (mPlayerholder->mTeam == playerinCollision->mTeam)
			{
				return;

			}
		}

		mPlayerholder = playerinCollision;
		return;
	}
}
