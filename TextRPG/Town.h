#pragma once

#include "BlackSmith.h"
#include "Zone.h"

class UTown : public UZone
{
public:
	UTown();

	UZone* InPlayer();

	BlackSmith BS;
};

