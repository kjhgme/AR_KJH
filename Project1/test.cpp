#include <iostream>
using namespace std;

void Test(int Value0, int Value1, int Value2, int Value3)
{
	int* Ptr = &Value0;

	int TestValue0 = *Ptr;

	int TestValue1 = *(Ptr + 2);
	int TestValue2 = *(Ptr + 4);
	int TestValue3 = *(Ptr + 6);

	int a = 0;
}

int main()
{
	Test(10, 20, 30, 40);


}
