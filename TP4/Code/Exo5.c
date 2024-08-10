#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//Renvoie un booléen indiquant si les tableaux t1 et t2 contiennent les mêmes valeurs
// On supp qu'ils ont même taille n
bool egaux(int* t1, int* t2, int n){
    for(int i=0; i<n; i++){
        if(t1[i]!=t2[i]){
            return false;
        }
    }
    return true;
}

//renvoie un tableau de taille n, toutes les cases à 0
int* zeros(int n){
    int* t = malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        t[i] =0;
    }
    return t;
}

//Renvoie un tableau de booléens, dont les n premières valeurs sont fausses
// et dont les m suivantes sont vraies
bool* zeros_un(int n, int m){
    bool* t = malloc((n+m)*sizeof(bool));
    for(int i=0; i<n; i++){
        t[i] =false;
    }
    for(int i=n; i<(n+m); i++){
        t[i] = true;
    }
    return t;
}

//Lit dans le fichier f jusqu'à *n flottans. Stocke dans l'adresse pointée par n
// le nombre de flottans effectivement lus.
float* lire_flottants(FILE* f, int* n){
    int taille = *n;
    int compteur =0;
    float* tab = malloc(taille*sizeof(float));
    while(fscanf(f,"%f", &tab[compteur]) != EOF && compteur <taille){
        compteur++;
    }
    *n = compteur;
    return tab;
}

//Affiche le tableau t de taille n
void print_tab(bool* tab, int n){
    printf("{");
    for(int i=0;i<n-1;i++){
        printf("%d, ", tab[i]);
    }
    printf("%d}\n", tab[n-1]);
}

//idem pour des flottants
void print_tab_float(float* tab, int n){
    printf("{");
    for(int i=0;i<n-1;i++){
        printf("%f, ", tab[i]);
    }
    printf("%f}\n", tab[n-1]);
}


int main(){
    bool* tab_bool = zeros_un(5, 12);
    print_tab(tab_bool, 17);
    int n=10;
    FILE* test = fopen("Test_Exo5.txt", "r");
    assert(test!=NULL);
    printf("n avant : %d\n", n);
    float* tab_float = lire_flottants(test, &n);
    print_tab_float(tab_float, 5);
    printf("n après : %d\n", n);
    free(tab_bool);
    free(tab_float);
    fclose(test);
    return 0;
}
