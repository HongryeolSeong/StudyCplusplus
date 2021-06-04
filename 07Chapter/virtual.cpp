#include <iostream>
using namespace std;
// ��ü �����͸� ���� ���� �Լ��� �ʿ伺 ����
// ���� �Լ� : 
// �ش� �������� �ڷ������� ���� Ŭ������ ��ü�� �����ϱ� ���� �Լ�

class A
{
public:
	void AFunc() {
		cout << "A::AFunc()" << endl;
	}
};

class B : public A
{
public:
	void BFunc() {
		cout << "B::BFunc()" << endl;
	}
};

class C : public B
{
public:
	void CFunc() {
		cout << "C::CFunc()" << endl;
	}
};

int main()
{
	// �θ� -> �ڽ�
	A* pa = new C;	// ���� Ŭ���� Ÿ���� �����Ͱ� �Ļ� ��ü�� ����Ű�� �ִ�. A -> C
	pa->AFunc();	// AŬ���� Ÿ�� �������̹Ƿ� C���� ��ӵ� A�κи� ����ų �� �ִ�.

	B* pb = new C;
	pb->AFunc();	// BŬ���� Ÿ�� �����ͷ� B�� B���� ��ӵ� A���� ����ų �� �ִ�.
	pb->BFunc();

	C* pc = new C;
	pc->AFunc();
	pc->BFunc();
	pc->CFunc();

	//C* pcc = new A;	// �ڽ� -> �θ��̹Ƿ� �Ұ�

	return 0;
}