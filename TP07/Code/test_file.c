#ifndef file_H
#include "file.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Programme de test pour les files*/

int main(){
    file_t* f = file_vide();
    if(est_file_vide(f)){
        printf("La file est vide\n");
    }
    else{
        printf("La file n'est pas vide\n");
    }
    enfiler(f, 5);
    enfiler(f, 4);
    enfiler(f, 3);
    printf("On défile et on obtient : %d\n", defiler(f));
    enfiler(f,1);
    enfiler(f,10);
    enfiler(f,20);
    enfiler(f,30);
    affiche_file(f);
    free_file(f);
}