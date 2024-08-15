#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

struct eleve{
    char nom_complet[50];
    int jour, mois, annee; //date de naissance
    char metier[50];
};
typedef struct eleve eleve_t;

//Lis dans un fichier f et renvoie les données d'un élève.
eleve_t* lire_eleve(FILE* f){
    long unsigned int n = 50;
    eleve_t* eleve = malloc(sizeof(eleve_t));
    char* lecture = malloc(50*sizeof(char));
    int len = getline(&lecture, &n, f);
    lecture[len-1] = '\0';
    strcpy(eleve->nom_complet, lecture);


    fscanf(f, "%d", &eleve->jour);
    fscanf(f, "%d", &eleve->mois);
    fscanf(f, "%d", &eleve->annee);
    char poubelle;
    fscanf(f, "%c", &poubelle); //supprime le '\n'

    
    len = getline(&lecture, &n, f);
    lecture[len-1] = '\0';
    strcpy(eleve->metier, lecture);

    free(lecture);
    return eleve;
}

//lis une promo entiere
eleve_t** lire_promo(char* filename,int* n){
    FILE* f = fopen(filename, "r");
    assert(f != NULL);
    fscanf(f, "%d", n);
    char poubelle;
    fscanf(f, "%c", &poubelle); // supprime le '\n'
    eleve_t** eleve_tab = malloc((*n) * sizeof(eleve_t*));
    for(int i=0; i<*n; i++){
        eleve_t* eleve = lire_eleve(f);
        eleve_tab[i] = eleve;
    }
    fclose(f);
    return eleve_tab;
}

int main(){
    char* filename = "promo_2013.txt";
	int n;
	eleve_t** promo = lire_promo(filename, &n);

	printf("Cette promo contient %d élèves :\n", n);
	for (int i = 0; i < n; ++i){
		eleve_t* e = promo[i];
		printf("%s est né le %d.%d.%d. Son metier est : %s\n\n", e->nom_complet, e->jour, e->mois, e->annee, e->metier);
	}

	for (int i = 0; i < n; ++i){
		free(promo[i]);
	}
	free(promo);

    return 0;
}