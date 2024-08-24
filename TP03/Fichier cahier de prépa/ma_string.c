#include <assert.h>

/* Longueur de la chaîne s */
int ma_strlen(char* s){
	int i = 0;
	while (s[i] != 0){
		i++;
	}
	return i;
}

/* Comparaison de chaînes. Renvoie:
   - un entier < 0 si s1 < s2 
   - un entier > 0 si s1 > s2 
   - un entier = 0 si s1 = s2 
   selon l'ordre lexicographique/alphabétique.

   Principe de l'algorithme:
     Si les deux chaînes ne sont pas égales, alors il existe un indice où 
     elles diffèrent. Cela prend en compte le cas où la plus courte est un 
     préfixe de la deuxième (par exemple "chat" et "chateau") car alors on
     aura:
       c h a t \0
       c h a t e a u \0
   */
int ma_strcmp(char* s1, char* s2){
	int i=0;
	// invariant: s1[0..i[ = s2[0..i[
	while (s1[i] != 0 || s2[i] != 0){
		if (s1[i] != s2[i]){
			return s1[i] - s2[i]; // positif si s1 > s2, négatif si s1 < s2
		}
		i++;
	}
	// en sortie: s1[i] = s2[i] = '\0': on a lu les deux chaînes en entier
	// sans trouver de différence
	return 0;
}


/* Concatène la chaîne src à la fin de dst. dst est supposée contenir assez de place */
void ma_strcat(char* dst, char* src){
	int i;
	int l = ma_strlen(dst);
	for (i = 0; src[i] != '\0'; i++){
		dst[l+i] = src[i];
	}
	// ne pas oublier le caractère nul pour marquer la fin de chaîne
	dst[l+i] = src[i];
}


/* Copie la chaîne src dans dst. dst est supposée contenir assez de place */
void ma_strcpy(char* dst, char* src){
	// principe: transformer dst en chaîne vide puis appeler strcat
	dst[0] = '\0';
	ma_strcat(dst, src);
}




int main()
{
	char s1[20] = "test_1";
	char s2[10] = "";
	assert(ma_strlen(s1) == 6);
	assert(ma_strlen(s2) == 0);

	assert(ma_strcmp(s1, "test_1") == 0); 
	assert(ma_strcmp("alpha", "beta") < 0);
	assert(ma_strcmp("chateau", "chat") > 0);
	assert(ma_strcmp(s1, s2) > 0);


	char s3[40];
	ma_strcpy(s3, "bonjour");
	assert(ma_strcmp(s3, "bonjour") == 0);

	ma_strcpy(s3, s2);
	assert(ma_strlen(s3) == 0);	

	ma_strcat(s1, " bla");
	assert(ma_strcmp(s1, "test_1 bla") == 0);

	return 0;
}
