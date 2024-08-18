#include "dict.h"
#include "liste.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// définition à mettre dans liste.h
struct cle_valeur {
	char* cle;
	char* valeur;
};
typedef struct cle_valeur cv_t;

struct dict {
	liste_t* chaine;
}
typedef struct dict dict_t;

dict_t* dico_vide(){
	dict_t* d = malloc(sizeof(dict_t));
	d->chaine = liste_vide(); // A MODIFIER
	return d;
}

bool in(dict_t* d, char* k){
	maillon_t* m = maillon_tete(d->chaine); // A MODIFIER
	while(m != NULL){
		cv_t c = contenu(m); // A MODIFIER
		if (strcmp(c.k, k) == 0){
			return true;
		}
		m = maillon_suivant(m); // A MODIFIER
	}
	return false;
}