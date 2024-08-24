#include <stdio.h>

int main(){
    int x;
    printf("Entrez un entier x: \n");
    scanf("%d", &x);
    if(x==0){
        printf("x vaut 0\n");
    }
    else{
        printf("x ne vaut pas 0\n");
    }
    return 0;
}