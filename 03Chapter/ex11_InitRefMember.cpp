#include <stdio.h>
// ��� �ʱ�ȭ ����Ʈ - ���۷���

class Some
{
public:
	int& total;	// ���۷��� �̹Ƿ�
	int n1, n2;
	// ��� �ʱ�ȭ ����Ʈ�� �ʱ�ȭ �� ��
	Some(int& atotal, int on1, int on2) : total(atotal) , n1(on1), n2(on2)
	{
		//this->total = atotal;	// �������� �ʱ�ȭx
	}
	void OutTotal() { printf("%d, %d, %d\n", total, n1, n2); }
};

int main()
{
	int value = 8;
	Some S(value, 1, 2);
	S.OutTotal();

	return 0;
}