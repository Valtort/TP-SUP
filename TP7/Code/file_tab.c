#ifndef file_H
#include "file.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Le but de ce programme est d'implémenter les fonctions de la SDA file 
en utilisant l'implémentation par tableau circulaire*/

#define Nmax 1000
struct file{
    int queue; // prochaine case à remplir
    int nb_elem;
    int tab[Nmax];
};


file_t* file_vide(){
    file_t* f = malloc(sizeof(file_t));
    f->queue =0;
    f->nb_elem = 0;
    return f;
}

bool est_file_vide(file_t* f){
    if(f->nb_elem ==0){
        return true;
    }
    return false;
}

void enfiler(file_t* f, int x){
    f->tab[f->queue] = x;
    f->queue++;
    
    if(f->queue>=Nmax){
        f->queue = (f->queue)% Nmax;
    }
    else{
        if(f->nb_elem < Nmax){
            f->nb_elem++;
        }
    }
}

int defiler(file_t* f){
    if(est_file_vide(f)){
        printf("Vous ne pouvez pas défiler une file vide !\n");
        exit(1);
    }
    else{
        int x = f->tab[0];
        for(int i=1; i<f->nb_elem; i++){
            f->tab[i-1] = f->tab[i];
        }
        f->queue--;
        f->nb_elem--;
        return x;
    }
}

void free_file(file_t* f){
    free(f);
}

void affiche_file(file_t* f){
    for(int i=0; i<f->nb_elem-1;i++){
        printf("%d<-", f->tab[i]);
    }
    if(f->nb_elem != 0){
        printf("%d", f->tab[f->nb_elem-1]);
    }
    printf("\n");
}