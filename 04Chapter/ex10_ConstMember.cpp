#include <stdio.h>
// ��� ���

class MathCalc
{
private:
	const double pie; // pie ���ȭ

public:
	MathCalc(double apie) : pie(apie) { } // ��� pie �ʱ�ȭ
	void DoCalc(double r) {
		printf("������ %.2f�� ���� �ѷ� = %.2f\n", r, r * 2 * pie);
	}
};

int main()
{
	MathCalc m(3.1416); // ��ü ������ ��� pie�� 3.1416���� �ʱ�ȭ
	m.DoCalc(5);
}