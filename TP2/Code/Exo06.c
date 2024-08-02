#include <stdio.h>
#include <assert.h>

//Fichier qui contient les questions 1 et 2 de l'exo 6

//Affiche tout les entiers entre 1 et n, n entier
void affiche_suite(int n){
    assert(n>=0); //Avoir un nombre négatif ou nul poserait problème
    for(int i=1; i<=n; i++){
        printf("%d\n", i);
    }
}

/*
Affiche une seul ligne composé de n tirets, et se terminant par un |
Exemple : ligne(3) affichera : ---| 
*/
void ligne(int n){
    assert(n>=0); // on ne va pas affiché -1 tirets
    for(int i=0; i<n; i++){
        printf("-");
    }
    printf("|\n");
}

// Affiche un escalier de n lignes, la i-ème ligne contiendra 2i+1 tirets
void escalier(int n){
    for(int i=0; i<n; i++){
        ligne(2*i+1);
    }
}

int main(){
    affiche_suite(5);
    escalier(40);
    return 0;
}