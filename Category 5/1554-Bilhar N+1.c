#include <stdio.h>
#include <math.h>


/***
 * DistanciaPontos(): Tem o objetivo de retornar a distancia entre dois pontsos.
 * 
 * Parametros:
 * x_branca - Coordenada X da bola branca
 * y_branca - Coordenada Y da bola branca
 * x - Coordenada X da outra bola (nao branca)
 * y - Coordenada Y da outra bola (nao branca)
 * 
 * Retorno: O quadrado da distancia entre os pontos.
 * 
 * 
 * Nota: Apesar de seu objetivo, essa funcao foi pensada e escrita especificamente
 *       para esse problema. Seu tipo de retorno e parametros (int) foram assim
 *       especificados devido as restricoes do problema, que afirmam que os valores
 *       de entrada sao todos inteiros.
 *       Alem disso, a distancia real nao eh calculada porque nao eh necessaria, ja
 *       que, quanto maior um numero, maior sera sua raiz e, portanto, nao precisamos
 *       achar o valor real da distancia (nosso interesse eh apenas achar a bola mais
 *       proxima da branca, nao a sua distancia da bola branca).
*/
int DistanciaPontos(int x_branca, int y_branca, int x, int y){
    return pow(x_branca - x, 2) + pow(y_branca - y, 2);
}


int main(){
    int nTestes; //Numero de casos de teste
    int nBolas; //Numero de bolas alem da cola branca

    int x_branca, y_branca; //Coordenadas da bola branca

    int maisProxima; //Numero da bola mais proxima
    int dist_maisProxima; //Distancia (nao real) da bola mais proxima

    int novoX, novoY; //Novas leituras das bolas (nao brancas)
    int novaDist; //Distancia (nao real) de determinada bola ate a branca
    
    int i, j;


    scanf("%d", &nTestes);
    for (i = 0; i < nTestes; i++)
    {
        scanf("%d", &nBolas);
        scanf("%d %d", &x_branca, &y_branca);

        scanf("%d %d", &novoX, &novoY);
        maisProxima = 1;
        dist_maisProxima = DistanciaPontos(x_branca, y_branca, novoX, novoY);

        for (j = 2; j <= nBolas; j++)
        {
            scanf("%d %d", &novoX, &novoY);

            novaDist = DistanciaPontos(x_branca, y_branca, novoX, novoY);

            if (novaDist < dist_maisProxima){
                maisProxima = j;
                dist_maisProxima = novaDist;
            }
        }

        printf("%d\n", maisProxima);
    }


    return 0;
}