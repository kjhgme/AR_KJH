#include <iostream>
using namespace std;

int StringCount(const char* const _Str)
{
    int Count = 0;

    while (_Str[Count])
    {
        if (_Str[Count] != 0)
        {
            Count++;
        }
    }

    return Count;
}

int main()
{
    int Count = strlen("asdfBBBB");

    int Count2 = StringCount("asdfBBBB");

    int a = 0;
}

