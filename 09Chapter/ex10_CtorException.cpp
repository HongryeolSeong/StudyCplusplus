#include <stdio.h>
// 생성자와 연산자의 예외

class Int100
{
private:
	int num;

public:
	Int100(int a) {
		if (a <= 100) {
			num = a;
		}
		else {
			throw a;
		}
	}
	Int100& operator+=(int b) {
		if (num + b <= 100) {
			num += b;
		}
		else {
			throw num + b;
		}
		return *this;
	}
	void OutValue() {
		printf("%d\n", num);
	}
};

int main()
{
	try {
		Int100 i(101);
		i += 12;
		i.OutValue();
	}
	catch (int n) {
		printf("%d는 100보다 큰 정수이므로 다룰 수 없습니다.\n", n);
	}
}