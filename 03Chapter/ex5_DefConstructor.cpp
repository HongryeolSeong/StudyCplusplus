#include <stdio.h>
#include <string.h>
// ����Ʈ ������

class Human
{
private:
	char name[12];
	int age;

public:
	Human() {
		strcpy(name, "�̸�����");
		age = 0;
	}
	void intro() {
		printf("�̸� = %s, ���� =%d\n", name, age);
	}
};

int main()
{
	Human momo; // Human momo(); -> x
	momo.intro();
}