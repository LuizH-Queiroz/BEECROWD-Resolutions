#include <stdio.h>


float ValorGolpe(int ataque, int defesa, int level, int bonus){
    float golpe;

    golpe = (float) (ataque + defesa) / 2;

    if (level % 2 == 0){
        golpe += bonus;
    }

    return golpe;
}

int main(){
    int nTestes;
    int bonus, ataque, defesa, level;
    float dabriel, guarte;
    int i;


    scanf("%d", &nTestes);
    for (i = 0; i < nTestes; i++)
    {
        scanf("%d", &bonus);
        
        scanf("%d %d %d", &ataque, &defesa, &level);
        dabriel = ValorGolpe(ataque, defesa, level, bonus);

        scanf("%d %d %d", &ataque, &defesa, &level);
        guarte = ValorGolpe(ataque, defesa, level, bonus);

        if (dabriel > guarte){
            puts("Dabriel");
        }
        else if (guarte > dabriel){
            puts("Guarte");
        }
        else {
            puts("Empate");
        }
    }


    return 0;
}