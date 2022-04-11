#define _CRT_SECURE_NO_WARNINGS 1


#include "head.h"

//简单迭代法

void Simple_Iterate()
{
	int i;
	double x0 = 0;
	printf("请输入初值x0开始简单迭代法：\n");
	scanf("%lf", &x0);
	double x_k = x0, x_k1 = x0;
	printf("	k	xk\n");
	for (i = 0; i < MAXREPT; i++)
	{
		printf("	%d	%lf\n", i, x_k1);
		x_k1 = G(x_k);
		if (fabs(x_k1 - x_k) < EPS)
		{
			printf("用简单迭代法方程的根是 %lf ，经过 %d 次迭代\n", x_k1, i);
			return;
		}
		x_k = x_k1;
	}
	printf("经过 %d 次迭代后无法解决\n", MAXREPT);
}

//埃特金迭代法

void Aitken()
{
	int i;
	double x0 = 0;
	printf("请输入初值x0开始埃特金迭代法：\n");
	scanf("%lf", &x0);
	double x1 = x0, x2 = x0;
	double y, z;
	printf("	k	xk\n");
	for (i = 0; i < MAXREPT; i++)
	{
		printf("	%d	%lf\n", i, x2);
		y = G(x1);
		z = G(y);
		x2 = z - ((z - y) * (z - y)) / (z - 2 * y + x1);
		if (fabs(x2 - x1) < EPS)
		{
			printf("用埃特金迭代法方程的根是 %lf ，经过 %d 次迭代\n", x2, i);
			return;
		}
		x1 = x2;
	}
	printf("经过 %d 次迭代后无法解决\n", MAXREPT);
}

//牛顿迭代法

void Newton(const double x0)
{
	int i ;
	double x_k = x0, x_k1 = x0;
	printf("	k	xk\n");
	for (i = 0; i < MAXREPT; i++)
	{
		printf("	%d	%lf\n", i, x_k1);
		x_k1 = F(x_k);
		if (fabs(x_k1 - x_k) < EPS1)
		{
			printf("x0取 %lf 时，方程的根是 %lf ，经过 %d 次迭代\n",x0, x_k1, i);
			double ans = F(x_k1);
			printf("%lf\n", ans);
			return;
		}
		x_k = x_k1;
	}
	printf("经过 %d 次迭代后无法解决\n", MAXREPT);
}



//弦截法

double f(double x)
{
	return (1-x-sin(x));
}

void Secan()
{
	double x1, x2, xx;
	do
	{
		printf("请输入x1和x2的值:\n");
		scanf("%lf %lf", &x1, &x2);
	} 
	while ((f(x1) * f(x2)) > 0);//保证f(x1)和f(x2)是异号，这样才可以进行下一步的精准区间，否则，重新输入x1，x2的值
	do
	{
		xx = ((x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1)));
		if (f(xx) * f(x1) > 0)
			x1 = xx;
		else if (f(xx) * f(x2) > 0)
			x2 = xx;
	}
	while (fabs(f(xx)) >= EPS2);
	printf("%.3lf\n", xx);//保留3位小数
}