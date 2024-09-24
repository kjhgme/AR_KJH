#include <iostream>
#include <conio.h>

const int LINECOUNT = 50;

const int NAMELEN = 10;

int PlayerAtt = 0;
int PlayerHp = 0;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
char MonsterName[NAMELEN] = "NONE";

void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
{
    for (int i = 0; i < _BufferSize; i += 1)
    {
        _Arr[i] = 0;
    }

    int Size = strlen(_Name);
    _Arr[0] = _Name[0];

    for (int i = 0; i < Size; i++)
    {
        _Arr[i] = _Name[i];
    }
}

// 행동
void CreatePlayer(const char* const _Ptr, int _Att, int _Hp)
{
    StrCopy(PlayerName, NAMELEN, _Ptr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
}

void CreateMonster(const char* const _Ptr, int _Att, int _Hp)
{
    StrCopy(MonsterName, NAMELEN, _Ptr);
    MonsterAtt = _Att;
    MonsterHp = _Hp;
}

void StatusRender(const char* _Name, int _Att, int _HP)
{
    printf_s("%s Status ", _Name);

    int nameSize = strlen(_Name) + strlen(" Status ");

    for (int i = 0; i < LINECOUNT - nameSize; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");

    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _HP);

    for (int i = 0; i < LINECOUNT; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");

    // printf_s("---------------------------------------------------\n");
}

void PlayerStatusRender()
{
    StatusRender(PlayerName, PlayerAtt, PlayerHp);
}

void MonsterStatusRender()
{
    StatusRender(MonsterName, MonsterAtt, MonsterHp);
}

void DamageLogic(const char* const _AttName, const char* const _DefName, int& _DefHp, int _Att)
{
    _DefHp -= _Att;
}

void DamageRender(const char* const _AttName, const char* const _DefName, int& _DefHp, int _Att)
{
    printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, _DefName, _Att);
}


void Damage(const char* const _AttName, const char* const _DefName, int& _DefHp, int _Att)
{
    // 게임 로직
    DamageLogic(_AttName, _DefName, _DefHp, _Att);

    // 랜더링
    DamageRender(_AttName, _DefName, _DefHp, _Att);
}




int main()
{
    // char Test0[100] = "Player";
    /*char Test1[50] = Test0;
    Test1 = Test0*/;

    CreatePlayer("1", 10, 100);
    CreateMonster("Orc", 10, 50);

    PlayerStatusRender();
    MonsterStatusRender();

    while (true)
    {
        system("cls");

        char Input = ' ';

        PlayerStatusRender();
        MonsterStatusRender();
        Input = _getch();


        system("cls");
        PlayerStatusRender();
        MonsterStatusRender();
        Damage(PlayerName, MonsterName, MonsterHp, PlayerAtt);

        system("cls");
        PlayerStatusRender();
        MonsterStatusRender();
        DamageRender(PlayerName, MonsterName, MonsterHp, PlayerAtt);

        Input = _getch();


        system("cls");
        PlayerStatusRender();
        MonsterStatusRender();
        Damage(MonsterName, PlayerName, PlayerHp, MonsterAtt);

        system("cls");
        PlayerStatusRender();
        MonsterStatusRender();
        DamageRender(PlayerName, MonsterName, MonsterHp, PlayerAtt);
        DamageRender(MonsterName, PlayerName, PlayerHp, MonsterAtt);

        Input = _getch();
    }


}
