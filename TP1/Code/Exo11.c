#include <stdio.h>

int main(){
    int x=3;
    float y=0.25;
    float somme_f = x+y;
    int somme_i = x+y;
    printf("x = %d, y = %f, la somme de x et y en flottant vaut %f, la somme de x et y en entier vaut %d\n", x,y,somme_f,somme_i);


    return 0;
}