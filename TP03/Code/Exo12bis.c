#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Ce programme recode strcat, strlen, strcmp, strcpy


//Calcule la longueur d'un string
int ma_strlen(char* mot){
    int i=0;
    while(mot[i]!='\0'){
        i++;
    }
    return i;
}

// Concatène le mot2 avec le mot1
void ma_strcat(char* mot1, char* mot2){
    int taille1 = ma_strlen(mot1);
    int taille2 = ma_strlen(mot2);
    for(int i=0; i<taille2; i++){
        mot1[taille1+i] = mot2[i]; // On met +1 par rapport au caractère \0 du mot1
    }
    mot1[taille1+taille2] = '\0'; 
}

//Compare 2 chaines de caractères, renvoie 0 si les deux string sont égaux
// -1 si s1 est plus court que s2
// 1 si s1 est plus long que s2
int ma_strcmp(char* mot1, char* mot2){
    int taille1 = ma_strlen(mot1);
    int taille2 = ma_strlen(mot2);
    if (taille1 <taille2){
        return -1;
    }
    else{
        if(taille2 < taille1){
            return 1;
        }
        else{
            return 0;
        }
    }

}

//Copie le mot2 dans le mot1
void ma_strcpy(char* mot1, char* mot2){
    int taille2 = ma_strlen(mot2); 
    for(int i=0; i<taille2; i++){
        mot1[i]= mot2[i]; 
    }
    mot1[taille2] = '\0';
}

//On test dans le main
int main(){
    char Mot1[50]="Halloween"; //9 lettres
    char Mot2[50]="Burger";
    char Mot3[50]="Tiramisu";
    assert(ma_strlen(Mot1)==strlen(Mot1));
    assert(ma_strcmp(Mot1, Mot1) == strcmp(Mot1, Mot1) );
    ma_strcpy(Mot1, Mot2);
    assert( strcmp(Mot1,Mot2) == 0);
    ma_strcat(Mot2, Mot3);
    assert( strcmp(Mot2,  "BurgerTiramisu")==0);
    printf("Tout les tests ont réussi !\n");
    return 0;   
}