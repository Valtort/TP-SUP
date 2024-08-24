#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/*
Lit dans le fichier f une ligne entière, et la stocke dans résultat
Seul les n_max premiers caractères sont stockés, et si la lgine dépasse
de cette limite, les caractères supplémentaires sont perdus.
resultat doit pointer vers une zone d'au moins (n_max+1) octets pour
y stocker la ligne lue ainsi que le caractère de termination.*/
void lire_ligne(FILE* f, char* resultat, int n_max){
    char sauv;
    int i=0;
    while(fscanf(f, "%c", &sauv) != EOF || sauv != '\n'){
        if(i<n_max){
            resultat[i] = sauv;
        }
        
        i++;
    }

}


int main(){
    FILE* fichier = fopen("Test_Exo4.txt", "r");
    assert(fichier != NULL);
    char mot[61];
    lire_ligne(fichier, mot, 60);
    assert(strcmp(mot, "Le chat noir saute par-dessus le mur."));
    lire_ligne(fichier, mot, 20);
    assert(strcmp(mot, "Le chat blanc regar"));
    printf("Tout les tests ont été passé avec succés !\n");
    return 0;
}