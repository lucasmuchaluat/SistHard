
extern long var1; //TODO: complete com o tipo correto

//TODO: implemente a função solucao_ex1 abaixo
void teste();

int solucao_ex1()
{
    int ebx = 0;
    while (var1 > 0)
    {
        teste();
        ebx += 1;
    }
    return ebx;
}
