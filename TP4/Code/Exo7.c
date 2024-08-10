#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*
Ce programme a pour but de lire toutes les lignes d'un fichier et de les
afficher en indiquant le numéro de la ligne
*/


//Implémentation de getline dans laquelle on suppose que buffer point forcément
// vers un pointeur nul.
//On utilisera realloc et on doublera la taille à chaque fois qu'on dépasse celle alloué
int ma_getline(char** buffer, unsigned long int* n, FILE* f){
    unsigned long int taille = 10;
    *buffer = malloc(taille*sizeof(char*));
    char* ligne = *buffer;
    *n=taille;
    char lecture;
    int compteur =0;
    while(fscanf(f, "%c", &lecture) != EOF){
        ligne[compteur] = lecture; 
        if (lecture == '\n'){
            return compteur+2;
        }

        compteur++;
        if(compteur>=taille-2){
            taille = taille * 2;
            *n = taille;
            *buffer = realloc(*buffer, taille*sizeof(char));
            ligne = *buffer;
        }
        
    }
    if(fscanf(f, "%c", &lecture) == EOF && compteur ==0){
        return -1;
    }
    else{
        return compteur+2;
    }
}





int main(int argc,char** argv){
    if(argc != 2){
        printf("Vous n'avez pas saisi le nom d'un seul fichier !\n");
        exit(1);
    }
    char* name = argv[1];
    FILE* fichier = fopen(name, "r");
    assert(fichier != NULL);
    char* ligne = NULL;
    long unsigned int n=0;
    int compteur_ligne=1;
    int len = ma_getline(&ligne, &n, fichier);
    char sauv;
    while(len !=-1){
        printf("%d. %s", compteur_ligne, ligne);
        len = ma_getline(&ligne, &n, fichier);
        compteur_ligne++;
    }
    printf("\n");
    fclose(fichier);
    return 0;
}