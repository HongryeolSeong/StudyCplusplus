#include <iostream>
#include <vector>
#include <algorithm>	// sort()�� ����ϱ� ����
using namespace std;

bool compare(int a, int b) { return a > b; }

int main()
{
	vector<int> ary;
	ary.push_back(10);
	ary.push_back(34);
	ary.push_back(61);
	ary.push_back(99);
	ary.push_back(2);

//	sort(ary.begin(), ary.end());			// ��������
	sort(ary.begin(), ary.end(), compare);	// ��������

	for (auto i = 0; i < ary.size(); i++)
	{
		cout << ary[i] << endl;
	}

	return 0;
}
