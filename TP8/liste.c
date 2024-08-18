#include "liste.h"
/* Implémentation par liste à sentinelle
La liste contient toujours deux maillons, un
à la tête et un à la queue, appelés les
sentinelles. Ces maillons sont invisibles du
point de vue de l'utilisateur. */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct liste {
   struct maillon* tete;
   struct maillon* queue;
} liste_t;

typedef struct maillon {
   T val;
   struct maillon* suiv;
   struct maillon* prec;
} maillon_t;


liste_t* liste_vide(){
   liste_t* l = malloc(sizeof(liste_t));
   l->tete = malloc(sizeof(maillon_t));
   l->queue = malloc(sizeof(maillon_t));

   // TETE <-> QUEUE
   l->tete->suiv = l->queue;
   l->tete->prec = NULL;
   l->queue->prec = l->tete;
   l->queue->suiv = NULL;

   return l;
}


void print_liste(liste_t* l){
   // itérer sur les vrais maillons, i.e. en partant après la sentinelle de tête
   maillon_t* m = l->tete->suiv; 
   //jusqu'à atteindre la sentinelle de queue
   while (m->suiv != NULL){
      printf("%d", m->val);
      // mettre une double flèche s'il reste un vrai maillon à afficher
      if (m->suiv->suiv != NULL){
         printf(" <-> ");
      }
      m = m->suiv;
   }
   printf("\n");
}


void free_liste(liste_t* l){
   maillon_t* m = l->tete;
   while (m != NULL){
      maillon_t* prochain = m->suiv;
      free(m);
      m = prochain;
   }
   free(l);
}

bool est_sentinelle(maillon_t* m){
   return(m->suiv == NULL || m->prec == NULL);
   //Car une CNS pour être une sentinelle est de pointé NULL à gauche ou à droite
}

void ajout_avant(liste_t* l, int x){
   maillon_t* m = malloc(sizeof(maillon_t));
   m->val = x;
   m->suiv = l->tete->suiv;
   l->tete->suiv->prec = m;
   l->tete->suiv = m;
   m->prec = l->tete;
}  

void ajout_arriere(liste_t* l, int x){
   maillon_t* m = malloc(sizeof(maillon_t));
   m->val = x;
   m->prec = l->queue->prec;
   l->queue->prec->suiv = m;
   l->queue->prec = m;
   m->suiv = l->queue;
}  

int recup_value(maillon_t* m){
   assert(m!=NULL);
   assert(!est_sentinelle(m));
   return m->val;
}

maillon_t* recup_avant(liste_t* l){
   if(liste_vide(l)){
      return NULL;
   }
   return l->tete->suiv;
}

maillon_t* recup_arriere(liste_t* l){
   if(liste_vide(l)){
      return NULL;
   }
   return l->queue->prec;
}

maillon_t* recup_suiv(maillon_t* m){
   if(!est_sentinelle(m->suiv) && m->suiv != NULL){
      return m->suiv;
   }
   return NULL;
}  

maillon_t* recup_prec(maillon_t* m){
   if(!est_sentinelle(m->prec) && m->prec != NULL){
      return m->prec;
   }
   return NULL;
}  

void insertion(maillon_t* m, int x){
   assert(m->suiv != NULL);
   maillon_t* s = m->suiv;
   maillon_t* new = malloc(sizeof(maillon_t));
   new->val = x;
   //on relie m avec new 
   m->suiv = new;
   new->prec = m;

   //on relie new et s
   new->suiv = s;
   s->prec = new;
}

void suppr(maillon_t* m){
   assert(!est_sentinelle(m));
   maillon_t* p = m->prec;
   maillon_t* s = m->suiv;
   p->suiv = s;
   s->prec = p;
   free(m);
}

void ajout_avant_bis(liste_t* l, int x){
   insertion(l->tete,x);
}

void ajout_arriere_bis(liste_t* l, int x){
   insertion(l->queue->prec,x);
}

//Merci les sentinelles ! 