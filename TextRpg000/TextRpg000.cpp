#include <iostream>
#include <conio.h>
#include <random>
using namespace std;

random_device rd;
default_random_engine dre(rd());
uniform_int_distribution<int> uid(0, 10);


const int LINECOUNT = 50;

const int NAMELEN = 10;

int PlayerAtt = 0;
int PlayerHp = 0;
int PlayerSpeed = 10;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
int MonsterSpeed = 10;
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
void CreatePlayer(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
    StrCopy(PlayerName, NAMELEN, _Ptr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
    PlayerSpeed = _Speed;
}

void CreateMonster(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
    StrCopy(MonsterName, NAMELEN, _Ptr);
    MonsterAtt = _Att;
    MonsterHp = _Hp;
    MonsterSpeed = _Speed;
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

void DamageLogic(int& _DefHp, int _Att)
{
    _DefHp -= _Att;
}

void DamageRender(const char* const _AttName, const char* const _DefName, int _Att)
{
    printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, _DefName, _Att);
}

void Damage(const char* const _AttName, const char* const _DefName, int& _DefHp, int _Att)
{
    // 게임 로직
    DamageLogic(_DefHp, _Att);

    // 랜더링
    DamageRender(_AttName, _DefName, _Att);
}

void SpeedCheckRender(const char* const _Name)
{
    printf_s("%s 의 선공입니다\n", _Name);
}

void SpeedChecker(const char* const _PlayerName, const char* const _MonsterName, int _PlayerSpeed, int _MonsterSpeed)
{
    if (_PlayerSpeed > _MonsterSpeed)
    {
        SpeedCheckRender(_MonsterName);
    }
    else {
        SpeedCheckRender(_PlayerName);
    }
}

int SetRandomSpeed(int _Speed)
{
    _Speed = uid(dre);

    return _Speed;
}


int main()
{
    CreatePlayer("1", 10, 100, PlayerSpeed);
    CreateMonster("Orc", 10, 50, MonsterSpeed);

    PlayerStatusRender();
    MonsterStatusRender();

    while (true)
    {
        system("cls");

        char Input = ' ';

        PlayerSpeed = SetRandomSpeed(PlayerSpeed);
        MonsterSpeed = SetRandomSpeed(MonsterSpeed);

        PlayerStatusRender();
        MonsterStatusRender();
        Input = _getch();


        system("cls");
        PlayerStatusRender();
        MonsterStatusRender();

        SpeedChecker(PlayerName, MonsterName, PlayerSpeed, MonsterSpeed);
        Input = _getch();


        system("cls");

        if (PlayerSpeed > MonsterSpeed)
        {
            DamageLogic(PlayerHp, MonsterAtt);

            PlayerStatusRender();
            MonsterStatusRender();

            SpeedCheckRender(MonsterName);

            DamageRender(MonsterName, PlayerName, MonsterAtt);
        }
        else {
            DamageLogic(MonsterHp, PlayerAtt);

            PlayerStatusRender();
            MonsterStatusRender();

            SpeedCheckRender(PlayerName);

            DamageRender(PlayerName, MonsterName, PlayerAtt);
        }
        Input = _getch();


        system("cls");

        if (PlayerSpeed > MonsterSpeed)
        {
            DamageLogic(MonsterHp, PlayerAtt);

            PlayerStatusRender();
            MonsterStatusRender();

            SpeedCheckRender(MonsterName);

            DamageRender(MonsterName, PlayerName, MonsterAtt);
            DamageRender(PlayerName, MonsterName, PlayerAtt);
        }
        else {
            DamageLogic(PlayerHp, MonsterAtt);

            PlayerStatusRender();
            MonsterStatusRender();

            SpeedCheckRender(PlayerName);

            DamageRender(PlayerName, MonsterName, PlayerAtt);
            DamageRender(MonsterName, PlayerName, MonsterAtt);
        }
        Input = _getch();
    }


}
