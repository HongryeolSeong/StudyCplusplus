#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class Human
{
private:
//protected:
	char* name;

public:
	Human(const char * aname) { 
		name = new char[strlen(aname) + 1];
		strcpy_s(name, strlen(aname) + 1, aname);
	}

	~Human() { 
		delete[] name;
	}

	void printname() {
		cout << "My name is " << name << endl;
	}
};

class Student : public Human
{
private:
	char* major;

public:
	Student(const char* aname, const char* amajor) : Human(aname) {
		major = new char[strlen(amajor) + 1];
		strcpy_s(major, strlen(amajor) + 1, amajor);
	}

	~Student() {
		delete[] major;
	}

	void printmajor() {
		// �θ��� ��� ������ proteced �̸�
		//cout << "My name is " << name << ", " << "My Major is " << major << endl;
		
		printname();
		cout << "My Major is " << major << endl;
	}
};

int main()
{
	Human my("ȫ�浿");
	my.printname();

	Student s("��ȫ��", "IoT");
	s.printmajor();	// Myname is ��ȫ�� \n My Major is IoT


	return 0;
}