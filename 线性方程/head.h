#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 10
#define EPS 1e-4

//ȫ�ֱ���

double A[MAX][MAX];
double b[MAX];
double X[MAX];
double Y[MAX];
double X0[MAX];
int NUM;

//��������

//��˹����Ԫ�������

void Input_Matrix();

//��˹����Ԫ��ȥ��

void Gauss();

//�������

void Input_Matrix1();

double NF2();

//�ſɱȵ���

void Jacobi();


//��˹ - ���¶�������

void Gauss_Seidel();


//SOR��

void SOR();
