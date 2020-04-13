// TODO: substituir tipo pelo tipo das globais
extern int var1, var2;

// TODO: implementar solucao_ex3 abaixo
int solucao_ex3(long *rdi)
{
    int eax = 5 * var1;
    int edx = 10 * var2;
    eax += edx;
    *rdi = eax;
    eax += var1;
    var2 = eax;
}