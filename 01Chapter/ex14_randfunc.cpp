#include <stdio.h>
#include <stdlib.h>

//int randfunc(int n)
//{
//	return rand() % n;
//}

inline int randfunc(int n)	// �ζ��� �Լ�
{							// �Լ� ȣ��� �б�x -> �� ������ �Լ� ȣ��
	return rand() % n;		// ���ο� �Լ� ��ü�� ����
}

int main()
{
	int i, j, k;
	i = randfunc(10);
	j = randfunc(100);
	k = randfunc(50);
	printf("���� = %d, %d, %d\n", i, j, k);
}