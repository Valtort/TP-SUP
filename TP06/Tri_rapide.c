#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>
/*le but de ce programme est d'implémenter le tri rapide*/


//Determine si un tableau est trié
bool est_trie(int* T,int n){
    for(int i=0; i<n-1; i++){
        if( T[i-1]>T[i]){
            return false;
        }
    }
    return true;
}

//tri un tableau T de taille n
void tri_insertion(int* T, int n){
    for(int i=1; i<n-1; i++){
        int sauv = T[i];
        int j =i;
        while(j >0 && T[j-1] > sauv){
            T[j] = T[j-1];
            j--;
        }
        T[j] = sauv;
    }
}

//Algorithme de partition d'un tableau T de taille b-a+1 avec un pivot p
// Prend en entré a (l'indice de la première case) et b (l'indice de la dernière)
int partition(int* T,int a,int b, int p){
    int pos=a;

    //Echange pivot et dernier
    int sauv;
    sauv = T[p];
    T[p]= T[b];
    T[b] = sauv; 

    for(int i=a; i<=b-1; i++){
        if(T[i]<=T[b]){
            sauv = T[i];
            T[i]= T[pos];
            T[pos] = sauv;

            pos++;
        }
    }
    sauv = T[b];
    T[b]= T[pos];
    T[pos] = sauv; 
    return pos;
}

//Algo de tri rapide sur un tableau de taille b-a+1
// Prend en entré a (l'indice de la première case) et b (l'indice de la dernière)
void tri_rapide(int* T, int a, int b){
    int pivot;
    if(a<b){
        pivot = a;
        pivot = partition(T, a, b, pivot);
        tri_rapide(T, a, pivot-1);
        tri_rapide(T, pivot+1, b);
    }
}


//Créer 20 tableaux de taille n, les trie avec le tri rapide, renvoie le nombre
// moyen de milisecondes écoulé par tableau.
float test_tri_rapide(int n){
    clock_t total = 0;
    for(int i=0; i<20; i++){
        int* T = malloc(n*sizeof(int));
        for(int j=0; j<n; j++){
            T[j] = rand()%100;
        }
        clock_t debut = clock();
        tri_rapide(T, 0, n-1);
        clock_t fin = clock();
        assert(est_trie(T, n));
        total = total + fin - debut;
        free(T);
    }
    float moy = total/20;
    return 1000*moy/(1000000);
}


//Créer 20 tableaux de taille n, les trie avec le tri par insertion, renvoie le nombre
// moyen de milisecondes écoulé par tableau.
float test_tri_insertion(int n){
    clock_t total = 0;
    for(int i=0; i<20; i++){
        int* T = malloc(n*sizeof(int));
        for(int j=0; j<n; j++){
            T[j] = rand()%100;
        }
        clock_t debut = clock();
        tri_insertion(T, n);
        clock_t fin = clock();
        assert(est_trie(T,n ));
        total = total + fin - debut;
        free(T);
    }
    float moy = total/20;
    return 1000*moy/(1000000);
}

int main(){
    srand(time(NULL));
    printf("Le temps d'éxécution moyen est de : %f millisecondes\n", test_tri_rapide(1000000));
    return 0;
}