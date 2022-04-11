#define _CRT_SECURE_NO_WARNINGS 1
#include "head.h"

int main()
{
	//高斯列主元消去法
	printf("5.1题:\n");
	Gauss();


    //雅可比迭代法
	printf("5.5题:\n");
	Jacobi();


	//高斯 - 赛德尔迭代法
	Gauss_Seidel();


	//SOR法
	SOR();


	return 0;
}