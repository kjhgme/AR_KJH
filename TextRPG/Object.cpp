#include <BaseSystem/EngineDebug.h>
#include <iostream>

#include "Object.h"
#include "Enums.h"

void UObject::SetName(const char* const _Name)
{
    if (static_cast<int>(Enums::MAXS::NAMEMAX) <= strlen(_Name))
    {
        MSGASSERT("�̸��� �ʹ� ��ϴ�");
        return;
    }

    strcpy_s(Name, _Name);
}

void UObject::TopLine()
{
    const char* Name = GetName();
    printf_s("%s Status", Name);
    int NameLan = static_cast<int>(strlen(Name));
    int StatusRand = static_cast<int>(strlen(" Status"));
    int nameLineCount = static_cast<int>(Enums::MAXS::LINECOUNT) - NameLan - StatusRand;
    for (int i = 0; i < nameLineCount; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
}

void UObject::BotLine()
{
    for (int i = 0; i < static_cast<int>(Enums::MAXS::LINECOUNT); i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");

}

