#include <stdio.h>
#include <math.h>


float Delta(float a, float b, float c){
    return b*b - 4*a*c;
}

float RaizX1(float a, float b, float delta){
    return (-b + sqrt(delta)) / (2*a);
}

float RaizX2(float a, float b, float delta){
    return (-b - sqrt(delta)) / (2*a);
}



int main(){
    float a, b, c; //Coeficientes da funcao f(x) = (ax^2 + bx + c)
    float delta;


    scanf("%f %f %f", &a, &b, &c);
    delta = Delta(a, b, c);
    if (delta < 0 || a == 0){
        puts("Impossivel calcular");
    }
    else {
        printf("R1 = %.5f\n", RaizX1(a, b, delta));
        printf("R2 = %.5f\n", RaizX2(a, b, delta));
    }


    return 0;
}