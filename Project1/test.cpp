#include <iostream>
using namespace std;

int StringCount(const char* const _Str)
{
    int Count = 0;

    while (_Str[Count])
    {
        Count++;
    }

    return Count;
}

int main()
{
    int Count = strlen("asdfBBBB");

    int Count2 = StringCount("asdfBBBB");

    int a = 0;
}

