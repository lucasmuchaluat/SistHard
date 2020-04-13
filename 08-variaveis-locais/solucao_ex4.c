#include <stdio.h>

int ex4_solucao(int rdi)
{
    int rbx = rdi;
    int rdx;
    int rsi;
    scanf("%d %d", &rsi, &rdx);
    int eax = rsi + 2 * rdx;
    eax += rbx;
    return eax;
}