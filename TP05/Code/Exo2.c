#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct maillon{
    struct maillon* suivant;
    int valeur;
};
typedef struct maillon maillon_t;

struct liste{
    unsigned int taille;
    maillon_t* tete; //premier maillon
};
typedef struct liste liste_t;

//renvoie une liste chaînée dont les maillons contiennent 0,1,...,n-1
liste_t* range(int n){
    assert(n>=1);
    liste_t* liste = malloc(sizeof(liste_t));
    liste->taille = n;
    liste->tete = malloc(sizeof(maillon_t));
    maillon_t* maillon_actuelle = liste->tete;
    liste->tete->suivant = NULL;
    maillon_actuelle->valeur =0;
    for(int i=1; i<n; i++){
        maillon_actuelle->suivant = malloc(sizeof(maillon_t));
        maillon_actuelle = maillon_actuelle->suivant;
        maillon_actuelle->valeur = i;
        maillon_actuelle->suivant = NULL;
    }
    return liste;
}

//Affiche une liste (sans récursivité)
void print_liste(liste_t* l){
    maillon_t* maillon_actuelle = l->tete;
    printf("[");
    while(maillon_actuelle !=NULL){
        printf("%d ", maillon_actuelle->valeur);
        maillon_actuelle = maillon_actuelle->suivant;
    }
    printf("]\n");
}

//Libere la mémoire d'une liste chainé (sans récursivité)
void free_liste(liste_t* liste){
    maillon_t* maillon_actuelle = liste->tete;
    maillon_t* maillon_suiv = maillon_actuelle->suivant;
    while(maillon_suiv !=NULL){
        free(maillon_actuelle);
        maillon_actuelle = maillon_suiv;
        maillon_suiv = maillon_actuelle->suivant;
    }
    free(maillon_actuelle);
    free(liste);
}

bool recherche(int x, liste_t* L){
    maillon_t* maillon_actuelle = L->tete;
    while(maillon_actuelle != NULL){
        if(maillon_actuelle->valeur == x){
            return true;
        }
        maillon_actuelle = maillon_actuelle->suivant;
    }
    return false;
}

//Ajoute un elem x à la fin d'une liste chainée
void ajout_fin(liste_t* l, int x){
    maillon_t* maillon_actuelle = l->tete;
    while(maillon_actuelle->suivant != NULL){
        maillon_actuelle = maillon_actuelle->suivant;
    }
    //On se déplace jusqu'à la fin de la liste
    
    maillon_actuelle->suivant = malloc(sizeof(maillon_t));
    maillon_actuelle = maillon_actuelle->suivant;
    maillon_actuelle->valeur = x;
    maillon_actuelle->suivant = NULL;
}

//Ajoute un elem x au début d'une liste chainée l
void ajout_debut(liste_t* l, int x){
    maillon_t* sauvegarde = l->tete->suivant;
    maillon_t* insertion = malloc(sizeof(maillon_t));
    l->tete->suivant = insertion;
    insertion->suivant = sauvegarde;
    insertion->valeur = l->tete->valeur;
    l->tete->valeur = x;

}

// APPROFONDISSEMENT : 
//Recherche un élément x et dans la liste l, supprime le premier maillon
//où celui-ci apparait.
void suppr(liste_t* l, int x){
    if(l->tete->valeur == x){
        maillon_t* suiv = l->tete->suivant;
        free(l->tete);
        l->tete = suiv;
    }
    else{
        maillon_t* maillon_prec = l->tete; 
        maillon_t* maillon_actuelle = l->tete->suivant;
        maillon_t* maillon_suiv = maillon_actuelle->suivant;
        while(maillon_actuelle != NULL){
            if(maillon_suiv == NULL && maillon_actuelle->valeur == x){
                free(maillon_actuelle); // On n'a pas besoin de "raccordé", on supprime juste le maillon
                maillon_prec->suivant = NULL;
                maillon_actuelle = NULL; // Pour sortir de la boucle
            }
            else{
                if(maillon_actuelle->valeur == x){
                    free(maillon_actuelle);
                    maillon_prec->suivant = maillon_suiv;
                    maillon_actuelle = NULL;
                }
                else{
                    maillon_prec = maillon_prec->suivant;
                    maillon_actuelle = maillon_actuelle->suivant;
                    maillon_suiv = maillon_suiv->suivant;
                }
            }
        }
    }
}


int main(){

    liste_t* l = range(10);
    print_liste(l);
    printf("%d\n", recherche(9,l));
    printf("%d\n", recherche(10,l));
    ajout_fin(l, 88);
    ajout_debut(l, 77);
    print_liste(l);
    suppr(l, 88);
    print_liste(l);
    suppr(l, 77);
    print_liste(l);
    ajout_fin(l, 2);
    suppr(l, 2);
    print_liste(l);
    free_liste(l);
    return 0;   
}