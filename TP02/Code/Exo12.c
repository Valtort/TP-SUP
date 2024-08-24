#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// Le but de ce programme est de calculer le n-ème terme de la suite de fibonacci

//Calcul le n-ème terme de la suite de fibonacci
long int fibo_rec(int n, long int u1, long int u0){
    assert(n>0);
    assert(u1>=0);
    assert(u0>=0);
    if (n==0){
        return u0;
    }
    if(n==1){
        return u1;
    }
    return fibo_rec(n-1, u1+u0, u1);
}

// On utilise des long int pour pouvoir pousser la limite au 93ème terme
long int fibo(int n){
    return fibo_rec(n, 1, 0);
}

int main(){
    printf("%ld\n", fibo(92));

    return 0;
}