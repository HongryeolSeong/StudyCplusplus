#include <stdio.h>
#include <malloc.h>
#include <string.h>

void InputNameRef(char*& Name)
{
	Name = (char*)malloc(32);
	strcpy(Name, "kim sang hyung");
}

int main()
{
	char* Name;

	InputNameRef(Name); // Name�� ���μ��� �Ѱ������� ���۷����� �Ѱܴ��� �𸣴�
						// Ref�� ǥ������ ��  
	printf("�̸��� %s�Դϴ�.\n", Name);
	free(Name);
}