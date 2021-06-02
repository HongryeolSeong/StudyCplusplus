#include <stdio.h>
// static ��� ���� / �Լ�

class Simple
{
private:
	int value;
	static int count;

public:
	Simple() { count++; }
	~Simple() { count--; }
	static void InitCount() {
		count = 0;
	}
	static void Outcount() {
		printf("���� ��ü ���� = %d\n", count);
	}
};

int Simple::count;

int main()
{
	Simple::InitCount();
	Simple::Outcount();
	Simple s, * ps;
	Simple::Outcount();
	ps = new Simple;
	Simple::Outcount();
	delete ps;
	Simple::Outcount();
	printf("ũ�� = %d\n", sizeof(s));
}