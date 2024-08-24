#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/*Le but de ce programme est de découvrir la lecture de fichiers .txt*/


//Lit dans un fichier "filename", supposé contenir seulement des entiers,
//compte le nb d'entiers strictement positifs lus avant de lire un zéro
//renvoie -1 si elle ne rencontre pas de 0
int premier_zero(char* filename){
    FILE* fichier = fopen(filename, "r");
    assert(fichier != NULL);
    int lecture;
    int compte=0;
    while( fscanf(fichier, "%d", &lecture)!=EOF && lecture != 0 ){
        if(lecture >0){
            compte++;
        }
    }
    if(lecture !=0){
        fclose(fichier);
        return -1;
    }
    else{
        return compte;
    }
}

/*Prend en entrée un nom de fichier et une chaîne de caractères supposée sans espaces
compte le nb d'occurences de la chaîne dans le fichier. On nous dit que l'on peut
stocker chaque mot lu dans un tableau char mot[31]*/
int nb_occurences(char* filename, char* motif){
    FILE* file = fopen(filename, "r");
    char mot[31];
    int compte=0;
    while( fscanf(file, "%s", mot)!=EOF){
        if(strcmp(mot, motif)==0){
            compte++;
        }
    }
    fclose(file);
    return compte;
}

/*Prend en entrée deux noms de fichiers in_fn et out_fn, recopie le premier
dans le deuxieme en inversant chaques mots
On suppose qu'aucun mot ne fait plus de 50 caractères de long*/
void reverse(char* in_fn, char* out_fn){
    FILE* in = fopen(in_fn,"r");
    FILE* out = fopen(out_fn,"w");
    char mot[51];
    while( fscanf(in, "%s", mot)!=EOF){
        int len = strlen(mot);
        for(int i=len-1; i>=0; i--){
            fprintf(out, "%c", mot[i]);
        }
        fprintf(out, "%c", mot[len]); // permet de rajouter le \0 ou le \n a la fin des mots.
        printf("%s" , mot);
    }
}


int main(){
    printf("1er test : %d\n", premier_zero("1er_Test_Exo2.txt"));
    printf("2eme test : %d\n", premier_zero("2eme_Test_Exo2.txt"));
    printf("3eme test : %d\n", nb_occurences("3eme_Test_Exo2.txt", "chat"));
    printf("4eme test : %d\n", nb_occurences("3eme_Test_Exo2.txt", "Ananas"));
    reverse("4eme_Test_Exo2.txt", "4emebis_Test_Exo2.txt");
    
    return 0;
}