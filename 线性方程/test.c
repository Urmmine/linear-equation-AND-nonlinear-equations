#define _CRT_SECURE_NO_WARNINGS 1


#include "head.h"

//��˹����Ԫ��ȥ��

void Input_Matrix()//�������
{
    int i, j;
    printf("ϵ������A�Ľ���:\n");
    scanf("%d", &NUM);
    for (i = 1; i <= NUM; i++)
    {
        printf("ϵ������A�ĵ�%d��Ԫ��:\n", i);
        for (j = 1; j <= NUM; j++)
            scanf("%lf", &A[i - 1][j - 1]);
    }
    printf("�Ҷ���b:\n");
    for (i = 1; i <= NUM; i++)
    {
        scanf("%lf", &b[i - 1]);
    }
    printf("�����ϵ������A:\n");
    for (i = 0; i < NUM; i++)
    {
        for (j = 0; j < NUM; j++)
            printf("%lf\t", A[i][j]);
        printf("\n");
    }
    printf("������Ҷ���b:\n");
    printf("�������[A,b]:\n");
    for (i = 0; i < NUM; i++)
    {
        for (j = 0; j < NUM; j++)
            printf("%.4lf\t", A[i][j]);
        printf("%lf\t", b[i]);
        printf("\n");
    }
    printf("\n");
}

//��˹����Ԫ��ȥ��

void Gauss()
{
    Input_Matrix();
    int i, j, k, column;
    double max, A_temp, b_temp, mik, sum;
    for (k = 0; k < NUM - 1; k++)
    {
        column = k;
        max = 0;
        for (i = k; i < NUM; i++)
        {
            if (fabs(A[i][k]) > max)
            {
                max = fabs(A[i][k]);
                column = i;
            }
        }
        for (j = k; j < NUM; j++)
        {
            A_temp = A[k][j];
            A[k][j] = A[column][j];
            A[column][j] = A_temp;
        }
        b_temp = b[k];
        b[k] = b[column];
        b[column] = b_temp;
        for (i = k + 1; i < NUM; i++)//��Ԫ����
        {
            mik = A[i][k] / A[k][k];
            for (j = k; j < NUM; j++)
                A[i][j] -= mik * A[k][j];
            b[i] -= mik * b[k];
        }

    }
    printf("��Ԫ��ľ���:\n");
    for (i = 0; i < NUM; i++)
    {
        for (j = 0; j < NUM; j++)
            printf("%lf\t", A[i][j]);
        printf("%lf\t", b[i]);
        printf("\n");
    }
    printf("\n");
    X[NUM - 1] = b[NUM - 1] / A[NUM - 1][NUM - 1];
    for (i = NUM - 2; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < NUM; j++)
            sum += A[i][j] * X[j];
        X[i] = (b[i] - sum) / A[i][i];
    }
    printf("���X:\n");
    for (i = 0; i < NUM; i++)
    {
        printf("%lf\n", X[i]);
    }
}


//�ſɱȵ�����

void Input_Matrix1()//�������
{
    int i, j;
    printf("ϵ������A�Ľ���:\n");
    scanf("%d", &NUM);
    for (i = 1; i <= NUM; i++)
    {
        printf("ϵ������A�ĵ�%d��Ԫ��:\n", i);
        for (j = 1; j <= NUM; j++)
            scanf("%lf", &A[i - 1][j - 1]);
    }
    printf("�Ҷ���b:\n");
    for (i = 1; i <= NUM; i++)
    {
        scanf("%lf", &b[i - 1]);
    }
    printf("�����ϵ������A:\n");
    for (i = 0; i < NUM; i++)
    {
        for (j = 0; j < NUM; j++)
            printf("%.4lf\t", A[i][j]);
        printf("\n");
    }
    printf("������Ҷ���b:\n");
    for (i = 0; i < NUM; i++)
        printf("%.4lf\n", b[i]);
    printf("\n");
    printf("�����ֵX0:\n");
    for (i = 1; i <= NUM; i++)
    {
        scanf("%lf", &X0[i - 1]);
    }
}

double NF2()
{
    int i;
    double z, sum1 = 0;
    for (i = 0; i < NUM; i++)
    {
        sum1 += pow(Y[i] - X[i], 2);
    }
    z = sqrt(sum1);
    return z;
}

//�ſɱȵ�����

void Jacobi()
{
    int i, j;
    double sum;
    Input_Matrix1();
    for (i = 0; i < NUM; i++)
    {
        Y[i] = X0[i];
    }
    printf("\n");
    printf("�ſɱȵ�����\n");
    printf("������������:\n");
    do
    {
        for (i = 0; i < NUM; i++)
        {
            X[i] = Y[i];
        }
        for (i = 0; i < NUM; i++)
        {
            sum = 0;
            for (j = 0; j < NUM; j++)
            {
                if (j != i)
                    sum += A[i][j] * X[j];
            }
            Y[i] = (b[i] - sum) / A[i][i];
        }
        for (i = 0; i < NUM; i++)
        {
            printf("%lf\t", Y[i]);
        }
        printf("\n");
    } while (NF2() > EPS);
    printf("���������Ľ�:\n");
    for (i = 0; i < NUM; i++)
    {
        printf("%lf\t", Y[i]);
    }
    printf("\n");
}


//��˹�����¶�������

void Gauss_Seidel()
{
    int i, j;
    double sum;
    Input_Matrix1();
    for (i = 0; i < NUM; i++)
    {
        X[i] = X0[i];
        Y[i] = X0[i];
    }
    printf("\n");
    printf("��˹�����¶�������\n");
    printf("������������:\n");
    for (;;)
    {
        for (i = 0; i < NUM; i++)
        {
            sum = 0;
            for (j = 0; j < i; j++)
                sum += A[i][j] * Y[j];
            for (j = i + 1; j < NUM; j++)
                sum += A[i][j] * X[j];
            Y[i] = (b[i] - sum) / A[i][i];
        }
        for (i = 0; i < NUM; i++)
        {
            printf("%lf\t", Y[i]);
        }
        printf("\n");
        if (NF2() > EPS)
        {
            for (i = 0; i < NUM; i++)
                X[i] = Y[i];
        }
        else
            break;
    }
    printf("���������Ľ�:\n");
    for (i = 0; i < NUM; i++)
    {
        printf("%lf\t", Y[i]);
    }
    printf("\n");
}


//SOR��

void SOR()
{
    int i, j;
    double sum;
    Input_Matrix1();
    double w = 0;
    printf("���볬�ɳ�����:\n");
    scanf("%lf", &w);
    for (i = 0; i < NUM; i++)
    {
        X[i] = X0[i];
        Y[i] = X0[i];
    }
    printf("\n");
    printf("��˹�����¶�������\n");
    printf("������������:\n");
    for (;;)
    {
        for (i = 0; i < NUM; i++)
        {
            sum = 0;
            for (j = 0; j < i; j++)
                sum += A[i][j] * Y[j];
            for (j = i + 1; j < NUM; j++)
                sum += A[i][j] * X[j];
            Y[i] = w * (b[i] - sum) / A[i][i];
        }
        for (i = 0; i < NUM; i++)
        {
            printf("%lf\t", Y[i]);
        }
        printf("\n");
        if (NF2() > EPS)
        {
            for (i = 0; i < NUM; i++)
                X[i] = Y[i];
        }
        else
            break;
    }
    printf("���������Ľ�:\n");
    for (i = 0; i < NUM; i++)
    {
        printf("%lf\t", Y[i]);
    }
    printf("\n");
}


