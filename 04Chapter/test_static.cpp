#include <iostream>
// ���� ��� ���� : ��ü�� ���� ����� ����. ��ü���� ���� x
//					�ܺο��� �ʱ�ȭ �� ��

class StaticTest {
public:
	int a;
	static int b;		// static ��� ���� ����
	StaticTest() {
		a = 10;
		//b = 20; // �Ұ�
		b++;			// ��ü �������� +1
	}
	void getData() {
		printf("a : %d, b: %d\n", a, b);
	}
};

int StaticTest::b = 20;	// static ��� ���� �ʱ�ȭ
						// �ܺο��� �� ��
						// ��� ������ �Ҽӵ� Ŭ������ ǥ�� �� ��

int main()
{
	StaticTest s1;
	s1.getData();
	StaticTest s2;
	s2.getData();

	return 0;
}