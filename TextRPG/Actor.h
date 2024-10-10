#pragma once

#include "StatusUnit.h"
#include "FightUnit.h"
#include "Object.h"

class AActor : public UObject, public UStatusUnit, public UFightUnit
{
public:
	void StatusRender();

	virtual void StatusTextRender();
};

