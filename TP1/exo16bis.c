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

    
    return 0;
}