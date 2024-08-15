#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


struct CHOIX{
    char* texte;
    int page_suivante;
};
typedef struct CHOIX choix_t;

struct PAGE{
    char* texte;
    int n_choix;
    struct CHOIX** choix;
};
typedef struct PAGE page_t;

struct LIVRE{
    int n_pages;
    struct PAGE** pages;
};
typedef struct LIVRE livre_t;

//Prend un fichier f, renvoie un pointeur de structure de type
// struct CHOIX en utilisant les données du choix
choix_t* generer_choix(FILE* f){
    choix_t* choix = malloc(sizeof(choix_t));
    long unsigned int n = 800;

    choix->texte = malloc(800*sizeof(char));
    int len = getline(&choix->texte, &n, f);

    fscanf(f, "%d", &choix->page_suivante);
    char poubelle;
    fscanf(f, "%c", &poubelle); //supprime le '\n'

    return choix;
}

//Prend un fichier f, renvoie un pointeur de type page_t
//en utilisant les données de la page
page_t* generer_page(FILE* f){
    page_t* page = malloc(sizeof(page_t));
    long unsigned int n = 800;

    int n_choix = 0;
    fscanf(f, "%d", &n_choix);
    
    char poubelle;
    fscanf(f, "%c", &poubelle); //Supprime le '\n'

    page->n_choix = n_choix;

    page->texte = malloc(800*sizeof(char));
    int len = getline(&page->texte, &n, f);

    choix_t** choix = malloc((n_choix+1)*sizeof(choix_t*));// on fait +1 pour ne pas avoir de problèmes lors du cas n_choix = 0

    
    for(int i=0; i<n_choix; i++){
        choix[i] = generer_choix(f);
    }
    page->choix = choix;
    return page;
}

//Prend un fichier f, renvoie un pointeur de type livre_t
//en utilisant les données du livre
livre_t* generer_livre(FILE* f){
    livre_t* livre = malloc(sizeof(livre_t));
    fscanf(f, "%d", &livre->n_pages);
    char poubelle;
    fscanf(f, "%c", &poubelle);
    page_t** pages = malloc((livre->n_pages)*sizeof(page_t*));
    for(int i=0; i<livre->n_pages; i++){
        pages[i] = generer_page(f);
    }
    livre->pages = pages;
    return livre;
}

//Libere la mémoire d'un choix
void free_choix(choix_t* choix){
    free(choix->texte);
    free(choix);
}

//Libere la mémoire d'une page
void free_page(page_t* page){
    for(int i=0; i< page->n_choix; i++){
        free_choix(page->choix[i]);
    }
    free(page->texte);
    free(page->choix);
    free(page);
}

//Libere la mémoire d'un livre
void free_livre(livre_t* livre){
    for(int i=0; i<livre->n_pages; i++){
        free_page(livre->pages[i]);
    }
    free(livre->pages);
    free(livre);
}


int main(){
    FILE* f = fopen("multiverse.txt","r");
    assert(f != NULL);
    livre_t* livre = generer_livre(f);
    bool jeu_en_cours = true;
    int nb_page_actuelle = 0;
    page_t* page_actuelle;
    int choix;
    int nb_choix;
    while(jeu_en_cours){
        page_actuelle = livre->pages[nb_page_actuelle];
        printf("%s\n\n", page_actuelle->texte);
        nb_choix = page_actuelle->n_choix;
        for(int i=0; i<nb_choix; i++){
            printf("%d. %s\n\n", i+1, page_actuelle->choix[i]->texte);
        }
        if(nb_choix ==0){
            printf("Merci d'avoir joué!\n");
            jeu_en_cours = false;
        }
        else{
            printf("Votre choix : ");
            scanf("%d", &choix);
            assert(choix<=nb_choix);
            assert(1<=choix);
            nb_page_actuelle = page_actuelle->choix[choix-1]->page_suivante;
            printf("\n");
        }

    }
    fclose(f);
    free_livre(livre);
    return 0;
}
