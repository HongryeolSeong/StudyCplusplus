#include <stdio.h>
// Ŭ������ ��2

class Date
{
private:
	int year, month, day;

public:
	void SetDate(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}

	void OutDate() {
		printf("���� ��¥�� %d�� %d�� %d���Դϴ�.\n", year, month, day);
	}
};

int main()
{
	Date today;

	today.SetDate(2021, 05, 31);
	today.OutDate();

	return 0;
}