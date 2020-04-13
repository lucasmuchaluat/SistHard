
/* Implemente aqui sua versão em C da função soma_n
 * presente no arquivo ex4.o
 * 
 * Chame sua função de soma_n_solucao */

int soma_n_solucao(int c)
{
    long a = 0;
    long b = 0;
    while (a < c)
    {
        b += a;
        a += 1;
    }
    return b;
}