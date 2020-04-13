
/* Implemente aqui sua versão em C da função ex5
 * presente no arquivo ex5.o
 * 
 * Chame sua função de ex5_solucao */

long ex5_solucao(long a, long b)
{
    long c = 0;
    long d = 0;
    long e;
    while (c < a)
    {
        e = c % b;
        if (e == 0)
        {
            d += c;
        }
        c += 1;
    }
    return d;
}