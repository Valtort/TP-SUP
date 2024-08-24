#pragma once
/* Structure de données abstraite: Liste chaînée */
#include "dict.h"
#define T cv_t*
#include <stdbool.h>

struct cle_valeur {
	char* cle;
	char* valeur;
};
typedef struct cle_valeur cv_t;

typedef struct liste {
   struct maillon* tete;
   struct maillon* queue;
   int taille;
} liste_t;


typedef struct maillon {
   cv_t* val;
   struct maillon* suiv;
   struct maillon* prec;
   liste_t* mere;
} maillon_t;



/* Crée une liste vide */
liste_t* liste_vide();


/* Libère toute la mémoire allouée à l */
void free_liste(liste_t* l);

/* Affiche la liste de l'avant à l'arrière */
void print_liste(liste_t* l);

/*Prend un maillon et détermine si c'est une sentinelle*/
bool est_sentinelle(maillon_t* m);

//Prend une liste et ajoute un maillon à l'avant
void ajout_avant(liste_t* l, cv_t* x);

//Prend une liste et ajoute un maillon à l'arrière
void ajout_arriere(liste_t* l, cv_t* x);

//Permet de récuperer le contenu d'un maillon
cv_t* recup_value(maillon_t* m);

//Permet de récuperer le maillon avant d'une liste
maillon_t* recup_avant(liste_t* l);

//Permet de récuperer le maillon arrière d'une liste
maillon_t* recup_arriere(liste_t* l);

//Permet de récuperer le maillon suivant d'un autre maillon
maillon_t* recup_suiv(maillon_t* m);

//Permet de récuperer le maillon precedent d'un autre maillon
maillon_t* recup_prec(maillon_t* m);

//Insere un maillon contenant x après le maillon m
void insertion(maillon_t* m, cv_t* x);

//Supprime un maillon
void suppr(maillon_t* m);

//Prend une liste et ajoute un maillon à l'avant (en une ligne)
void ajout_avant_bis(liste_t* l, cv_t* x);

//Prend une liste et ajoute un maillon à l'arrière (en une ligne)
void ajout_arriere_bis(liste_t* l, cv_t* x);

//Donne la taille d'une liste
int taille(liste_t* l);