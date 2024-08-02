#include <stdio.h>
#include <stdbool.h>

//Fichiers utilisés pour la question 3, référence plusieurs fonctions


// Determine si b divise a, avec a et b entier et b non nul
bool divise(int a, int b){
    if(a%b == 0){
        return true;
    }
    else{
        return false;
    }
}

//Affiche x et son inverse, x flottant non nul
void affiche_inverse(float x){
    printf("x: %f, 1/x: %f\n", x, 1/x);
}

//Etant donné x,y,z,t flottants, calcule 3x+5y-6.25z+t, l'affiche et renvoie son carré
float calcule(float x, float y, float z, float t){
    float resultat = 3*x+5*y-6.25*z+t;
    printf("Le résultat est : %f\n", resultat);
    return resultat*resultat;
}

int main(){
    //Test divise
    printf("5 divise-t-il 15? : %d, 15 divise-t-il 3? : %d\n", divise(15,5), divise(3,15));
    //Test affiche_inverse
    affiche_inverse(0.5);
    //Test calcule
    float resultat = calcule(1, 1, 1, 1);
    printf("Et maintenant le carré vaut : %f\n", resultat);
    return 0;
}