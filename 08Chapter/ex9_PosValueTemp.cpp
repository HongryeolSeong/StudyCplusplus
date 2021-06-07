#include "cursor.h"
#include <iostream>
using namespace std;
// Ŭ���� ���ø�

template <typename T>	// Ŭ���� ���ø��̹Ƿ�
class PosValue			// PosValue��� �̸������δ� ��ü ���� �Ұ�
{						// <Ÿ��>�� �ٿ��� ��ü ������ ��
private:
	int x, y;
	T value;
public:
	PosValue(int ax, int ay, T av) : x(ax), y(ay), value(av) {}
	void outvalue() {
		gotoxy(x, y);
		cout << value << endl;
	}
};

int main()
{
	PosValue<int> iv(10, 10, 2);		// <int>�� ����� ǥ���� ��
										// <>�� Ÿ�Կ� ���� �޸� �Ҵ�
	PosValue<char> cv(25, 5, 'C');
	PosValue<double> dv(30, 15, 3.14);
	iv.outvalue();
	cv.outvalue();
	dv.outvalue();
}