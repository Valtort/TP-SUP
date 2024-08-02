#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Ce programme calculera le temps de vol de x. (On parle ici d'une suite de syracuse cf. TP2.pdf)


//étant donné x entier non nul, calcule le terme suivant dans la suite de syracuse
int suivant(int x){
    assert(x>0);
    if(x%2==0){
        return x/2;

    }
    else{
        return 3*x+1;
    }
}

//Etant donné x entier non nul et n entier, calcule le n-ème terme de la suite de Syracuse
int syracuse(int x, int n){
    assert(x>0);
    assert(n>=0);
    int resultat = x;
    for(int i=0; i< n;i++){
        resultat = suivant(resultat);
    }
    return resultat;
}

//Etant donné x entier non nul, calcul le temps de vol associé
int temps_de_vol(int x){
    int compteur = 0;
    int resultat = x;
    while(resultat != 1){
        resultat = suivant(resultat);
        compteur++;
    }
    return compteur;
}

//etant donné un entier N, renvoie l'entier x entre 1 et N ayant le plus long temps de vol
int plus_long_vol(int N){
    assert(N>=1);
    int max = 1;
    int tdv;
    for( int i=1; i <= N; i++){
        tdv = temps_de_vol(i);
        if(tdv>temps_de_vol(max)){
            max = i;
        }
    }
    return max;
}



int main(){
    printf("1 : %d\n", syracuse(9,6));
    printf("2 : %d\n", syracuse(77,128));
    printf("3 : %d\n", syracuse(1023,729));
    printf("4 : %d\n", syracuse(1234567,52397));
    printf("--------Temps de Vol---------\n");
    printf("1 : %d\n", temps_de_vol(1));
    printf("2 : %d\n", temps_de_vol(26));
    printf("3 : %d\n", temps_de_vol(27));
    printf("4 : %d\n", temps_de_vol(28));
    printf("5 : %d\n", temps_de_vol(77030));
    printf("6 : %d\n", temps_de_vol(77031));
    printf("--------Plus long Temps de Vol---------\n");
    printf("1 : %d\n", plus_long_vol(10));
    printf("2 : %d\n", plus_long_vol(100));
    printf("3 : %d\n", plus_long_vol(1000));
    printf("4 : %d\n", plus_long_vol(10000));
    printf("5 : %d\n", plus_long_vol(100000));
    // printf("6 : %d\n", plus_long_vol(1000000));
    // printf("7 : %d\n", plus_long_vol(10000000));
    return 0;
}