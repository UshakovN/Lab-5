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
        printf("Введите корректное значение (от 1 до 100) \n");
        scanf_s("%d", &n);
    }
}

void sravn(float av_a, float av_b, float av_c, FILE* f, float zn) {

    if (av_a == zn && av_b == zn && av_c == zn) {
        fprintf(f, "В массивах нет элементов больших заданного числа. \n");
    }
    else if (av_b == zn && av_c == zn) {
        fprintf(f, "В массиве А меньше среднее арифметическое (В массивах B и C нет подходящих элементов: %.2f \n)", av_a);
    }
    else if (av_a == zn && av_c == zn) {
        fprintf(f, "В массиве B меньше среднее арифметическое (В массивах А и C нет подходящих элементов: %.2f \n)", av_b);
    }
    else if (av_a == zn && av_b == zn) {
        fprintf(f, "В массиве С меньше среднее арифметическое (В массивах A и B нет подходящих элементов: %.2f \n)", av_c);
    }
    else if (av_a == zn)
    {
        if (av_b < av_c)
            fprintf(f, "В массиве B меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
        else
            fprintf(f, "В массиве С меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_c);
    }
    else if (av_b == zn)
    {
        if (av_a < av_c)
            fprintf(f, "В массиве A меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
        else
            fprintf(f, "В массиве С меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_c);
    }
    else if (av_c == zn)
    {
        if (av_a < av_b)
            fprintf(f, "В массиве A меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
        else
            fprintf(f, "В массиве B меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
    }
    else if (av_a == av_b && av_b == av_c) {
        fprintf(f, "В массивах A и B и С равные среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
    }
    else if (av_a == av_b)
    {
        if (av_a < av_c)
            fprintf(f, "В массиве А и B меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
        else
            fprintf(f, "В массиве С меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_c);
    }
    else if (av_a == av_c)
    {
        if (av_a < av_b)
            fprintf(f, "В массиве А и C меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
        else
            fprintf(f, "В массиве B меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
    }
    else if (av_b == av_c)
    {
        if (av_b < av_a)
            fprintf(f, "В массиве B и C меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
        else
            fprintf(f, "В массиве A меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
    }
    else if (av_a < av_b && av_a < av_c) {
        fprintf(f, "В массиве А наименьшее среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
    }
    else if (av_b < av_a && av_b < av_c) {
        fprintf(f, "В массиве B наименьшее среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
    }
    else  if (av_c < av_a && av_c < av_b) {
        fprintf(f, "В массиве C наименьшее среднее арифметическое элементов, больших заданного числа: %.2f \n", av_c);
    }
    printf("\n");
}