#include <stdio.h>

class MyTest
{
private:
	int x, y;

public:
	MyTest(int ax = 0, int ay = 0) 
	{ 
		x = ax;
		y = ay;
		printf("�μ� 2��¥�� ������!!\n");
	}

	MyTest(MyTest& other) : x(other.x), y(other.y)
	{
		printf("���� ������ ȣ��!!\n");
	}

	const MyTest& operator +(const MyTest& other) const {
		MyTest res;

		res.x = this->x + other.x;
		res.y = this->y + other.y;

		return res; // �ӽ� ��ü ���� -> ���� �����ڰ� ȣ��
					// ������ ���Ͻ� ���� ������ ȣ��x
					// ���(��ȯ)�� ������ Ÿ������ �� ��
	}

	void OutValue() {
		printf("%d, %d\n", x, y);
	}
};

int main()
{
	MyTest obj1(1, 2);
	MyTest obj2(3, 4);
	MyTest obj;
	obj = obj1 + obj2;
	obj.OutValue();

	return 0;
};