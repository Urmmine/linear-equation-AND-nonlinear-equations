#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXREPT 1000//迭代次数
#define EPS 1e-5//精度
#define EPS1 1e-4//精度
#define EPS2 1e-6
#define PI acos(-1)
#define G(x) (cos(x)+sin(x))/2.0//迭代函数；将原方程化为x=G(x)。
#define F(x) 2*sin(x)


//函数声明


//普通迭代法

void Simple_Iterate();


//埃特金迭代法

void Aitken();


//牛顿迭代法

void Newton(const double);


//弦截法

void Secan();
