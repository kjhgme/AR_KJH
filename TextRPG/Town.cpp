#include <iostream>
#include <conio.h>

#include "TextRpgCore.h"
#include "BlackSmith.h"
#include "Player.h"
#include "Town.h"

UTown::UTown()
{
	BS.SetParent(this);
}

UZone* UTown::InPlayer()
{
	InMsgPrint();

	UPlayer& _Player = TextRpgCore::GetPlayer();

	while (true)
	{
		system("cls");

		ZonePrint();
		_Player.StatusRender();

		std::cout << "0. ü��ȸ��\n";
		std::cout << "1. ��ȭ\n";
		std::cout << "2. �ٸ� �������� �̵�\n";

		int Select = _getch();

		switch (Select)
		{
		case '1':
		{
			BS.InPlayer();
			break;
		}

		case '2':
		{
			UZone* NextZone = ConnectingProgress();
			return NextZone;
			break;
		}

		case '0':
		case '3':
			printf_s("���� �ϼ����� ���� ����Դϴ�.");
			_getch();
			return nullptr;

		default:
			break;
		}

	}
}
