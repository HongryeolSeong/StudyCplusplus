#include <stdio.h>
// ����� �μ�

template <typename T>
T cast(int s)
{
	return (T)s;		// intŸ���� s�� TŸ������ ĳ���� �� ����
}

int main()
{
	unsigned u = cast<unsigned>(1234);	// <>�� ���ø� �μ��� Ÿ���� ������
	double d = cast<double>(5678);

	printf("u = %d, d = %f\n", u, d);
}