#pragma once
#include <cstdio>

typedef float (*func)(float);

float average(float* x, int n, float zn, func f);
void sravn(float av_a, float av_b, float av_c, FILE* f, float zn);
void input(FILE* f_in, float* x, int n);
void output(FILE* f_out, float* x, int n, func f);
void size_check(int& n);

float func_cos(float x);
float func_sin(float x);
float func_exp(float x);
float func_log(float x);
