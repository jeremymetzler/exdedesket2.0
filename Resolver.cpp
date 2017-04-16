#include "Resolver.h"

int Globals::Shots = 0;
bool Globals::change;
CUserCmd* Globals::UserCmd;
int Globals::TargetID;
IClientEntity* Globals::Target;

void R::Resolve()
{
	IClientEntity *pLocal = Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());

	for (int i = 0; i < Interfaces::Engine->GetMaxClients(); ++i)
	{
		IClientEntity *pEntity = Interfaces::EntList->GetClientEntity(i);

		if (!pEntity || pEntity->IsDormant() || !pEntity->IsAlive())
			continue;

		if (pEntity->GetTeamNum() == pLocal->GetTeamNum() || !pLocal->IsAlive())
			continue;

		Vector* eyeAngles = pEntity->GetEyeAnglesPointer();

		if (Menu::Window.RageBotTab.AccuracyResolver.GetIndex() == 1 || Menu::Window.RageBotTab.AccuracyResolver.GetIndex() == 2)
		{
			if (pEntity != Globals::Target) continue;

			Vector AimAngle;
			CalcAngleYawOnly(pEntity->GetEyePosition(), pLocal->GetAbsOrigin2(), AimAngle);
			NormalizeVector(AimAngle);
			static float StoredYaw = 0;
			static bool bLowerBodyIsUpdated = false;
			if (pEntity->GetLowerBodyYaw() != StoredYaw) bLowerBodyIsUpdated = true;
			else bLowerBodyIsUpdated = false;
			if (bLowerBodyIsUpdated) StoredYaw = pEntity->GetLowerBodyYaw();
			if (pEntity->GetFlags() & FL_ONGROUND && pEntity->GetVelocity().Length2D() != 0) eyeAngles->y = pEntity->GetLowerBodyYaw();
			else

			if (Menu::Window.RageBotTab.AccuracyResolver.GetIndex() == 1 || Menu::Window.RageBotTab.AccuracyResolver.GetIndex() == 2)
			Vector AimAngle;
			CalcAngleYawOnly(pEntity->GetEyePosition(), pLocal->GetAbsOrigin2(), AimAngle);
			NormalizeVector(AimAngle);
			static float StoredYaw = 0;
			static bool bLowerBodyIsUpdated = false;
			if (pEntity->GetLowerBodyYaw() != StoredYaw) bLowerBodyIsUpdated = true;
			else bLowerBodyIsUpdated = false;
			if (bLowerBodyIsUpdated) StoredYaw = pEntity->GetLowerBodyYaw();
			if (pEntity->GetFlags() & FL_ONGROUND && pEntity->GetVelocity().Length2D() != 0) eyeAngles->y = pEntity->GetLowerBodyYaw();
			
	        
		   	}
		}

	}

