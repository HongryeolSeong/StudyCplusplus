#include <stdio.h>
// mutable : ����� ���� ���� �ְ� ������ ���ϴ� ��Ģ�� ���ܸ� ����
//			 ������ ��ü�� ������� ������� ������ ���� ����

class Some
{
private:
	mutable int temp;	// mutable ����

public:
	Some() { }
	void method() const { temp = 0; }
};

int main()
{
	Some s;
	s.method();

	const Some t;		// ��ü ���ȭ
	t.method();
}