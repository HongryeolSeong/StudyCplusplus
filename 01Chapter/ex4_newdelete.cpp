#include <stdio.h>

int main()
{
	int* pi, *pj;

	pi = new int;		// ���� �Ҵ� + ������ȣ��(�ʱ�ȭ) ����
	pj = new int(10);	// ������ = new Ÿ��[(�ʱ갪)];
	
	*pi = 123;

	printf("*pi = %d\n", *pi);
	printf("*pj = %d\n", *pj);

	delete pi;
	delete pj;
}