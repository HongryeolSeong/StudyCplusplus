#include <stdio.h>
#include <string.h>
// �������� ���� Ÿ��
// �Լ� �տ� virtual ���� �����Ͱ� ����Ű�� ��ü Ÿ�Կ� ���� �Լ� ȣ��

class Human
{
protected:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}

	virtual void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}

};

class Student : public Human
{
protected:
	int stunum;

public:

	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}

	virtual void intro() {		// �ڽ��� virtual ���� ����
		printf("%d�й� %s�Դϴ�.", stunum, name);
	}

	void study() {
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}
};

int main()
{
	Human h("����", 10);
	Student s("���л�", 15, 1234567);
	Human* pH;

	pH = &h;
	pH->intro();
	pH = &s;
	pH->intro();	// virtual ����� : ���� Ÿ������ Human::intro()�� ȣ�� �ȴ�
					// virtual ����� : ���� Ÿ������ Student::intro()�� ȣ�� �ȴ�
}