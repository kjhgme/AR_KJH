#pragma once

#include "FightZone.h"
#include "Town.h"

class UWorld
{
public:
	void ZoneInit();

	void PlayerZonePlay();

	UTown Town0;
	UTown Town1;
	UFightZone FZone0;
};

