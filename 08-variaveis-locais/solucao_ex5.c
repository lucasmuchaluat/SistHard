#include <stdio.h>

int ex5_solucao()
{
    int ebx = 0;
    int eax = 1;
    while (eax > 0)
    {
        scanf("%d", &eax);
        if (eax > 0)
        {
            ebx += eax;
        }
    }
    eax = ebx;
    return eax;
}