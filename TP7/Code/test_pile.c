#ifndef pile_H
#include "pile.h"
#endif
#include <stdio.h>
#include <stdlib.h>


/*Programme de test pour les piles*/

int main(){
    pile_t* p = pile_vide();
    if(est_vide(p)){
        printf("La pile est vide\n");
    }
    else{
        printf("La pile n'est pas vide\n");
    }
    empiler(p, 5);
    empiler(p, 4);
    empiler(p, 3);
    printf("On dépile et on obtient : %d\n", depiler(p));
    empiler(p,1);
    print_pile(p);
    free_pile(p);
}