#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"


int main()
{
	printf("6.3题:\n");
	//普通迭代法
	Simple_Iterate();

	//埃特金法
	Aitken();

	//牛顿迭代法
	printf("6.5题:\n");
	printf("输入6.5开始牛顿迭代法程序:\n");
	float input = 0;
	scanf("%f", &input);
	if (input == 6.5)
	{
		Newton(PI);
		Newton(PI / 2);
	}


	//弦截法
	printf("6.9题:\n");
	void Secan();

	return 0;
}