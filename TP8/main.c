#ifndef list_H
#include "liste.h"
#endif
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//fonction de test
void test(){
    liste_t* l = liste_vide();
    ajout_avant_bis(l, 5);
    ajout_arriere_bis(l, 7);
    ajout_avant_bis(l, 3);
    ajout_arriere_bis(l, 70);
    print_liste(l);
    free_liste(l);
}

int main(){
    test();
    return 0;
}