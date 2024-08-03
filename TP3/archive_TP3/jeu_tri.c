/**** JEU DU TRI ****/
/* [Consignes à effacer et à remplacer par un commentaire de documentation]
 * - Commencez par lire l'intégralité du code et des commentaires;
 * - Implémentez les 4 fonctions en suivant leur documentation, en n'oubliant
 *   pas les tests ni les assertions;
 * - Enfin, complétez le main en utilisant les 4 fonctions.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>
#define N 1000 // taille maximale autorisée


/* Échange les cases i et j de t un tableau supposé de taille n*/
void echange(int* t, int i, int j, int n){
	// A COMPLETER	
}


/* Détermine si le tableau t de n cases est trié dans l'ordre croissant
   au sens large */
bool est_trie(int* t, int n){
	// A COMPLETER
}


/* Affiche le tableau t de n cases avec un format 'à la python'. Par
   exemple:
      [2, 5, 8, 1, 3]   */
void print_tab(int* t, int n){
	// A COMPLETER
}

/* Remplit le tableau t de n cases avec des entiers aléatoires entre 0 et 50 */
void random_tab(int* t, int n){
	// A COMPLETER
}




int main()
{
	srand(time(NULL));

	/*** TESTS: cette partie sert à tester vos fonctions au fur et à mesure que vous les codez.
	 *   Il faudra bien penser à commenter tout le code de cette partie une fois que le programme
	 *   fonctionne comme vous voulez, afin de ne pas polluer l'affichage pour l'utilisateur ! ***/	
	// tests est_trie
	int t1[5] = {1, 2, 3, 5, 4};
	assert(!est_trie(t1, 5)); // le tableau n'est pas trié
	assert(est_trie(t1, 4)); // les 4 premières cases sont bien triées



	// tests print_tab (pas besoin d'assert ici, on se contente de constater visuellement à l'exécution)






	/*** FIN TESTS ***/


	// Variables
	int n; // taille effective du tableau
	int t[N]; // tableau
	int coups = 0; // nombre de coups joués

	printf("Bienvenue au jeu du tri. Choisissez la taille du tableau: ");
	scanf("%d", &n);
	assert(n <= N);

	// generation du tableau de jeu
	// A COMPLETER

	printf("Voici votre tableau:\n");
	print_tab(t, n);

	// Boucle entrée/sortie: afficher l'état du tableau, 
	// lire les entrées de l'utilisateur
	// puis mettre à jour, tant que le tableau n'est pas trié

	// A COMPLETER


	printf("Bravo !! vous avez gagné en %d coup(s)\n", coups);
	return 0;
}