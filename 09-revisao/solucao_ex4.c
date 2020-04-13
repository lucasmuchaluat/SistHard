/* Implementar solucao_ex4 */

int add1(int a);

int solucao_ex4(int rdi, int rdx)
{
    int rbx = rdi;
    unsigned int eax = 0;
    while (eax < rbx)
    {
        rdi = eax;
        eax = add1(rdi);
    }
    return eax;
}