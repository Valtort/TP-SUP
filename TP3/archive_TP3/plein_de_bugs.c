/**** Triangle de Rousseau ****
 * 
 * Ce programme sert à afficher les triangles de Rousseau.
 * Le triangle d'ordre n aura n lignes. La i-ème ligne fait (i-1) unités
 * de large et pour j entre 1 et i-1, la ligne i contient un X à la j-ème 
 * place si et seulement si i%(j+1)%3 ne vaut pas 1.
 * Par exemple pour n = 10: 

X
  X
X   X
  X   X
X X X   X
    X X   X
X X X X X   X
  X     X X   X
X   X X   X X   X
 
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>


// Renvoie un booléen indiquant si n est pair.
bool est_pair(int n){ // Il y avait un int z en trop, et de 1 !
	if (n%2 == 0){
		printf("true\n");
		return true; // Deuxième erreur
	} else {
		printf("false\n");
		return false; // Et de 3 !
	}
}


// affiche la i-ème ligne du triangle de Rousseau
void ligne(int i){
	assert(i >= 0);
	// Il y avait un int t=3 inutile ici, quatrième erreur.

	// afficher chaque caractère de la ligne.
	// j varie de 1 à i-1 
	for (int j; j < i; j++) // Il y a marqué ++j, il faut mettre j++, c'est ma 9eme erreur trouvé !
	{
		if ((i%(j+1))%3 != 1){
			printf("X ");
		} else {
			printf("  ");
		}
	}
	printf("\n");
	// Il ne devrait pas y avoir de return 0; ici, 5 !
}


int main(){	 // Il n'y avait pas le int de int main, et de 6!
	srand(time(NULL));
    // nombre de lignes à afficher (n doit être positive)
	int n;
	
	printf("Rentrez le nombre de lignes à afficher: ");
	scanf("%d", &n); // Il n'y avait pas de &, 7 !
	assert(n >= 0); // Le assert n'était pas au bon endroit, et de 11
	for (int i = 1; i <= n; i++) // idem qu'a la ligne 47, il y avait ++i, 10 !
	{
		ligne(i);
	}

    int a = rand()%2000; // Il n'y avait pas de #include <time.h> ni de <stdlib.h >et de 8 !
	printf("Au fait, le saviez vous ?");
	printf(" %d ", a);
	if (est_pair(a)){
		printf("est pair !\n");
	} else {
		printf("n'est pas pair...\n");
	}
	

}