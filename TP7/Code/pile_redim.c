/* Implémentation des piles par tableaux redimensionnables */
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "pile.h"

/* Principe: 
Le tableau peut stocker au plus taille éléments.
Les cases 0, 1, ..., nb_elem-1 du tableau
sont utilisées et stockent les éléments de la base vers
le sommet. La case contenant le sommet est la case
nb_elem-1 (si la pile n'est pas vide).
Par exemple, pour une pile contenant (de haut en bas):
1
2
3
Le tableau sera [1, 2, 3, ?, ?, ..., ?] et nb_elem sera 3. Les cases
au delà (entre nb_elem et taille-1) peuvent contenir n'importe quoi.

Lorsque la pile atteint sa taille maximale, le tableau est
doublé de taille. Si la pile est remplie à moins du quart,
alors le tableau est divisé par deux de taille */
struct pile {
   int taille;
   int nb_elem;
   int* tab;
};

pile_t* pile_vide(){
   pile_t* p = malloc(sizeof(pile_t));
   p->nb_elem = 0;
   p->taille = 25; // choix de taille initiale
   p->tab = malloc(p->taille*sizeof(int));
   return p;
}

bool est_vide(pile_t* p){
   return (p->nb_elem == 0);
}

void empiler(pile_t* p, int x){
   if(p->nb_elem == p->taille){
      p->taille = p->taille * 2;
      p->tab = realloc(p->tab, p->taille*sizeof(int));
   }
   p->tab[p->nb_elem] = x;
   p->nb_elem++;
}

int depiler(pile_t* p){
   assert(!est_vide(p));
   if (p->taille > 50 && p->nb_elem < p->taille/4){
      p->taille = p->taille / 2;
      p->tab = realloc(p->tab, p->taille*sizeof(int));
   }
   int res = p->tab[p->nb_elem-1];
   p->nb_elem--;
   return res;
}

void free_pile(pile_t* p){
   free(p->tab);
   free(p);
}

void print_pile(pile_t* p){
   printf("###\n");
   for (int i = p->nb_elem-1; i >= 0; --i)
   {
      printf("%c\n", p->tab[i]);
   }
   printf("===\n");
}