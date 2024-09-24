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

    cout << Buffer;

    return;
}

const int IntMaxCount = 10;
const int ParameterInter = 8;

int MyPrintf(const char* const _Ptr, ...)
{
    __int64 FAdd = reinterpret_cast<__int64>(&_Ptr);

    int ChCount = 0;

    while (_Ptr[ChCount])
    {
        char Ch = _Ptr[ChCount];

        if (Ch == '%')
        {
            Ch = _Ptr[ChCount + 1];

            switch (Ch)
            {
            case 'd':
            {
                int* Ptr = reinterpret_cast<int*>(FAdd += ParameterInter);
                int ConvertValue = *Ptr;
                char Arr[IntMaxCount] = {};
                NumberToString(Arr, IntMaxCount, ConvertValue);
                ChCount += 2;
                break;
            }
            default:
                break;
            }
        }

        putchar(_Ptr[ChCount]);
        ChCount += 1;
    }

    return ChCount;
}

int main()
{
    MyPrintf("Number : %d\n", 12321);

    int Value = 123;

    char Arr[IntMaxCount] = {};
    // 100이라는 숫자부터 시작해야한다는것은 어떻게 알수 있을까?
    int NumberCountValue = NumberCount(Value);

    int MulValue = 1;

    for (int i = 0; i < NumberCountValue - 1; i++)
    {
        MulValue *= 10;
    }

    Arr[0] = Value / MulValue;
    // MulValue -= 1000;

    Arr[1] = Value / MulValue;
    // MulValue -= 100;

    Arr[2] = Value / MulValue;
    // MulValue -= 10;
}

