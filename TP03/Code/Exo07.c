#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
// Le but de ce programme est de manipuler des tableaux.


//Calcule la somme des n premiers entiers d'un tableau, n doit être <=100
int somme(int* tab, int n){
    assert(n<=100);
    int res = 0;
    for(int i=0; i<n; i++){
        res=res + tab[i];
    }
    return res;
}

//Affiche les n premieres cases d'un tableau
void affiche(int* tab, int n){
    assert(n<=100);
    printf("[");
    for(int i=0; i<n-1; i++){
        printf("%d, ", tab[i]);
    }
    printf("%d]\n", tab[n-1]);
}

/*Remplit les n premières cases de T avec des entiers aléatoires entre -10 et 10*/
void remplit(int* tab, int n){
    assert(n<=100);
    for(int i=0; i<n; i++){
        tab[i] = rand()%21 -10;
    }
}

/*Remplit les n+1 premières cases de U en stockant dans les U[i] la somme des
i premières cases de T*/
void remplit_somme(int* tabT, int* tabU , int n){
    assert(n<=100);
    for(int i=0; i<n+1; i++){
        tabU[i] = somme(tabT, i);
    }
}


int main(){
    srand(time(NULL));
    int t[6] = {2, 3, 5, 1,-3 ,3};
    int u[8] = {0, 0, 0, 0,0 ,0 ,0 };
    printf("%d\n", somme(t, 6));
    affiche(t, 6);
    remplit_somme(t,u, 6);
    affiche(u, 7);
    return 0;
}