#include "dict.h"
#include "liste.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int main(){
    char** tab = malloc(4*sizeof(char*));
    tab[0] = "Guillaume";
    tab[1] = "Caroline";
    tab[2] = "Oliver";
    tab[3] = "Guillaume";
    assert(doublons(tab, 4));
    free(tab);
}
