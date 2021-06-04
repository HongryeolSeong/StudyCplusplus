#include <stdio.h>
#include <string.h>
// 객체 포인터

class Human
{
protected:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}

	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

class Student : public Human
{
protected:
	int stunum;

public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}

	void intro() {
		printf("%d학번 %s입니다.\n", stunum, name);
	}

	void study() {
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
};

int main()
{
	Human h("김사람", 10);
	Student s("이학생", 15, 1234567);
	Human* pH;
	Student* pS;

	pH = &h;
	pS = &s;
	pH = &s;
	
	//pS = &h;			// 자식 -> 부모 x
	pS = (Student*)&h;	// 형변환 통해 자식 -> 자식
	pS->intro();
}