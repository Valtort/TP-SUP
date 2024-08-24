#ifndef KVGUARD
#include "dico_chaine.h"
#endif
#ifndef KEY_H
#include "keyval.h"
#endif
#ifndef HASH_H
#include "dico_hash.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

/*Fonction de test*/
void test();

/*Renvoie la clé dont la valeur associé est maximale dans une chaine
Prend une chaine, un pointeur vers la valeur max enregistré jusqu'à maintenant
ainsi qu'un pointeur vers la valeur de clé (l'indice max a modifié en quelques sortes)
Précondition : t n'est pas vide et les valeurs sont des entiers positifs*/
void argmax_tab(chain_t* t, KEY* k, VAL* max);

/*Renvoie la clé dont la valeur associé est maximale dans un dictionnaire
Précondition : d n'est pas vide et les valeurs sont des entiers positifs*/
KEY argmax(hashtable_t* d);

/*Renvoie le dictionnaire des occurences des mots de filename, parmi les mots
d'au moins K lettres*/
hashtable_t* occurences(char* filename, int K);

/*Troue le mot le plus fréquent dans le fichier filename parmi ceux ayant une
longueur au moins K, et l'affiche avec son nombres d'occurences.
Affiche aussi le nombre total de mots dans le texte.*/
void mot_plus_frequent(char* filename, int K);

