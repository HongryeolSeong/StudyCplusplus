#include <stdio.h>

int main()
{
	enum origin { EAST, WEST, SOUTH, NORYH };
	//enum origin mark = WEST; // c���
	origin mark = WEST; // cpp������ ��ũ ���� ����
	printf("%d ����\n", mark);

	typedef struct shuman
	{
		char name[12];
		int age;
		double height;
	} SHuman;

	//struct SHuman kim = { "�����", 29, 181.4 }; // c���
	SHuman kim = { "�����", 29, 181.4 }; // cpp
	printf("�̸� = %s, ���� = %d\n", kim.name, kim.age);

	return 0;
}