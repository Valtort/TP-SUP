#ifndef list_H
#include "liste.h"
#endif
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>



/* Renvoie true si x est dans l, false sinon */
bool recherche(liste_t* l, T x){
    maillon_t* m = recup_avant(l); // On parcourt de gauche à droite
    while(m!=NULL){
        if(recup_value(m) == x){
            
            return true;
        }
        m = recup_suiv(m);
    }
    return false;
}

//fonction de test
void test(){
    liste_t* l = liste_vide();
    ajout_avant_bis(l, 5);
    ajout_arriere_bis(l, 7);
    ajout_avant_bis(l, 3);
    ajout_arriere_bis(l, 70);
    print_liste(l);
    assert(!recherche(l, 80));
    assert(recherche(l, 7));
    free_liste(l);
}

int main(){
    test();
    return 0;
}