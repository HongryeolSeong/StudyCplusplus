#include <stdio.h>
#include <conio.h>
#include <string.h>
// 중첩 예외 처리기

int main()
{
	int num;
	int age;
	char name[128];

	try
	{
		printf("학번을 입력하시오 : ");
		scanf("%d", &num);
		if (num <= 0) throw num;
		try
		{
			printf("이름을 입력하시오 : ");
			scanf("%s", name);
			if (strlen(name) < 4) throw "이름이 너무 짧습니다.";
			printf("나이를 입력하시오 : ");
			scanf("%d", &age);
			if (age <= 0) throw age;
			printf("입력한 정보 => 학번:%d, 이름:%s, 나이:%d\n", num, name, age);
		}
		catch (const char *Message)
		{
			puts(Message);
		}
		catch (int)	// 이 catch 밖에 동일한 타입(int)의 catch가 있다면
		{			// 거기로 던져줌
			throw;
		}
	}
	catch (int n)
	{
		printf("%d는 음수이므로 적합하지 않습니다.\n", n);
	}

	return 0;
}