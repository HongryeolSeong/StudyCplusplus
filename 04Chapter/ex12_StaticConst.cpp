#include <stdio.h>
// ��� + static ���

class MathCalc
{
private:
	static const double pie;			// pie ���ȭ + static

public:
	MathCalc() { }
	void DoCalc(double r) {
		printf("������ %.2f�� ���� �ѷ� = %.2f\n", r, r * 2 * pie);
	}
};

const double MathCalc::pie = 3.1416;	// pie�� static �����̹Ƿ� Ŭ���� �ۿ��� �ʱ�ȭ

int main()
{
	MathCalc m;
	m.DoCalc(5);
}