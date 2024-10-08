#ifndef KVGUARD
#define KVGUARD
#include "keyval.h"

typedef struct chain chain_t;

typedef struct maillon{
	KEY key;
	VAL val;
	struct maillon* next; // maillon suivant
	struct maillon* prev; // maillon précédent
} maillon_t;

struct chain{
	maillon_t* head; // 1er maillon
	int n;  // nombre total de couples (clé, valeur)
};


chain_t* chain_create();

/* Renvoie un booléen indiquant si k est une clé de d. Si 
   c'est le cas, stocke la valeur associée à k dans *v */
bool chain_get(chain_t* d, KEY k, VAL* v);

/* Associe la valeur v à la clé k dans d. Si k est déjà associée à une valeur
   v' dans d, remplace v' par v */
void chain_set(chain_t* d, KEY k, VAL v);

/* Supprime la clé k de d. Renvoie true si la clé était bien dans d
   et false sinon */
bool chain_delete(chain_t* d, KEY k);

/* Affiche les asssociations clé -> valeur de d, sous le format suivant:
	clé 1 -> valeur 1
	clé 2 -> valeur 2
	...
	clé n -> valeur n
  avec n le nombre d'associations de d.
  Affiche (liste vide) si d ne contient aucune association.
 */
void chain_print(chain_t* d);

/* Libère la mémoire allouée pour d, clés et valeurs comprises. */
void chain_free(chain_t* d);

/*Renvoie le tableau des clés d'un dictionnaire d*/
char** tab_cle(chain_t* d);
#endif