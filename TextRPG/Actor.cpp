#include <iostream>

#include "Actor.h"

void AActor::StatusRender()
{
	TopLine();

	StatusTextRender();


	BotLine();
}


void AActor::StatusTextRender()
{
	printf_s("���ݷ� : %d ~ %d\n", MinAtt, MaxAtt);
	printf_s("ü�� : %d\n", Hp);
	printf_s("��� : %d\n", Gold);
}