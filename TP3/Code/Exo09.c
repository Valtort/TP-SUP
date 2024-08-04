#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define MAX_SIZE 1024

/* Le but de cet exercice est d'écrire un programme qui simule une petite mémoire
RAM. Ce programme possèdera un tableau en variable globale, et proposera en boucle
à l'utilisateur le menu suivant :
Que voulez vous faire ?
1. Accéder à une valeur
2. Stocker une valeur
3. Faire une addition
4. Quitter le programme*/

/* Mémoire adressable simple

Ce programme permet à l'utilisateur de manier une (fausse) mémoire d'entiers.
Il choisit une taille de mémoire, puis peut lire, écrire et effectuer des
additions. */



int size; // taille réelle de la mémoire
int mem_tab[MAX_SIZE]; // tableau des cases mémoires
bool no_value[MAX_SIZE]; // no_value[i] = 1 si une case n'a jamais reçu de valeur

/* Teste si l'indice i est valide pour une lecture,
   i.e. si la case i existe dans la mémoire
   Si ce n'est pas le cas, lève une erreur d'assertion. */
void assert_write(int i){
	assert(0 <= i && i < size);	
}

/* Teste si l'indice i est valide pour une lecture,
   i.e. si la case i existe et contient une vraie valeur.
   Si ce n'est pas le cas, lève une erreur d'assertion. */
void assert_read(int i){
	assert(0 <= i && i < size);	
    assert(!no_value[i]); 
}



/* Renvoie l'entier contenu dans la case i de la mémoire, si
   i est une case valide à lire. */
int get(int i){
	assert_read(i);
	return mem_tab[i];
}

/* Pour stocker une valeur */
void set(int i, int x){
    assert_write(i);
    no_value[i] = false;
    mem_tab[i] = x;
}


/* Pour l'addition */
void somme(int a, int b, int c){
    set(c, get(a) + get(b));
}



int main()
{
	// initialisation
	printf("Choisir la taille de la mémoire: ");
	scanf("%d", &size);

	// au départ, toutes les cases sont invalides à lire
	for (int i = 0; i < size; ++i)
	{
		no_value[i] = true;
	}

	int i, j, k, x; // pour la saisie de l'utilisateur

	// boucle Input/Ouput
	bool quit = false;
	while (!quit){
		int choix;
		printf("Que voulez vous faire\n");
		printf("1. Accéder à une valeur\n");
		printf("2. Stocker une valeur\n");
		printf("3. Faire une addition\n");
		printf("4. Quitter le programme\n");
		printf("Choix: ");
		scanf("%d", &choix);

		// traiter le choix
        if (choix == 2){ // CAS 1
            printf("Rentrer l'adresse mémoire puis la valeur à stocker: ");
            scanf("%d %d", &i, &x);
            set(i,x);
            printf("La valeur %d a bien été stocké dans la case %d\n", x, i);
        }
        if (choix == 1){ // CAS 2
            printf("Rentrer l'adresse mémoire: ");
            scanf("%d", &i);
            printf("La case %d contient %d\n", i, get(i));
        }
        if (choix == 3){ // CAS 3
            printf("Rentrer l'adresse mémoire des deux nombres à sommer puis la case où stocker la somme: ");
            scanf("%d %d %d", &i,&j,&k);
            somme(i,j,k);
            printf("La valeur %d a bien été stocké dans la case %d\n", get(k), k);
        }
        if (choix == 4){
            quit = true;
        }
        else{
            printf("Vous n'avez pas entré un chiffre valide !\n");
        }
	}

	printf("Au revoir\n");
	return 0;
}

