#ifndef file_H
#include "file.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Le but de ce programme est d'implémenter les fonctions de la SDA file 
en utilisant l'implémentation par liste chainées*/

typedef struct maillon{
    int elem;
    struct maillon* suivant; // de la tete vers la queue
} maillon_t;

struct file{
    maillon_t* tete;
    maillon_t* queue;
};

file_t* file_vide(){
    file_t* file = malloc(sizeof(file_t));
    file->tete = NULL;
    file->queue = NULL;
    return file;
}

bool est_file_vide(file_t* f){
    if(f->tete ==NULL){
        return true;
    }
    return false;
}

void enfiler(file_t* f, int x){
    maillon_t* maillon = malloc(sizeof(maillon_t));
    maillon->elem = x;
    maillon->suivant = NULL;
    if(est_file_vide(f)){
        f->tete = maillon;
        f->queue = maillon;
    }
    else{
        f->queue->suivant = maillon;
        f->queue = maillon;
    }
}

int defiler(file_t* f){
    if(f->tete == f->queue){
        int x = f->tete->elem;
        f->tete =NULL;
        f->queue = NULL;
        return x;
    }
    else{
        int x = f->tete->elem;
        maillon_t* sauv = f->tete;
        f->tete = f->tete->suivant;
        free(sauv);
        return x;
    }
}

void free_file(file_t* f){
    maillon_t* maillon_actuelle = f->tete;
    maillon_t* maillon_suiv = maillon_actuelle->suivant;
    while(maillon_suiv!=NULL){
        free(maillon_actuelle);
        maillon_actuelle = maillon_suiv;
        maillon_suiv = maillon_actuelle->suivant;
    }
    free(maillon_actuelle);
    free(f);
}

void affiche_file(file_t* f){
    if(f->tete != NULL){
        printf("%d", f->tete->elem);
        maillon_t* maillon_actuelle = f->tete->suivant;
        while(maillon_actuelle != NULL){
            printf("<-%d", maillon_actuelle->elem);
            maillon_actuelle = maillon_actuelle->suivant;
        }
    }
    printf("\n");
}   