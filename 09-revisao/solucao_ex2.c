/* Implementar função solucao_ex2 */

long x2(long n);

long solucao_ex2(long rdi, long rsi)
{
    long rbx = rdi;
    long rax = x2(rsi);
    if (rax <= rbx)
    {
        rax += rbx;
        return rax;
    }
    rbx += rbx;
    rax += rbx;
    return rax;
}
