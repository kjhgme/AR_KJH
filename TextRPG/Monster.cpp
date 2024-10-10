#include <BaseSystem/EngineDebug.h>
#include <iostream>

#include "Monster.h"

void AMonster::BeginPlay()
{

}

void AMonster::SetRandomGold(int _Min, int _Max)
{
	if (_Min > _Max)
	{
		MSGASSERT("���� ����� Max�� Min���� �۽��ϴ�.");
	}

	int Gold = rand() % (_Max - _Min) + _Min;
	SetGold(Gold);
}