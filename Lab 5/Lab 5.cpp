//Lab 5. Переделать задачу с тремя массивами так, чтобы вспомогательная функция
//работала не с элементом массива x[i], а с выражением f(x[i]).

#include <cstdio>
#include <locale.h>
#include <math.h>
#include "Function.h"
#pragma warning (disable:4996)

int main() {
    setlocale(LC_ALL, "Rus");
    int n_a, n_b, n_c;
    int select = 0; int func_select = 0;
    float av_a, av_b, av_c, zn;
    float* a, * b, * c;
    bool flag = true;
    func function = nullptr;

    FILE* mas_a = fopen("a.txt", "r");
    FILE* mas_b = fopen("b.txt", "r");
    FILE* mas_c = fopen("c.txt", "r");
    FILE* log;

    while (flag) {
        printf("1: Очистить log-файл. \n");
        printf("2: Решить задачу. \n");
        printf("3: Завершение работы программы. \n");
        printf("Выбор: ");
        scanf_s("%d", &select);
        switch (select) {

        case (1):
            fopen_s(&log, "log.txt", "w");
            fclose(log);
            fopen_s(&log, "log.txt", "a");
            fprintf(log, "log-файл очищен. \n");
            fclose(log);
            break;

        case (2):
            printf("Выберите функцию: \n");
            printf("1. f(x) = log(x) \n");
            printf("2. f(x) = sin(x) \n");
            printf("3. f(x) = exp(x) \n");
            scanf_s("%d", &func_select);
            switch (func_select) 
            {
            case(1): function = &func_log; break;
            case(2): function = &func_sin; break;
            case(3): function = &func_exp; break;
            }
            fopen_s(&log, "log.txt", "a");
            printf("Введите размер массивов a,b,c: \n");
            scanf_s("%d", &n_a); size_check(n_a);
            scanf_s("%d", &n_b); size_check(n_b);
            scanf_s("%d", &n_c); size_check(n_c);
            a = new float[n_a]; 
            b = new float[n_b]; 
            c = new float[n_c];

            fprintf(log, "Элементы массива x[i], представляют собой выражение f(x[i]). \n");
            input(mas_a, a, n_a);
            fprintf(log, "Массив A : %d \n", n_a);
            output(log, a, n_a, function); fprintf(log, "\n");
            input(mas_b, b, n_b);
            fprintf(log, "Массив B: %d \n", n_b);
            output(log, b, n_b, function); fprintf(log, "\n");
            input(mas_c, c, n_c);
            fprintf(log, "Массив C: %d \n", n_c);
            output(log, c, n_c, function); fprintf(log, "\n");
            printf("Введите заданное число: ");
            scanf_s("%f", &zn);
            fprintf(log, "Заданное число: %.3f \n", zn);
            av_a = average(a, n_a, zn, function);
            av_b = average(b, n_b, zn, function);
            av_c = average(c, n_c, zn, function);
            
            if (av_a == zn) fprintf(log, "В массиве A нет элементов больших заданного числа \n");
            else fprintf(log, "Среднее арифметическое A: %.3f \n", av_a);
            if (av_b == zn) fprintf(log, "В массиве B нет элементов больших заданного числа \n");
            else fprintf(log, "Среднее арифметическое B: %.3f \n", av_b);
            if (av_c == zn) fprintf(log, "В массиве C нет элементов больших заданного числа \n");
            else fprintf(log, "Среднее арифметическое C: %.3f \n", av_c);
            sravn(av_a, av_b, av_c, log, zn);
            fprintf(log, "\n\n");
            fclose(log);
            delete[] a;
            delete[] b;
            delete[] c;
            break;

        case (3):
            flag = false;
            printf("Завершение работы программы. \n");
            fopen_s(&log, "log.txt", "a");
            fprintf(log, "Завершение работы программы. \n ");
            fclose(mas_a); fclose(mas_b); fclose(mas_c);
            fclose(log);
            break;
        default:
            printf("Введите корректное значение! \n ");
            break;
        }
    }
    return 0;
}