#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"


int main()
{
	printf("6.3��:\n");
	//��ͨ������
	Simple_Iterate();

	//���ؽ�
	Aitken();

	//ţ�ٵ�����
	printf("6.5��:\n");
	printf("����6.5��ʼţ�ٵ���������:\n");
	float input = 0;
	scanf("%f", &input);
	if (input == 6.5)
	{
		Newton(PI);
		Newton(PI / 2);
	}


	//�ҽط�
	printf("6.9��:\n");
	void Secan();

	return 0;
}