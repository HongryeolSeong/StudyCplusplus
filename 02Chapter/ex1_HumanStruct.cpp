#include <iostream>
// ��� �Լ�

class/*struct*/ Human {
public:				// Ŭ���� ���ǽ�
	char name[20];	// ����ü ����� �⺻������ public���� ������
	float height;
	float weight;
	int age;
	char blood;
	void view();
};

void Human::view() // ��� �Լ� �ܺ� �ۼ��� ���� ���� ������ �� ��
{
	printf("%s %.1lf %.1lf %d %c", name, height, weight, age, blood);
}

int main()
{
	Human my = { "��ȫ��", 172, 65, 27, 'A' };
	//printf("%s %.1lf %.1lf %d %c", my.name, my.height, my.weight, my.age, my.blood);
	//����ü�� ���� ����
	my.view();
	return 0;
}