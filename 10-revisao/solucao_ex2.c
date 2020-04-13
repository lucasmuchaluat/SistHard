//TODO: implementar função solucao_ex2 aqui
void solucao_ex2(long *rdi, long rsi, long *rdx)
{
    long rax = *rdx;
    if (*rdi > rax)
    {
        rsi = 3 * rsi;
    }
    else
    {
        *rdx += 1;
    }

    rsi += *rdx;
    *rdi = rsi;
    return;
}