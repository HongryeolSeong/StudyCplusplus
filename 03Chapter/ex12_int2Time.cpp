#include <stdio.h>
// ��ȯ ������ : type -> obj

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	// ��ȯ ������
	// �ӽð�ü ���� �� ��ȯ�Ͽ� ����� ����
	explicit Time(int abssec)	// ����� ��ȯ���� ����ϱ� ���� explicit���
	{
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void OutTime()
	{
		printf("���� �ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
};

void printTime(Time when)
{
	when.OutTime();
}

int main()
{
	Time noon(40000);	// �����ڸ� ����� ȣ��
	noon.OutTime();
	/*Time now = 60000;	// Ÿ�� ��ȯ�� ���� ������ ȣ��
	now.OutTime();		// -> ��ȣ���� �ִ°�� explicit�� ȣ���� ������
	now = 70000;
	now.OutTime();

	printTime(80000);*/

	return 0;
}