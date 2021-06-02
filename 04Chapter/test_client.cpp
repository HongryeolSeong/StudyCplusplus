#include <stdio.h>
#include <string.h>

class CMember
{
private:
	char *name;
	char *pnum;
	char *address;
	static int cnt;

public:
	CMember() { cnt++; }
	~CMember() { cnt--; }
	static void InitCount() {
		cnt = 0;
	}
	static void Outcount() {
		printf("���� ȸ�� �� = %d\n", cnt);
	}
	void setData(const char *aname, const char* apnum, const char *aaddress)
	{
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
		pnum = new char[strlen(apnum) + 1];
		strcpy(pnum, apnum);
		address = new char[strlen(aaddress) + 1];
		strcpy(address, aaddress);
	}
	void getData() {
		printf("�̸� : %s, ��ȭ ��ȣ : %s, �ּ� : %s\n", name, pnum, address);
	}
};

int CMember::cnt = 0;		// static ��� ���� cnt �ʱ�ȭ

int main()
{
	CMember::InitCount();
	CMember::Outcount();

	CMember c1;
	c1.setData("��ȫ��", "01077590276", "�λ�� ������");
	c1.getData();
	CMember::Outcount();

	CMember c2, *pc2;
	c2.setData("�迵��", "01012345678", "���� ��굿");
	c2.getData();
	pc2 = &c2;
	CMember::Outcount();
	delete pc2;
	CMember::Outcount();


	return 0;
}