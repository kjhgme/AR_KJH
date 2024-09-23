#include <iostream>
using namespace std;

// 음수 안함
// 0 이외의 양수의 자릿수를 세자.
int NumberCount(int _Value)
{
    // /(나누기를 최대한) 연산을 사용하세요.
    int Result = 0;
    while (true)
    {
        while (_Value)
        {
            _Value = _Value / 10;
            Result += 1;
        }

        return Result;
    }

    return 0;
}

void NumberToString(char* Buffer, int BufferSize, int _Value)
{
    int cnt = 0;

    while (_Value)
    {
        Buffer[cnt] = static_cast<char>(_Value % 10 + '0');
        _Value /= 10;
        cnt++;
    }
    Buffer[cnt] = 0;

    for (int i = 0; i < (cnt / 2); ++i)
    {
        char temp = Buffer[i];
        Buffer[i] = Buffer[cnt - 1 - i];
        Buffer[cnt - 1 - i] = temp;
    }

    cout << Buffer << endl;

    return;
}

int main()
{
    // 5
    int Result0 = NumberCount(12358);
    // 4
    int Result1 = NumberCount(5258);
    // 7
    int Result2 = NumberCount(5258111);

    // 0은 영

    char Buffer[100] = { 0 };

    NumberToString(Buffer, 100, 3712);
    // Buffer == "3712"
}

