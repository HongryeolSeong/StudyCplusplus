#include <stdio.h>
#include <string.h>
// ����Ʈ ������ ���°���� ����

class Human
{
private:
	char name[12];
	int age;

public:
	/*Human() {
		strcpy(name, "�̸� ����");
		age = 0;
	}*/
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main()
{
	//Human momo;			// �ش��ϴ� �����ڰ� �����Ƿ�
	//Human arFriend[3];	// ����

	Human arFriend[3] = {
		{ Human("������", 49)},
		{ Human("������", 49)},
		{ Human("�ڻ�", 49)}
	};

	//momo.intro();
	arFriend[2].intro();
}