#include <stdio.h>
// trycatch�� ���� ó��

int main()
{
	int a, b;

	while (1)
	{
		try
		{
			printf("�������� ���� �Է��Ͻÿ� : ");
			scanf("%d", &a);
			if (a < 0) throw a;	// a�� ��� catch�� ����
			printf("������ ���� �Է��Ͻÿ� : ");
			scanf("%d", &b);
			if (b == 0) throw "0���δ� ���� �� �����ϴ�.";
			printf("������ ����� %d�Դϴ�.\n", a / b);
		}
		catch (int a)
		{
			printf("%d�� �����̹Ƿ� ������ �ź�\n", a);
		}
		catch (const char* message)
		{
			puts(message);
		}
	}
	
	
}