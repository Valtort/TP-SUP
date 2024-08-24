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
/*Ce programme vise à tester les fonctions implémenter dans
dico_hash.c*/

int main(){

    /*DEBUT TEST hash(x, m)*/

    assert(hash("bonjour")%101 == 60);
    assert(hash("voici un texte a hacher")%503==151);
    assert(hash("voici un texte a macher")%503==156);
    /*FIN TEST hash(x, m)*/

    /*DEBUT TEST equal*/
    assert(equal("Coucou", "Coucou")==true);
    assert(equal("Coucou", "Bonjour")==false);
    /*FIN TEST equal*/

    /*DEBUT TEST dico_chaine.c*/
    chain_t* c = chain_create();
    int n=8;
    assert(chain_get(c, "Salut", &n) ==false);
    chain_set(c, "Chat", 1);
    chain_set(c, "Chien", 2);
    chain_set(c, "Vache", 3);
    chain_set(c, "Poule", 4);
    chain_print(c);

    VAL* v1 = malloc(sizeof(VAL));
    assert(chain_get(c,"Chien", v1)==true);
    assert(chain_get(c,"chien", v1)==false);
    chain_delete(c, "Chien");
    assert(chain_get(c, "Chien", &n) ==false);
    chain_print(c);
    print_tab(tab_cle(c),3);
    chain_free(c);
    free(v1);
    /*FIN TEST dico_chaine.c*/
    printf("----------------------\n");
    /*DEBUT TEST dico_hash.c*/
    hashtable_t* h = hash_create();
    assert(hash_get(h, "Salut", &n) ==false);
    hash_set(h, "Chat", 1);
    hash_set(h, "Chien", 2);
    hash_set(h, "Vache", 3);
    hash_set(h, "Poule", 4);
    hash_print(h);
    printf("-----\n");
    VAL* v2 = malloc(sizeof(VAL));
    assert(hash_get(h,"Chien", v2)==true);
    assert(hash_get(h,"chien", v2)==false);
    hash_delete(h, "Chien");
    assert(hash_get(h, "Chien", &n) ==false);
    hash_print(h);
    hash_free(h);
    free(v2);

    /*FIN TEST dico_hash.c*/
}