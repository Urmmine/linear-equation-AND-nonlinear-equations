#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXREPT 1000//��������
#define EPS 1e-5//����
#define EPS1 1e-4//����
#define EPS2 1e-6
#define PI acos(-1)
#define G(x) (cos(x)+sin(x))/2.0//������������ԭ���̻�Ϊx=G(x)��
#define F(x) 2*sin(x)


//��������


//��ͨ������

void Simple_Iterate();


//���ؽ������

void Aitken();


//ţ�ٵ�����

void Newton(const double);


//�ҽط�

void Secan();
