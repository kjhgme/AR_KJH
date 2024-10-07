#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("�θ����� ���õ��� �ʾҽ��ϴ�");
		return;
	}

	if(_Player.GetGold() <= 0)
		_Player.SetGold(1000000);
	
	srand(time(nullptr));

	while (true)
	{
		system("cls");

		_Player.StatusRender();
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������\n";
		int Select = _getch();
		switch (Select)
		{
		case '1':
			UpgradeWeapon(_Player);
			// Ȯ���� ���δ� 2���� 1
			// 1���� �𿩾� �Ѵ�. �÷��̾��� ��ȭ �ܰ� * 100
			// ���� ���� 5���� �����ϰ� �ִ�. �׷��� 500���� �￩�� �Ѵ�.
			// 1~5������ ���а� ����Ȯ���� ������.
			// �ٿ������ �ʴ´�.
			// 6~10������ �����ϸ� 1�� �ٿ�ȴ�.
			// 10~15�� 0���� �����ϸ� 0���� ��������.
			// 15�� �̻��̸� ��ȭ�� ���ϰ� �ؾ����Ѵ�.
			return;
		case '2':
			return;
		default:
			break;
		}
	}
}

void BlackSmith::UpgradeWeapon(UPlayer& _Player)
{
	if (_Player.GetEquipAtt() >= 15)
		return;

	_Player.SetGold(_Player.GetGold() - ((_Player.GetEquipAtt() + 1) * 100));

	if (rand() % 2 == 0)
	{
		_Player.SetEquipAtt(_Player.GetEquipAtt() + 1);
	}
	else
	{
		if (6 <= _Player.GetEquipAtt() && _Player.GetEquipAtt() < 10)
		{
			_Player.SetEquipAtt(_Player.GetEquipAtt() - 1);
		}
		else if (10 <= _Player.GetEquipAtt() && _Player.GetEquipAtt() < 15)
		{
			_Player.SetEquipAtt(0);
		}
	}
}
