#include <stdio.h>

int main(){
    int x = 6;
        int* px = &x; //adresse de x
    int y = *px ; //valeur stockée à partir de l'octet pointé par px
    printf("y vaut %d\n", y);
    return 0;    
}