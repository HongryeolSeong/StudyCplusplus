#include <stdio.h>
#include <string.h>
// ���� �Ҵ� �޸��� ���� ����� ����
// �纻 ���� ����
// ������ �纻�� �����Ͱ� ���� ������ ����Ű�Ƿ�
// ���� �� �ı��� ������ �ȴ�.

class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1]; // ���� �Ҵ�
		strcpy(pname, aname);
		age = aage;
	}

	~Human() {
		delete[] pname;
	}

	void intro() {
		printf("�̸� = %s, ���� = %d\n", pname, age);
	}
};

int main()
{
	Human kang("������", 1424);
	Human boy = kang;

	boy.intro();
}