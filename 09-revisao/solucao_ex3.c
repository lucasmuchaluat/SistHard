int solucao_ex3(long rdi, long rsi, int *rdx, int *rcx, int *r8)
{
    unsigned int eax;
    eax = (rdi < rsi);
    *rdx = eax;
    eax = (rdi == rsi);
    *rcx = eax;
    eax = (rdi > rsi);
    *r8 = eax;
    return *r8;
}