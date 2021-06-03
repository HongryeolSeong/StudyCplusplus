#include <stdio.h>
// ������ �Լ�
// ���� ������ �Լ�

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

	/*const MyTest& operator -(const MyTest& other) const {
		MyTest res;

		res.x = this->x - other.x;
		res.y = this->y - other.y;

		return res;
	}*/

	//const MyTest& operator =(const MyTest& other) {
	//	x = other.x;
	//	y = other.y;

	//	return *this;	// �� ������ �Լ��� ���� �� ���Ͻ� 
	//					// ������ ������ �ȵǹǷ�
	//					// �ٸ� ���۷����� ������ ��ü�� ������ ��
	//}

	// ���� ������ �Լ� ������� ������ ����
	friend MyTest operator-(const MyTest& rhs1, const MyTest& rhs2);

	// ��� ���� ���
	void OutValue() {
		printf("%d, %d\n", x, y);
	}
};

// ���� ������ �Լ�
MyTest operator-(const MyTest& rhs1, const MyTest& rhs2) {
	MyTest res;

	res.x = rhs1.x - rhs2.x;
	res.y = rhs1.y - rhs2.y;

	return res;
}

int main()
{
	MyTest obj1(1, 2);
	MyTest obj2(3, 4);
	MyTest obj;
	obj = obj1 + obj2;			// 4, 6
	obj.OutValue();
	//obj = obj1.operator=(obj2);	// 3, 4
	//obj.OutValue();
	obj = obj2 - obj1;			// 2, 2
	obj.OutValue();

	return 0;
};