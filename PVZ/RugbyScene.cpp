#include "RugbyScene.h"

#include "Player.h"
#include "Zombie.h"
#include "Ball.h"
#include "Debug.h"

#include <vector>

#define PLAN_COUNT 5

Player* pPlayers[PLAN_COUNT];
Ball* ball;
Player* player1;
Player* player2;

void RugbyScene::OnInitialize()
{
	int width = GetWindowWidth();
	int height = GetWindowHeight();

	float playerRadius = height * 0.07f;

	float playerStartY = height / (PLAN_COUNT * 2.f);
	float playerGapY = height / (float)PLAN_COUNT;

	float playerStartX = width * 0.05f;



	for (int i = 0; i < PLAN_COUNT; i++)
	{
		pPlayers[i] = CreateEntity<Player>(playerRadius, sf::Color::Yellow);
		pPlayers[i]->SetPosition(playerStartX, playerStartY, 0.f, 0.5f);
		pPlayers[i]->SetAreaIndex(i);
		pPlayers[i]->mTeam = 1;

		int xMin = playerStartX + playerRadius * 3.f;
		int yMin = playerStartY - playerRadius;
		int xMax = width;
		int yMax = playerStartY + playerRadius;

		//mAreas[i] = { xMin, yMin, xMax, yMax };

		playerStartY += playerGapY;
	}

	Player* pPlayers2[PLAN_COUNT];
	float playerStartX2 = width * 0.9f;
	float playerStartY2 = height / (PLAN_COUNT * 2.f);
	float playerGapY2 = height / (float)PLAN_COUNT;

	for (int i = 0; i < PLAN_COUNT; i++)
	{
		pPlayers2[i] = CreateEntity<Player>(playerRadius, sf::Color::Red);
		pPlayers2[i]->SetPosition(playerStartX2, playerStartY2, 0.f, 0.5f);
		pPlayers2[i]->SetAreaIndex(i);
		pPlayers[i]->mTeam = 2;

		playerStartY2 += playerGapY2;
	}

	ball = CreateEntity<Ball>(20, sf::Color::Green);
	ball->SetPosition(500,250, 0.f, 0.5f);

	player1 = CreateEntity<Player>(playerRadius, sf::Color::Green);
	player1->SetPosition(400, 400, 0.f, 0.5f);
	player1->mTeam = 1;

	player2 = CreateEntity<Player>(playerRadius, sf::Color::Green);
	player2->SetPosition(800, 800, 0.f, 0.5f);
	player2->mTeam = 2;
}

void RugbyScene::OnUpdate()
{
	for (int i = 0; i < PLAN_COUNT; i++)
	{
		//const AABB& aabb; //mAreas[i];

		Debug::DrawRectangle(40, 0, 10, GetWindowHeight(), sf::Color::White);
		Debug::DrawRectangle(GetWindowWidth()- 40, 0, 10, GetWindowHeight(), sf::Color::White);
	}
}

int RugbyScene::GetClickedPlayer(int x, int y) const
{


	for (int i = 0; i < PLAN_COUNT; i++)
	{
		if (x >= pPlayers[i]->GetPosition().x - pPlayers[i]->GetRadius() && x <= pPlayers[i]->GetPosition().x + pPlayers[i]->GetRadius()
			&& y >= pPlayers[i]->GetPosition().y - pPlayers[i]->GetRadius() && y <= pPlayers[i]->GetPosition().y + pPlayers[i]->GetRadius())
		/*const AABB* aabb = &mAreas[i];

		if (x >= aabb->xMin && x <= aabb->xMax && y >= aabb->yMin && y <= aabb->yMax)*/
			return i;


	}


	return -1;
}

void RugbyScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Left)
	{
		for (int i = 0; i < PLAN_COUNT; i++)
		{
			pPlayers[i]->UnselectPlayer();
		}

		int index = GetClickedPlayer(event.mouseButton.x, event.mouseButton.y);

		if (index != -1)
		{
			pPlayers[index]->SelectPlayer();
		}
	}

	if (event.mouseButton.button == sf::Mouse::Middle)
	{
		//TO DO
	}

	if (event.mouseButton.button == sf::Mouse::Right)
	{
		for (int i = 0; i < PLAN_COUNT; i++) 
		{
			if (pPlayers[i] != nullptr && pPlayers[i]->GetIsSelected())
			{
				pPlayers[i]->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100);
			}
		}
	}
}

bool RugbyScene::IsZombieInArea(int index) const
{
	_ASSERT(index >= 0 && index < PLAN_COUNT);

	return mLaneZombieCount[index] > 0;
}

void RugbyScene::OnDestroyZombie(int lane)
{
	_ASSERT(lane >= 0 && lane < PLAN_COUNT);
	if(mLaneZombieCount[lane] <= 0)
		return;

	mLaneZombieCount[lane]--;
}