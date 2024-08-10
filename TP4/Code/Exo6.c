#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

//Renvoie une matrice null de dimensions n*m
int** zeros(int n, int m){
    int** mat = malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        mat[i] = malloc(m*sizeof(int));
        for(int j=0; j<m; j++){
            mat[i][j]=0;
        }
    }
    return mat;
}

//Renvoie une matrice de dimensions n*m dont chaque valeur est dans [a,b]
int** rand_mat(int n, int m,int a, int b){
    assert(b>=a);
    int** mat = malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        mat[i] = malloc(m*sizeof(int));
        for(int j=0; j<m; j++){
            mat[i][j]=a+(rand()%(b-a+1));
        }
    }
    return mat;
}

//libere la mémoire allouée pour une matrice
void free_mat(int** mat, int n){
    for(int i=0; i<n; i++){
        free(mat[i]);
    }
    free(mat);
}

//Affiche lun tableau t de taille n
void print_tab(int* tab, int n){
    printf("[");
    for(int i=0;i<n-1;i++){
        printf("%d, ", tab[i]);
    }
    printf("%d]\n", tab[n-1]);
}

//Affiche la matrice t de taille n
void print_mat(int** mat, int n, int m){
    printf("[\n");
    for(int i=0;i<n;i++){
        print_tab(mat[i], m);

    }

    printf("]\n");
}

//Renvoie la somme de mat1 et mat2
int** somme_mat(int** mat1, int** mat2, int n,int m){
    int** mat = zeros(n,m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mat[i][j] = mat1[i][j]+mat2[i][j];
        }
    }
    return mat;
}

//Calcule la moyenne des 8 cases voisines à la case (i,j) de la matrice mat n*m
float moyenne(int** mat, int i, int j, int n, int m){
    assert(i<n);
    assert(i>0);
    assert(j>0);
    assert(j<m);
    float moy=0;
    for(int k= i-1; k<i+2; k++){
        for(int l = j-1; l<j+2; l++){
            moy += mat[k][l];
        }
    }
    moy = moy /9;
    return moy;
}

/*Cherche dans la matrice, la case (i,j) pour laquelle la moyenne des 8 cases
voisines est la plus petite. Affiche la moyenne ainsi que le numéro de la case (i,j)*/
void min_moy(int** mat, int n,int m){
    float min = moyenne(mat, 1,1,n,m);
    float moy;
    int imin=1;
    int jmin=1;
    
    for(int i=2; i<n-1;i++){
        for(int j=1; j<m-1;j++){
            moy = moyenne(mat, i,j,n,m);
            if(moy<min){
                min = moy;
                jmin = j;
                imin= i;
            }
        }
    }
    printf("La case avec la moyenne la plus petite est : (%d, %d)\n", imin, jmin);
    printf("Cette moyenne vaut : %f\n", min);
}

int main(){
    srand(time(NULL));
    int** mat1 = rand_mat(15, 12, 0, 20);
    int** mat2 = rand_mat(15, 12, 0, 20);
    print_mat(mat1, 15 ,12);
    print_mat(mat2, 15 ,12);
    int** mat = somme_mat(mat1, mat2, 15 ,12);
    print_mat(mat, 15 ,12);

    min_moy(mat, 15,12);

    free_mat(mat, 15);
    free_mat(mat1, 15);
    free_mat(mat2, 15);
    return 0;
}