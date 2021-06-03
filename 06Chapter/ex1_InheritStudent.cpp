#include <stdio.h>
#include <string.h>
// ��� : ��κ� public���� ��ӹ޴´�
// 1. �Ļ� Ŭ������ ������ ȣ��
// 2. �θ� Ŭ������ ������ ȣ�� �� ����
// 3. �Ļ� Ŭ������ ������ ����

class Human
{
private:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	
	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

class Student : public Human
{
private:
	int stunum;

public:												// �θ�Ŭ������ �μ��� 2���� ������ ȣ��
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}

	void study() {
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}

	// �Ұ� : �θ��� ����� private�̹Ƿ�
	/*void report() {
		printf("�̸� : %s, �й� : %d ���� �����մϴ�.\n", name, stunum);
	}*/
};

int main()
{
	Human kim("�����", 29);
	kim.intro();
	Student han("���Ѱ�", 15, 123456);
	han.intro();
	han.study();
}