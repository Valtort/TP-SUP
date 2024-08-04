#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
// Ce programme vise à tester les fonctions les plus connues de la librairie string.h


int main(){
    char s[20] ="Coucou"; // 6 lettres
    char s1[20] = "Salut";
    char s2[20] = "Bonjour";

    printf("%ld\n", strlen( s));
    printf("%d\n", strcmp( s1,  s2) );
    strcat(s1, s2 );
    printf("%s\n", s1);
    strcpy(s1, s2);
    printf("%s\n", s1);
    return 0;
}   