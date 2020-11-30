#include <cstdio>
#include <math.h>
#include <locale.h>
#include "Function.h"

float func_cos(float x) {
    return cosf(x);
}

float func_sin(float x) {
        return sinf(x);
    }

float func_exp(float x) {
    return expf(x);
}

float func_log(float x) {
    return log(fabsf(x));
}

float average(float* x, int n, float zn, func f) {
    float val = 0; float k = 0;
    bool check = true;
    for (int i = 0; i < n; i++) {
        if ( f(x[i]) > zn) {
            check = false;
            val += f(x[i]);
            k++;
        }
    }
    if (!check) val /= k;
    else val = zn;
    return val;
}

void input(FILE* f_in, float* x, int n) {
    for (int i = 0; i < n; i++) {
        fscanf_s(f_in, "%f", &x[i]);
    }
}

void output(FILE* f_out, float* x, int n, func f) {
    for (int i = 0; i < n; i++) {
        fprintf(f_out, "%.3f ", f(x[i]) );
    }
    printf("\n");
}

void size_check(int& n) {
    while (n > 100 || n < 1) {
        printf("������� ���������� �������� (�� 1 �� 100) \n");
        scanf_s("%d", &n);
    }
}

void sravn(float av_a, float av_b, float av_c, FILE* f, float zn) {

    if (av_a == zn && av_b == zn && av_c == zn) {
        fprintf(f, "� �������� ��� ��������� ������� ��������� �����. \n");
    }
    else if (av_b == zn && av_c == zn) {
        fprintf(f, "� ������� � ������ ������� �������������� (� �������� B � C ��� ���������� ���������: %.2f \n)", av_a);
    }
    else if (av_a == zn && av_c == zn) {
        fprintf(f, "� ������� B ������ ������� �������������� (� �������� � � C ��� ���������� ���������: %.2f \n)", av_b);
    }
    else if (av_a == zn && av_b == zn) {
        fprintf(f, "� ������� � ������ ������� �������������� (� �������� A � B ��� ���������� ���������: %.2f \n)", av_c);
    }
    else if (av_a == zn)
    {
        if (av_b < av_c)
            fprintf(f, "� ������� B ������ ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_b);
        else
            fprintf(f, "� ������� � ������ ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_c);
    }
    else if (av_b == zn)
    {
        if (av_a < av_c)
            fprintf(f, "� ������� A ������ ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_a);
        else
            fprintf(f, "� ������� � ������ ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_c);
    }
    else if (av_c == zn)
    {
        if (av_a < av_b)
            fprintf(f, "� ������� A ������ ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_a);
        else
            fprintf(f, "� ������� B ������ ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_b);
    }
    else if (av_a == av_b && av_b == av_c) {
        fprintf(f, "� �������� A � B � � ������ ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_a);
    }
    else if (av_a == av_b)
    {
        if (av_a < av_c)
            fprintf(f, "� ������� � � B ������ ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_a);
        else
            fprintf(f, "� ������� � ������ ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_c);
    }
    else if (av_a == av_c)
    {
        if (av_a < av_b)
            fprintf(f, "� ������� � � C ������ ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_a);
        else
            fprintf(f, "� ������� B ������ ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_b);
    }
    else if (av_b == av_c)
    {
        if (av_b < av_a)
            fprintf(f, "� ������� B � C ������ ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_b);
        else
            fprintf(f, "� ������� A ������ ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_a);
    }
    else if (av_a < av_b && av_a < av_c) {
        fprintf(f, "� ������� � ���������� ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_a);
    }
    else if (av_b < av_a && av_b < av_c) {
        fprintf(f, "� ������� B ���������� ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_b);
    }
    else  if (av_c < av_a && av_c < av_b) {
        fprintf(f, "� ������� C ���������� ������� �������������� ���������, ������� ��������� �����: %.2f \n", av_c);
    }
    printf("\n");
}