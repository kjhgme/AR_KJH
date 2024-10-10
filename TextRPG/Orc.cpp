#include <iostream>

#include "Orc.h"

void AOrc::BeginPlay() 
{
	AMonster::BeginPlay();

	SetName("Orc");

	SetMinAtt(5);
	SetMaxAtt(10);
	SetHp(100);
	SetRandomGold(50, 100);
}