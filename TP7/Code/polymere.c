#ifndef pile_H
#include "pile.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* Le but de ce programme est d'utiliser les fonctions de la SDA pile 
(supposé implémenté par tableaux redimensionnable) afin de lire et 
simplifier un polymère (cf README.md pour savoir ce qu'est un polymère)*/

struct pile {
   int taille;
   int nb_elem;
   int* tab;
};

char* stable(char* filename){
    FILE* f = fopen(filename, "r");
    assert(f!=NULL);
    char lecture;
    pile_t* p = pile_vide();
    char sommet;

    //boucle qui lit dans le ficheir et fait les simplifications au fur et à mesure
    while(fscanf(f, "%c", &lecture) != EOF){
        if(!est_vide(p)){
            sommet = depiler(p);
            if(sommet - 'a' + 'A' == lecture || lecture - 'a' + 'A' == sommet){
            } 
            else{
                empiler(p, sommet);
                empiler(p, lecture);
            }
        }
        else{
            empiler(p, lecture);
        }
    }


    //On forme la chaine de caractère
    char* resultat = malloc((p->nb_elem+1)*sizeof(char));
    for(int i=p->nb_elem-1; i>=0; i--){
        resultat[i] = depiler(p);
    }

    free(p);
    fclose(f);
    return resultat;
}

int main(){
    char* poly = stable("big_polymer.txt");
    printf("Le polymère simplifié est : %s\n", poly);
    return 0;
}