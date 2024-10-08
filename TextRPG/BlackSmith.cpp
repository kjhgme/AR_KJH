#include <BaseSystem/EngineDebug.h>
#include <iostream>
#include <conio.h>

#include "TextRpgCore.h"
#include "BlackSmith.h"
#include "Player.h"

void BlackSmith::TryUpgrade()
{
	APlayer& _Player = TextRpgCore::GetPlayer();
	system("cls");

	int CurGold = _Player.GetGold();
	int CurUpgrade = _Player.GetEquipAtt();
	int UpgradeCost = (CurUpgrade + 1) * 100;

	std::cout << "======================= 강 화 =======================\n\n";

	//15강 이상인 경우
	if (15 == CurUpgrade)
	{
		std::cout << "최대 강화수치에 도달해 더 이상 강화할 수 없습니다.\n";
		return;
	}

	std::cout << UpgradeCost << "골드를 사용하여 +" << CurUpgrade << " -> +" << CurUpgrade + 1 << " 강화를 시도합니다...\n";

	//돈이 부족한 경우
	if (CurGold < UpgradeCost)
	{
		std::cout << "강화 비용이 부족합니다. ㅂㅂ\n";
		return;
	}

	_Player.SetGold(CurGold - UpgradeCost);
	// 강화로직

	// int Result = 1; 
	int Result = rand() % 2;
	int UpgradeResult = CurUpgrade;
	//50%
	if (0 < Result) // 0 : 실패 1 : 성공 
	{
		std::cout << "강화에 성공했습니다!!!\n\n";
		UpgradeResult = CurUpgrade + 1;
		_Player.SetEquipAtt(UpgradeResult);
		std::cout << "강화 수치가 1 증가했습니다.\n";
	}
	else
	{
		std::cout << "강화에 실패했습니다...\n\n";
		if (10 <= CurUpgrade) // 10->11 부터는 실패하면 0
		{
			UpgradeResult = 0;
			_Player.SetEquipAtt(UpgradeResult);
			std::cout << "강화 수치가 0으로 초기화 되었습니다. ㅠㅠ\n";
		}
		else if (5 <= CurUpgrade) // 10보다 작고 5->6부터는 실패하면 1깎
		{
			UpgradeResult = CurUpgrade - 1;
			_Player.SetEquipAtt(CurUpgrade - 1);
			std::cout << "강화 수치가 1 감소했습니다.\n";

		}

	}

	std::cout << "강화 결과 : +" << CurUpgrade << " -> +" << UpgradeResult << '\n';
	std::cout << "소지 골드 : " << CurGold << " -> " << _Player.GetGold() << '\n';

	std::cout << '\n';
	_Player.StatusRender();

	std::cout << "아무키나 누르면 대장간으로 돌아갑니다...\n";
	_getch();
}

UZone* BlackSmith::InPlayer()
{
	UZone* ParentZone = GetZone(0);

	if (nullptr == ParentZone)
	{
		MSGASSERT("부모존이 세팅되지 않았습니다");
		return nullptr;
	}

	APlayer& _Player = TextRpgCore::GetPlayer();

	_Player.SetGold(1000000);

	srand(static_cast<unsigned int>(time(nullptr)));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. 강화\n";
		std::cout << "2. 나간다\n";
		int Select = _getch();
		switch (Select)
		{
		case '1':
			TryUpgrade();
			break;
		case '2':
			return nullptr;
		default:
			break;
		}
	}
}