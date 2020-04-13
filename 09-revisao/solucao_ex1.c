/* Implementar função solucao_ex1 */

int solucao_ex1(long rdi, long rsi, long rdx)
{
    long rax = rdi + rsi;
    long rcx = rax + rdx * 4;
    rdi = rdi * rdi;
    rax = rdi + 2 * rsi;
    rdx += rax;
    if (rcx >= rdx)
    {
        return 1;
    }
    return 0;
}