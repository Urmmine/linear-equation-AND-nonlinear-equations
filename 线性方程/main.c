#define _CRT_SECURE_NO_WARNINGS 1
#include "head.h"

int main()
{
	//��˹����Ԫ��ȥ��
	printf("5.1��:\n");
	Gauss();


    //�ſɱȵ�����
	printf("5.5��:\n");
	Jacobi();


	//��˹ - ���¶�������
	Gauss_Seidel();


	//SOR��
	SOR();


	return 0;
}