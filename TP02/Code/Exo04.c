#include <stdio.h>
#include <assert.h>

// Calcule la factorielle de n avec n positif ou nulle
int factorielle(int n){
    assert(n>=0);
    if (n==0){
        return 1;
    }
    else{
        return n*factorielle(n-1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", factorielle(n));
    return 0;
}