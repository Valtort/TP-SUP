#include <stdio.h>

int main(){
    int x;
    printf("Entrez un entier x: \n");
    scanf("%d", &x);
    if(x%3 == 0){
        printf("gou");
    }
    if(x%5 == 0){
        printf("ba\n");
    }
    if((x%5 != 0) && (x%3 != 0)){
        printf("%d\n", x);
    }
    // Affiche gou si le nombre est divisible par 3, ba s'il l'est par 5, gouba s'il l'est par 5 et 3, sinon, affiche le nombre
    
    return 0;
}