#include <stdio.h>

int main()
{
	int i = 3;
	int& ri = i; // ���۷��� ����� �ʱ�ȭ �ʼ�
	int* pi = &i;
	//int* pri = &ri;			// ����
	//int&* pri = &ri;			// �Ұ�
	//int& rri = ri;			// �Ұ�
	//int& ra[2] = { i, j };	// ���۷��� �迭 �Ұ�

	printf("i = %d, ri = %d, pi = %x\n", i, ri, pi);
	ri++;
	printf("i = %d, ri = %d, pi = %d\n", i, ri, *pi); // ������ ������
	printf("i���� = %x, ri���� = %x, pi���� = %x\n", &i, &ri, &pi); // ������ �ּ�
}