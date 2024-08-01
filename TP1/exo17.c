#include <stdio.h>
#include <time.h>

int main(){
    long int t = time(NULL);
    int annee = 1970 + (t/(3600*24*365.24));
    int mois = (t/(3600*24*30.38));
    printf("Nous sommes le %dème mois de l'an %d\n", (mois%12), annee);
    return 0;
}