#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("char array");
	string s2("char array2");

	cout << s.data() << endl;	// �� �ڿ� �ι��� ����x
	cout << s.c_str() << endl;	// �� �ڿ� �ι��� ����(c��Ÿ��)

	char str[128];
	strcpy(str, s.c_str());
	printf("str = %s\n", str);

	swap(s, s2);
	cout << s << ", " << s2 << endl;
}