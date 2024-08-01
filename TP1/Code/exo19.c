#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int a,b,c; //Les trois coefficients de l'équation ax²+bx+c
    printf("Entrez les coefficients de l'équation ax²+bx+c, a,b,c:\n");
    scanf("%d %d %d", &a, &b, &c);
    float delta = b*b - 4*a*c;
    if(delta == 0){
        float solution = -1*b/(2*a);
        printf("L'unique solution est : %f\n", solution);
    }
    else{
        if(delta >0){
            printf("Les solutions sont : %f et %f \n", (-1*b + sqrt(delta))/(2*a), (-1*b - sqrt(delta))/(2*a));
        }
        else{
            printf("Les deux solutions sont : %d + i*%f et %d - i*%f \n",-1*b/(2*a), sqrt(-delta)/(2*a), -1*b/(2*a), sqrt(-delta)/(2*a) );
        }
    }
    // Affiche les solutions de l'équation
    return 0;
}