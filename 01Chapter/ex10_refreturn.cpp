#include <stdio.h>

int ar[] = { 1, 2, 3, 4, 5 };

int& GetAr(int i)
{
	return ar[i]; // ���۷����� ��ȯ
}

int main()
{
	//int& ra = 10;	// ����� ���� ���۷��� ���� �Ұ�

	GetAr(3) = 6;	// ���۷����� lvalue�� ���ؼ��� ���� ����
	printf("ar[3] = %d\n", ar[3]);

	return 0;
}
