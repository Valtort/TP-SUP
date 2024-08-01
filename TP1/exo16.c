#include <stdio.h>

int main(){
    int x,y,z;
    printf("Entrez des entiers pour x,y et z: \n");
    scanf("%d %d %d", &x, &y, &z);
    if((x <= y && z <= x) || (x <= z && y <= x)){
        printf("La médiane est %d\n", x);
    }
    else{
        if((y <= x && z <= y) || (y <= z && x <= y)){
            printf("La médiane est %d\n", y);
        }
        else{
            printf("La médiane est %d\n", z);
        }
    }
    return 0;
}