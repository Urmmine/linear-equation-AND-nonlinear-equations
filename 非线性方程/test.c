#define _CRT_SECURE_NO_WARNINGS 1


#include "head.h"

//�򵥵�����

void Simple_Iterate()
{
	int i;
	double x0 = 0;
	printf("�������ֵx0��ʼ�򵥵�������\n");
	scanf("%lf", &x0);
	double x_k = x0, x_k1 = x0;
	printf("	k	xk\n");
	for (i = 0; i < MAXREPT; i++)
	{
		printf("	%d	%lf\n", i, x_k1);
		x_k1 = G(x_k);
		if (fabs(x_k1 - x_k) < EPS)
		{
			printf("�ü򵥵��������̵ĸ��� %lf ������ %d �ε���\n", x_k1, i);
			return;
		}
		x_k = x_k1;
	}
	printf("���� %d �ε������޷����\n", MAXREPT);
}

//���ؽ������

void Aitken()
{
	int i;
	double x0 = 0;
	printf("�������ֵx0��ʼ���ؽ��������\n");
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
			printf("�ð��ؽ���������̵ĸ��� %lf ������ %d �ε���\n", x2, i);
			return;
		}
		x1 = x2;
	}
	printf("���� %d �ε������޷����\n", MAXREPT);
}

//ţ�ٵ�����

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
			printf("x0ȡ %lf ʱ�����̵ĸ��� %lf ������ %d �ε���\n",x0, x_k1, i);
			double ans = F(x_k1);
			printf("%lf\n", ans);
			return;
		}
		x_k = x_k1;
	}
	printf("���� %d �ε������޷����\n", MAXREPT);
}



//�ҽط�

double f(double x)
{
	return (1-x-sin(x));
}

void Secan()
{
	double x1, x2, xx;
	do
	{
		printf("������x1��x2��ֵ:\n");
		scanf("%lf %lf", &x1, &x2);
	} 
	while ((f(x1) * f(x2)) > 0);//��֤f(x1)��f(x2)����ţ������ſ��Խ�����һ���ľ�׼���䣬������������x1��x2��ֵ
	do
	{
		xx = ((x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1)));
		if (f(xx) * f(x1) > 0)
			x1 = xx;
		else if (f(xx) * f(x2) > 0)
			x2 = xx;
	}
	while (fabs(f(xx)) >= EPS2);
	printf("%.3lf\n", xx);//����3λС��
}