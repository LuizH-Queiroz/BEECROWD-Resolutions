#include <stdio.h>


int main(){
    int n_estrelas; //Quantidade de Estrelas (sítios)
    unsigned long long total_carneiros;
    int primeira_par; //Primeira Estrela que tem uma quantidade par de carneiros
    int carneiros_roubados; //Quantidade de carneros roubados
    int estrelas_atacadas; //Quantidade de Estrelas atacadas
    int i;


    scanf("%d", &n_estrelas);
    int estrela[n_estrelas];

    //Leitura da quanidade de carneiros em cada Estrela
    total_carneiros = 0;
    for (i = 0; i < n_estrelas; i++)
    {
        scanf("%d", &estrela[i]); //Cada estrela armazena o número de carneiros que possui
        total_carneiros += estrela[i];
    }


    /*
    Para chegar em uma Estrela com número par, o irmão louco com certeza passou apenas por
    Estrelas com números ímpares de carneiros, pois só assim ele pode seguir para uma Estrela
    que nunca passou antes.

    Pode-se perceber que se todas as Estrelas contiverem números ímpares, o irmão louco passará
    apenas uma vez em cada Estrela, já que sempre passará para a próxima casa. Se ele passar por
    uma Estrela com um número par de carneiros, porém, ele irá voltar e passar por todas as
    Estrelas que já passou, pois agora possuem um número par de carneiros, já que para ter avançado
    essas Estrelas tinham números ímpares, mas tiveram um de seus carneiros roubados.

    A partir dessas inferências, podemos usar de fórmular para calcular a quantidade de carneiros
    roubados e a quantidade de Estrelas atacadas.
    */


    /* Encontrando a primeira Estrela com quantidade par de carneiros (se houver) */

    int umCarneiro = 0; /*Quantidade de Estrelas com um unico carneiro que antecedem
                          a primeira Estrela com uma quantidade par de carneiros */
    primeira_par = -1;
    for (i = 0; i < n_estrelas; i++)
    {
        if (estrela[i] == 1){
            umCarneiro++;
        }
        else if (estrela[i] % 2 == 0){
            primeira_par = i;
            break;
        }
    }


    if (primeira_par == -1){ //Nao ha nenhuma Estrela com um numero par de carneiros
        carneiros_roubados = n_estrelas;
        estrelas_atacadas = n_estrelas;
    }
    else { //Ha alguma Estrela com quantidade par de carneiros
        carneiros_roubados = (primeira_par * 2 + 1) - umCarneiro;
        estrelas_atacadas = primeira_par + 1;
    }

    printf("%d %llu\n", estrelas_atacadas, (unsigned long long)(total_carneiros - carneiros_roubados));


    return 0;
}