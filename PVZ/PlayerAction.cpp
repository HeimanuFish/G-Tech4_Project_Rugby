#include "PlayerAction.h"
#include "Player.h"
#include "StateMachine.h"

#include "GameManager.h"
#include "Ball.h"
#include "RugbyScene.h"

void PlantAction_Shooting::OnStart(Player* pPlayer)
{
	//mShootTimer = pPlayer->mShootCadence;
}

void PlantAction_Shooting::OnUpdate(Player* pPlayer)
{
	/*mShootTimer += GameManager::Get()->GetDeltaTime();

	if (mShootTimer < pPlayer->mShootCadence)
		return;

	mShootTimer -= pPlayer->mShootCadence;

	pPlayer->Shoot();*/
}

void PlantAction_Reloading::OnStart(Player* pPlayer)
{
	//mReloadTimer = 0.f;
}

void PlantAction_Reloading::OnUpdate(Player* pPlayer)
{
	/*mReloadTimer += GameManager::Get()->GetDeltaTime();

	if (mReloadTimer < pPlayer->mReloadDuration)
		return;

	pPlayer->Reload();

	pPlayer->mpStateMachine->SetState(Player::Idle);*/
}