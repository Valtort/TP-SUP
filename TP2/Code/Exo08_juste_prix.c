#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

//Ce programme est un juste prix.

//Prend en entrée target et guess qui sont le nombre cible et l'essai de l'utilisateur
//Affiche le résultat (plus bas, plus haut, égal) et renvoie un booléen indiquant si l'essai est correct
bool verifier(int target, int guess){
    if(target < guess){
        printf("Plus bas !\n");
        return false;
    }
    else{
        if(target==guess){
            printf("Bravo, tu as gagné !\n");
            return true;
        }
        else{
            printf("Plus haut !\n");
            return false;
        }
    }
}

int main(){
    srand(time(NULL));
    int target = rand()%5000;
    int guess;
    bool Jeu_en_cours = false;
    while(!Jeu_en_cours){
        printf("Quelle nombre voulez vous essayez ?\n");
        scanf("%d", &guess);
        Jeu_en_cours = verifier(target, guess);
    }
    return 0;
}