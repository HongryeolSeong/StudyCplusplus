#include <stdio.h>
// this ������ : ������ �ڱ� �ڽ����� ������ ������ ���

class Simple
{
private:
	int value;

public:
	Simple(int avalue) : value(avalue) { }	// ��� �ʱ�ȭ ����Ʈ
	void OutValue() {
		printf("value = %d\n", value);
	}
};

int main()
{
	Simple A(1), B(2);
	A.OutValue();
	B.OutValue();

	return 0;
}