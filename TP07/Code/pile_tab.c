#ifndef pile_H
#include "pile.h"
#endif
#include <stdio.h>
#include <stdlib.h>


/* Le but de ce programme est d'implémenter les fonctions de la SDA pile 
en utilisant l'implémentation par tableaux*/

#define Nmax 100
struct pile{
    int nb_elem;
    int tab[Nmax];
};

pile_t* pile_vide(){
    pile_t* pile = malloc(sizeof(pile_t));
    pile->nb_elem = 0;
}

bool est_vide(pile_t* p){
    if(p->nb_elem==0){
        return true;
    }
    else{
        return false;
    }
}

void empiler(pile_t* p, int x){
    p->tab[p->nb_elem] = x;
    p->nb_elem ++;
}

int depiler(pile_t* p){
    p->nb_elem --;
    int x = p->tab[p->nb_elem] ;
    p->tab[p->nb_elem] = 0;
    return x;
}

void free_pile(pile_t* p){
    free(p);
}

void print_pile(pile_t* p){
    printf("#####\n");
    for(int i = p->nb_elem -1; i>=0; i--){
        printf("%d\n", p->tab[i]);
    }
    printf("=====\n");
}