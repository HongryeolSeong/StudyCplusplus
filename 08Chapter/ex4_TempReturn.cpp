#include <stdio.h>
// �μ��� Ÿ�Ը�ȣ�� �����߻� -> ����� �μ� ����� ��

template <typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

int main()
{
	int a = max<int>(1, 2);
	double b = max(1.1, 2.2);
	//int c = max(2, 3.14);		// Ÿ���� ��ȣ�ϹǷ� ����
	 
	printf("a = %d\n", a);
	printf("b = %.1lf\n", b);
	//printf("c = %d\n", c);
}