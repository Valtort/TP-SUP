#include "dict.h"
#include "liste.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*Le but de ce programme est d'implémenter la SDA dictionnaire
afin de pouvoir utiliser un algo permettant de savoir si un tableau
contient des doublons*/



struct dict {
	liste_t* chaine;
};
typedef struct dict dict_t;

dict_t* dico_vide(){
	dict_t* d = malloc(sizeof(dict_t));
	d->chaine = liste_vide(); 
	return d;
}

bool in(dict_t* d, char* k){
	maillon_t* m = recup_avant(d->chaine); 
	while(m != NULL){
		cv_t* c = recup_value(m); 
		if (strcmp(c->cle, k) == 0){
			return true;
		}
		m = recup_suiv(m); 
	}
	return false;
}

char* get(dict_t* d, char* k){
	if(!in(d,k)){
		return NULL;
	}
	maillon_t* m = recup_avant(d->chaine); 
	while(m != NULL){
		cv_t* c = recup_value(m); 
		if (strcmp(c->cle, k) == 0){
			return c->valeur;
		}
		m = recup_suiv(m); 
	}
}

void set(dict_t* d, char* k, char* v){
	if(!in(d,k)){
		cv_t* c = malloc(sizeof(cv_t));
		c->cle = k;
		c->valeur = v;
		ajout_avant_bis(d->chaine, c);
	}
	else{
		maillon_t* m = recup_avant(d->chaine); 
		while(m != NULL){
			cv_t* c = recup_value(m); 
			if (strcmp(c->cle, k) == 0){
				(m->val)->valeur = v;
			}
			m = recup_suiv(m); 
		}
	}
}


bool doublons(char** tab, int n){
	dict_t* d = dico_vide();
	for(int i=0; i<n; i++){
		if(in(d, tab[i])){
			print_liste(d->chaine);
			free_liste(d->chaine);
			free(d);
			return true; // Car il existe j appartenant à [0,n-1] tq T[j]=T[i]
		}
		set(d, tab[i], "a");
	}
	free_liste(d->chaine);
	free(d);
	return false; // Il n'y a aucun doublon
}