#include <iostream>
//�Լ��� ��ȣ��

int func(int a)
{
	return a;
}

int func(int a, int b = 0) // ����Ʈ �μ� ����
{
	return a + b;
}

int main()
{
	func(10);

	return 0;
}