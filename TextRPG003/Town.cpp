#include "Town.h"
#include <conio.h>
#include "Player.h"


int UTown::InPlayer(class UPlayer& _Player)
{
	InMsgPrint();

	while (true)
	{
		_Player.StatusRender();

		std::cout << "1. ü��ȸ��\n";
		std::cout << "2. ��ȭ\n";
		std::cout << "3. ������̵�\n";
		std::cout << "4. �߱޸����� �̵�\n";
		std::cout << "5. �ʺ������� �̵�\n";
		int Select = _getch();

		switch (Select)
		{
		case '1':
			printf_s("1�������ϴ�.\n");
			_getch();
			return 1;
			break;

		case '2':
			printf_s("2�������ϴ�.\n");
			_getch();
			return 2;
			break;

		case '3':
			printf_s("3�������ϴ�.\n");
			_getch();
			return 3;
			break;

		case '4':
			printf_s("4�������ϴ�.\n");
			_getch();
			return 4;
			break;

		case '5':
			printf_s("5�������ϴ�.\n");
			_getch();
			return 5;
			break;

		default:
			return -1;
			break;
		}

	}
}
