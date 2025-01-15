#include "Player.h"

#include <string>

#include "RugbyScene.h"
#include "Ball.h"

#include "StateMachine.h"
#include "PlayerAction.h"
#include "PlayerCondition.h"

#include "Debug.h"

/*void Player::OnInitialize()
{
	mpStateMachine = new StateMachine<Player>(this, State::Count);

	mAreaIndex = -1;
	mAmmo = mMaxAmmo;

	SetTag(RugbyScene::Tag::PLAYER);
	
	//IDLE
	{
		//Action<Player>* pIdle = mpStateMachine->CreateAction<PlantAction_Idle>(State::Idle);

		/*/ /*SHOOTING
		{
			auto transition = pIdle->CreateTransition(State::Shooting);

			auto condition = transition->AddCondition<PlantCondition_ZombieOnLane>();
		}

		//-> RELOADING
		{
			auto transition = pIdle->CreateTransition(State::Reloading);

			transition->AddCondition<PlantCondition_FullAmmo>(false);
			transition->AddCondition<PlantCondition_ZombieOnLane>(false);
		}
	}

}*/

/*const char* Player::GetStateName(State state) const
{
	switch (state)
	{
	case Idle: return "Idle";
	case Running: return "Running";
	case Passing: return "Passing";
	case Pursuing: return "Pursuing";
	case Keeping: return "Keeping";
	default: return "Unknown";
	}

	
		
		
		
}*/

const char* Player::GetStateName(State state) const
{
	return nullptr;
}

void Player::SelectPlayer()
{
	IsSelected = true;
	mShape.setFillColor(sf::Color::Cyan);

}

void Player::UnselectPlayer()
{
	IsSelected = false;
	mShape.setFillColor(sf::Color::Yellow);
}

void Player::Stop()
{
}

void Player::Pass()
{
	
}

void Player::Intercept()
{
}


bool Player::GetIsSelected()
{
	return IsSelected;
}

Ball Player::GetBallinHand()
{
	return mballinhand;
}

void Player::OnInitialize()
{
	SetTag(RugbyScene::Tag::PLAYER);
	IsSelected = false;
}

void Player::OnUpdate()
{

}

void Player::OnCollision(Entity* pCollidedWith)
{
	if (pCollidedWith->IsTag(RugbyScene::Tag::PLAYER))
	{
		Player* playerinCollision = dynamic_cast<Player*>(pCollidedWith);

		if (playerinCollision->mTeam != mTeam)
		{
			playerinCollision->GetBallinHand().SetPlayerHolder(this);
		}
	}

}

/*void Player::OnUpdate()
{
	const sf::Vector2f& position = GetPosition();
	const char* stateName = GetStateName((Player::State)mpStateMachine->GetCurrentState());

	std::string speed = std::to_string(mSpeed) + "/" + std::to_string(mAcceleration);

	Debug::DrawText(position.x, position.y - 50, stateName, 0.5f, 0.5f, sf::Color::Red);
	Debug::DrawText(position.x, position.y, speed, 0.5f, 0.5f, sf::Color::Blue);

	mpStateMachine->Update();
}
*/