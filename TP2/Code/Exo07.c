#include <stdio.h>
#include <assert.h>

//Programme qui fait la somme de tout les nombres donné jusqu'à ce que 
//l'utilisateur rentre un nombre strictement négatif, renvoie la somme de
//tout les nombres rentrés

void somme_user(){
    float somme = 0;
    float n=0;
    while(n>=0){
        printf("Rentrez un nombre à ajouter à la somme total (un nombre strict. négatif si vous voulez arrêtez la somme ici) : ");
        scanf("%f", &n);
        somme = somme + n;
    }
    somme = somme -n;
    printf("La somme est : %f\n", somme);
}

int main(){
    somme_user();
    return 0;
}