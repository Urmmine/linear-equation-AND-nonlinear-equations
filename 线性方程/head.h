#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 10
#define EPS 1e-4

//全局变量

double A[MAX][MAX];
double b[MAX];
double X[MAX];
double Y[MAX];
double X0[MAX];
int NUM;

//函数声明

//高斯列主元输入矩阵

void Input_Matrix();

//高斯列主元消去法

void Gauss();

//输入矩阵

void Input_Matrix1();

double NF2();

//雅可比迭代

void Jacobi();


//高斯 - 塞德尔迭代法

void Gauss_Seidel();


//SOR法

void SOR();
