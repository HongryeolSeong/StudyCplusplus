#include <stdio.h>
// ��� �ʱ�ȭ ����Ʈ - ���

class Some
{
public:
	const int total;						// ����̹Ƿ�
	Some(int atotal) : total(atotal) {}		// �̷������� �ʱ�ȭ�ؾ���
	//some(int atotal) {					// ���Կ������� �ʱ�ȭ�ϸ� �ȵ�
	//	total = atotal;
	//}
	void OutTotal() { printf("%d\n", total); }
};

int main()
{
	Some S(5);
	S.OutTotal();

	return 0;
}