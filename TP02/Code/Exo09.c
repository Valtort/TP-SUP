#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
// Programme qui contient toutes les questions de l'exo9


// Je n'ai pas le droit d'utilisé de boucle, tout doit être fait avec du récursif


//Prend un entier n et affiche les n premiers entiers dans l'ordre décroissant
void decroit(int n){
    assert(n>=0);
    if(n==0){
        printf("0\n");
    }else{
        printf("%d\n", n);
        decroit(n-1);
    }
}

//Idem mais dans l'odre croissant
void croit(int n){
    assert(n>=0);
    if(n==0){
        printf("0\n");
    }else{
        croit(n-1);
        printf("%d\n", n);
    }
}

//Compte le nombre de chiffres qui composent un entier n
int nb_chiffre_rec(int n, int compteur){
    if((n==0) && (compteur ==0)){
        return 1;
    }
    else{
        if(n==0){
            return compteur;
        }
        else{
            compteur++;
            nb_chiffre_rec(n/10, compteur);
        }
    }
}  

int nb_chiffre(int n){
    return nb_chiffre_rec(n, 0);
} 

//Prend un entier n et le décompose, par exemple : -894 donnera
/*
-
8
9
4
*/
void decompose_rec(int n, int nb_chiffres){
    if(n<0){
        n=-1*n;
        printf("-\n");
    }
    if(n!=0){
        decompose_rec(n/10, nb_chiffres);
        printf("%d\n", n%10);
    }
}

void decompose(int n){
    decompose_rec(n, nb_chiffre(n));
}

//Affiche n fois "O" puis revient à la ligne 
void affiche_O(int n){
    assert(n>=0);
    if(n!=0){
        printf("O");
        affiche_O(n-1);
    }
    else{
        printf("\n");
    }
}

// Décompose un nombre puis affiche la lettre O sur chaque ligne, en associant le nombre d'occurence au nombre décomposé, par exemple
/* Pour -894 : 
-
OOOOOOOO
OOOOOOOOO
OOOO
*/
void decompose_et_affiche_rec(int n, int nb_chiffres){
    if(n<0){
        n=-1*n;
        printf("-\n");
    }
    if(n!=0){
        decompose_et_affiche_rec(n/10, nb_chiffres);
        affiche_O(n%10);
    }
}

void decompose_et_affiche(int n){
    decompose_et_affiche_rec(n, nb_chiffre(n));
}


int main(){
    //Test décroit
    decroit(10);
    //Test croit
    croit(10);
    //Test decompose
    decompose(-547);
    //Test affiche_O
    affiche_O(5);
    //Test decompose_et_affiche
    decompose_et_affiche(-894);
}