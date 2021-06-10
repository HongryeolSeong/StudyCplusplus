#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("C++ stinrg");

	cout << s << "문자열의 길이 = " << s.size() << endl;
	cout << s << "문자열의 길이 = " << s.length() << endl;
	cout << s << "문자열의 할당 크기 = " << s.capacity() << endl;
	cout << s << "문자열의 최대 길이 = " << s.max_size() << endl;

	s.resize(6);
	cout << s << " 길이 = " << s.size() << ", 할당 크기 = " << s.capacity() << endl;

	s.reserve(100);
	cout << s << " 길이 = " << s.size() << ", 할당 크기 = " << s.capacity() << endl;
	cout << s.at(0) << endl;
	cout << s[0] << endl;

	s.clear();
	cout << s << endl;
}