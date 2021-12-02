/*
A informatização dos sistemas bancários permitiu grandes economias de tempo e dinheiro, permitindo
que vários tipos de transações financeiras pudessem ser realizadas pela Internet. Para possibilitar isso,
cada banco recebeu um código bancário, que é um número utilizado pelos sistemas de computador para
identificar cada banco.

Quando um banco decide comprar outro, ocorre o que se chama uma fusão: os dois bancos tornam-se
um só banco. Para manter compatibilidade com os sistemas eletrônicos dos bancos, qualquer um dos códigos
dos antigos bancos pode ser usado para se referir ao novo banco.

Com a crise econômica internacional, as fusões entre bancos têm sido cada vez mais comuns;
por isso, muitas vezes é difícil decidir se dois códigos bancários na realidade se referem ao mesmo
banco (devido aos dois bancos terem se fundido, diretamente ou não).

Escreva um programa que, dada uma série de fusões entre bancos, responde a várias consultas
perguntando se dois códigos bancários se referem ao mesmo banco.

Entrada
A primeira linha da entrada contém dois inteiros N e b, indicando o número de bancos e o número de
operações efetuadas (1 ≤ N ≤ 100.000, 1 ≤ K ≤ 100.000). Os códigos de cada um dos N bancos,
inicialmente, são os inteiros de 1 até N.

Cada uma das K linhas seguintes descreve ou uma fusão entre bancos ou uma consulta.

Uma fusão é descrita na entrada como uma linha que começa com o caractere 'F', um espaço, e dois
códigos bancários, que se referem aos dois bancos que estão sofrendo a fusão, separados por um espaço
em branco;
Uma consulta é descrita na entrada como uma linha que começa com o caractere 'C', um espaço,
e os dois códigos a serem consultados, separados por um espaço em branco. Os códigos
bancários consultados são sempre distintos.
As fusões são sempre realizadas entre bancos diferentes, e todos os códigos bancários fornecidos
na entrada são válidos.

Saída
Seu programa deve imprimir uma linha para cada consulta na entrada. Caso os dois códigos bancários
consultados se refiram ao mesmo banco, imprima uma linha contendo o caractere 'S'; caso contrário,
imprima uma linha contendo apenas o caractere 'N'.
*/


#include <iostream>

using namespace std;


int Patriarca(int x, int pai[]);
void Fusao(int banco_1, int banco_2, int pai[]);


int main(){
    int n_bancos, n_operacoes;
    int banco_1, banco_2;
    char operacao;


    cin >> n_bancos >> n_operacoes;
    int pai[n_bancos + 1];
    for (int i = 1; i <= n_bancos; i++)
    {
        pai[i] = i;
    }

    for (int i = 0; i < n_operacoes; i++)
    {
        cin >> operacao >> banco_1 >> banco_2;

        switch(operacao){
            case 'F':
                Fusao(banco_1, banco_2, pai);
                break;

            case 'C':
                if (Patriarca(banco_1, pai) == Patriarca(banco_2, pai)) cout << "S" << endl;
                else cout << "N" << endl;
                break;
        }
    }



    return 0;
}


int Patriarca(int x, int pai[]){
    if (pai[x] == x) return x;

    return pai[x] = Patriarca(pai[x], pai);
}

void Fusao(int banco_1, int banco_2, int pai[]){
    pai[Patriarca(banco_1, pai)] = Patriarca(banco_2, pai);
}