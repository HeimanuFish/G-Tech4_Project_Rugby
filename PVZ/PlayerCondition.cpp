#include "PlayerCondition.h"

#include "RugbyScene.h"

bool PlayerCondition_ZombieOnLane::OnTest(Player* owner)
{
	//RugbyScene* pScene = pPlayer->GetScene<PVZScene>();
	
	//int areaIndex = pPlayer->mAreaIndex;

	//bool condition = pScene->IsZombieInArea(areaIndex);

	//return condition;
	return false;
}

bool PlayerCondition_NoAmmo::OnTest(Player* pPlayer)
{
	//return pPlayer->mAmmo == 0;
	return false;
}

bool PlayerCondition_FullAmmo::OnTest(Player* pPlayer)
{
	//return pPlayer->mAmmo == pPlant->mMaxAmmo;
	return false;
}
