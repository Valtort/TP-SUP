#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/*Le but de ce programme est de découvrir argc et argv dans le main
ainsi que de recoder la commande cp du terminal*/


//Imite la fonction cp du terminal, prend en entrée un fichier in_fn et 
// le copie dans un fichier out_fn crée par le programme
void cp(char* in_fn, char* out_fn){
    FILE* in = fopen(in_fn, "r");
    assert(in != NULL);
    FILE* out = fopen(out_fn, "w");
    assert(out != NULL);
    char copie;
    while(fscanf(in, "%c", &copie) != EOF){
        fprintf(out, "%c", copie);
    }
    fclose(out);
    fclose(in);
}




int main(int argc, char** argv){

    //Q1
    // printf("%d", argc);
    // for(int i=0; i<argc; i++){
    //     printf("argv[%d] : %s\n",i, argv[i]);
    // }

    //Q2 Prend en entrée un argument un entier et affiche son carré. 
    // Si lancé sans argument, affiche un message d'erreur et s'arrête.
    // if(argc ==1){
    //     printf("Vous n'avez pas écrit de nombre !\n");
    //     exit(1);
    // }
    // else{
    //     int nombre = atoi(argv[1]);
    //     printf("Le carré de votre nombre est : %d\n", nombre*nombre);
    // }

    //Q3 Imite le comportement de la commande cp dans le terminal
    if(argc != 3){
        printf("Vous n'avez pas écrit le nom de deux fichiers !\n");
        exit(1);
    }
    else{
        cp(argv[1], argv[2]);
    }
    

    return 0;
}