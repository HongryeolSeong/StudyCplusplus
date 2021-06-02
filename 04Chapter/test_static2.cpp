#include <iostream>
// static ��� ���� / �Լ�

class StaticTest {
	static int a;				// static ��� ����
	int b;
public:
	StaticTest();
	static void setData(int);	// static ��� �Լ��� static ��� ������ ����Ѵ�.
	void getData();
};

int StaticTest::a = 10;			// static ��� ���� �ʱ�ȭ

StaticTest::StaticTest()
{
	b = 20;						//this->b = 20;�� ��Ȯ�� ��
}

void StaticTest::getData()
{
	printf("a : %d, b : %d\n", a, b);
}

void StaticTest::setData(int aa)
{
	a = aa;						//this->a = a;; ---> X
}								//a�� static�̹Ƿ� ��ü�� ������ �ƴϴ�.

int main()
{
	StaticTest s1;
	s1.getData();
	StaticTest s2;
	s2.getData();

	s1.setData(30);
	s1.getData();				// s1�� a�� 30
	s2.getData();				// s2�� a�� 30�̴�.

	StaticTest::setData(77);	// a�� �����ǹǷ� s1, s2 �� �� a�� �ٲ��.
	s1.getData();
	s2.getData();

	return 0;
}