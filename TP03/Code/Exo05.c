#include <stdio.h>
#include <assert.h>
#include <math.h>
//ajoute 1 à l'entier pointé par p
void incrementer(int* p){
    assert(p!= NULL);
    *p = *p +1; //
}

//Echange le contenu de deux zones mémoires correspondant à des flottans
void echange(float* pa, float* pb){
    assert(pa != NULL);
    assert(pb != NULL);
    float sauv;
    sauv = *pa;
    *pa = *pb;
    *pb = sauv;
}

// Résout l'équation quadratique aX² +bx+c=0
// Et renvoie le nb de solutions réeles(0, 1 ou 2)
// stocke également la ou les racines dans les zones pointées
// par x1 et x2.
int quadratic_solve(float a, float b, float c, float* x1, float* x2){
    float delta = b*b-4*a*c;
    int n=0; // le nombre de solutions réels
    if (delta <0){
        x1 = 0;
        x2 = 0;
        return n;
    }
    else if (delta ==0){
        *x2= (-1*b)/(4*a);
        x1 = 0;
        n=n+1;
        return n;
    }
    else{
        *x1= ((-1*b)-sqrt(delta))/(4*a);
        *x2 = ((-1*b)+sqrt(delta))/(4*a);
        n=n+2;
        return n;
    }
}

int main(){
    int x =3;
    float y = 5.21;
    float z = 8.64;
    printf("Avant: x: %d, y: %f, z: %f\n", x, y, z);
    incrementer(&x);
    echange(&y,&z);
    printf("Après : x: %d, y: %f, z: %f\n", x, y, z);
    float a =3;
    float b=2;
    float c= -5;
    float x1;
    float x2;
    printf("Le nombre de solution est : %d\n",quadratic_solve(a,b ,c, &x1, &x2));
    return 0;
}