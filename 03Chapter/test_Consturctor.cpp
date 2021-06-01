#include <iostream>

class CTest {
private:
	int m_num;
	int* ptr;
public:
	// ����Ʈ ������
	CTest() {
		printf("����Ʈ ������ ȣ��\n");
	}
	// �μ��� �ϳ� ������ ������(��ȯ ������)
	CTest(int num) {
		m_num = num;
		printf("������ ȣ�� : %d\n", m_num);
	}
	// �μ� �� ���� ������ ������
	CTest(int num, int* ptr) {
		this->m_num = num;
		this->ptr = new int;	// ���� �Ҵ�
		this->ptr = ptr;
		printf("�μ� 2�� ������ ȣ�� : %d, %p\n", m_num, ptr);
	}
	// ���� ���縦 �ϴ� ���� ������
	CTest(CTest& other) {
		this->m_num = other.m_num;
		this->ptr = new int;	// ���� �Ҵ�
		this->ptr = other.ptr;
		printf("���� ������ ȣ�� : %d, %p\n", m_num, ptr);
	}
	// ���� ���� ������
	/*CTest(CTest &other) {
		this->m_num = other.m_num;
		printf("���� ������ ȣ�� : %d\n", m_num);
	}*/
	// �Ҹ���
	~CTest() {
		printf("�Ҹ��� ȣ�� : %d\n", m_num);
		delete ptr;				// ���� �Ҵ��� ��� �Ҹ��ڿ��� ������Ų��.
	}
	void getData() {
		printf("%d\n", m_num);
	}
};

int main()
{
	// �⺻ �ڷ���
	int a = 10;
	int b(20);	//cpp���� ���Ǵ� ����
	int c(a);

	printf("%d, %d, %d\n", a, b, c);

	// ����� �ڷ���
	CTest c1(100);	// �μ� �� ���� ������ ȣ��, ������ ������ ����
	CTest c2;		// ����Ʈ ������ ȣ��, ������ ������ ����Ʈ ������ �����⶧���� ����
	CTest c3(c1);	// ���� ������ ȣ��(���� ����) - �ּҸ� ������(������ ���޹ޱ� ������)
	CTest c4(50, nullptr);

	//c1.getData();
	//c2.getData(); // �����Ⱚ
	//c3.getData();
	
	return 0;
}