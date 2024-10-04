#include "Town.h"
#include <conio.h>
#include "Player.h"


int UTown::InPlayer(class UPlayer& _Player)
{
	InMsgPrint();

	while (true)
	{
		_Player.StatusRender();

		std::cout << "1. 체력회복\n";
		std::cout << "2. 강화\n";
		std::cout << "3. 사냥터이동\n";
		std::cout << "4. 중급마을로 이동\n";
		std::cout << "5. 초보마을로 이동\n";
		int Select = _getch();

		switch (Select)
		{
		case '1':
			printf_s("1눌렀습니다.\n");
			_getch();
			return 1;
			break;

		case '2':
			printf_s("2눌렀습니다.\n");
			_getch();
			return 2;
			break;

		case '3':
			printf_s("3눌렀습니다.\n");
			_getch();
			return 3;
			break;

		case '4':
			printf_s("4눌렀습니다.\n");
			_getch();
			return 4;
			break;

		case '5':
			printf_s("5눌렀습니다.\n");
			_getch();
			return 5;
			break;

		default:
			return -1;
			break;
		}

	}
}
