#include <iostream>
using namespace std;
// Ŭ���� ���ø�(�Ϲ�ȭ)

template <typename T>
class CTest
{
private:
	int num;
public:
//	CTest(T anum) : num(anum) { };
	CTest(T);	// �ۿ��� �����
	void printData() {
		cout << "num : " << num << endl;
	}
};

template <typename T>	// ���ø� ���� �� �� �� �Ѵ�.
CTest<T>::CTest(T anum) {
	num = anum;
}

int main()
{
//	CTest obj(10); CTest�� ���ø��̹Ƿ� �̸������δ� ��ü ���� �Ұ�
	CTest<int> obj(10);
	obj.printData();
	
	return 0;
}