#include <stdio.h>

int main(){
    int x;
    printf("Entrez un entier x: \n");
    scanf("%d", &x);
    if(x < -0.33){
        printf("Cas A\n");
    }
    else{
        if(x>7.89){
            printf("Cas C\n");
        }
        else{
            printf("Cas B\n");
        }
    }
    //Voir le pdf pour les différents cas.
    return 0;
}