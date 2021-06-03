#include <stdio.h>
#include <string.h>

class Human
{
private:
	char* name;
	int age;

public:
	Human() { }

	// �μ� 2���� ������
	Human(const char *aname, int aage) {
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
		age = aage;
		printf("���̰� %d�� ��ü�� �����Ǿ����ϴ�.\n", age);
	}

	// ���� ������
	Human(const Human& other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
		printf("���� �����ڰ� ȣ��Ǿ����ϴ�.\n");
	}

	// �Ҹ���
	~Human() {
		delete[] name;
		printf("���̰� %d�� ��ü�� �Ҹ�Ǿ����ϴ�.\n", age);
	}

	// ������ �Լ�(������ �����ε�)
	const Human& operator =(const Human& other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;

		printf("���۷����� =�� ����Ǿ����ϴ�.\n");

		return *this;
	}

	void PrintHuman() {
		printf("�̸� : %s, ���� : %d\n\n", name, age);
	}
};


int main()
{
	Human h1("��ȫ��", 27);
	h1.PrintHuman();
	Human h2("�迵��", 25);
	h2.PrintHuman();

	Human h3(h1);
	h3.PrintHuman();

	Human Xman;
	Xman = h2;
	Xman.PrintHuman();

	return 0;
}