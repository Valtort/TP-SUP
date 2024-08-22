/* DICTIONNAIRE: TABLE DE HACHAGE 
Interface de dictionnaire.*/

#ifndef HASH_H
#define HASH_H
#include "keyval.h"
#include <stdbool.h>

struct hashtable{
	int m; // nombre d'alvéoles
	int n; // nombre d'entrées
	chain_t** t; // table de hachage: chaque case i contient la liste
	             // des clés hachées à la valeur i
};

typedef struct hashtable hashtable_t;

/*Créer une table de hachage vide*/
hashtable_t* hash_create();

/* Renvoie true si k est une clé de d, false sinon.
   Si k est une clé de d, stocke la valeur associée
   dans *v */
bool hash_get(hashtable_t* d, KEY k, VAL* v);

/* Associe la valeur v à la clé k dans d. Si k est déjà associée à une valeur
   v' dans d, remplace v' par v */
void hash_set(hashtable_t* d, KEY k, VAL v);

/* Supprime la clé k de d. Renvoie true si la clé était bien dans d
   et false sinon */
bool hash_delete(hashtable_t* d, KEY k);

/* Affiche les asssociations clé -> valeur de d, sous le format suivant:
	clé 1 -> valeur 1
	clé 2 -> valeur 2
	...
	clé n -> valeur n
  avec n le nombre d'associations de d.
  Affiche (liste vide) si d ne contient aucune association.
 */
void hash_print(hashtable_t* d);

void hash_free(hashtable_t* d);

/* Affiche le contenu de d alvéole par alvéole, sous le format suivant:
Alvéole 0 (taille n_0):
clé 1 -> valeur 1
...
clé n_0 -> valeur n_0

Alvéole 1 (taille n_1):
clé 1 -> valeur 1
...
clé n_1 -> valeur n_1

...
 */
void hash_debug(hashtable_t* d);
#endif