#ifndef pile_H
#include "pile.h"
#endif
#include <stdio.h>
#include <stdlib.h>

/* Le but de ce programme est d'implémenter les fonctions de la SDA pile 
en utilisant l'implémentation par liste chainées*/

typedef struct maillon{
    int elem;
    struct maillon* suivant;
}maillon_t;

struct pile{
    maillon_t* sommet;
};

pile_t* pile_vide(){
    pile_t* pile = malloc(sizeof(pile_t));
    pile->sommet = NULL;
    return pile;
}

bool est_vide(pile_t* p){
    if(p->sommet == NULL){
        return true;
    }
    else{
        return false;
    }
}

void empiler(pile_t* p, int x){
    maillon_t* maillon_sommet = malloc(sizeof(maillon_t));
    maillon_sommet->elem = x;
    maillon_sommet->suivant = p->sommet;
    p->sommet = maillon_sommet;
}   

int depiler(pile_t* p){
    maillon_t* maillon_sommet = p->sommet;
    int x = maillon_sommet->elem;
    p->sommet = maillon_sommet->suivant;
    free(maillon_sommet);
    return x;
}

void free_pile(pile_t* p){
    maillon_t* maillon_actuelle = p->sommet;
    maillon_t* maillon_suiv = maillon_actuelle->suivant;
    while(maillon_suiv != NULL){
        free(maillon_actuelle);
        maillon_actuelle = maillon_suiv;
        maillon_suiv = maillon_suiv->suivant;
    }
    free(maillon_actuelle);
    free(p);
}

void print_pile(pile_t* p){
    maillon_t* maillon_actuelle = p->sommet;
    printf("#####\n");
    while(maillon_actuelle != NULL){
        printf("%d\n", maillon_actuelle->elem);
        maillon_actuelle = maillon_actuelle->suivant;
    }
    printf("=====\n");
}