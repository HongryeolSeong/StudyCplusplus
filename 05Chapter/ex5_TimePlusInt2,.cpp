#include <stdio.h>
// ��ü�� �⺻���� ����
// 1 + now ���� �Ұ� �ذ�

class Time
{
	friend const Time operator +(int s, const Time& me);
private:
	int hour, min, sec;

public:
	Time() { }
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}
};

// 1 + now ���� ������ ������ �Լ�
const Time operator +(int s, const Time& me) {
	Time t = me;

	t.sec += s;

	t.min += t.sec / 60;
	t.sec %= 60;
	t.hour += t.min / 60;
	t.min %= 60;

	return t;
}

int main()
{
	Time now(11, 22, 33);
	now.OutTime();
	now = 1 + now;
	//now = now + 1;	// �Ұ� : operator +(int, Time) �����̹Ƿ� �Ұ�
						//		  -> ex6���� �ذ�
	now.OutTime();
}