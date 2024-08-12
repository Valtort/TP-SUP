#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct etudiant {
	char* prenom;
	unsigned int age;
};
typedef struct etudiant etu_t;

typedef struct equipe{
	unsigned int nb_membres;
	etu_t** membres; // tableaux de pointeurs vers les membres de l'equipe
	unsigned int indice_cpt; // indice du capitaine dans le tableau des membres
} equipe_t;


//Affiche un etudiant
void print_etu(etu_t* e){
    printf("Prenom : %s\n", e->prenom);
    printf("Age : %d\n", e->age);
}

//Affiche une equipe
void print_equipe(equipe_t* e){
    printf("Equipe de %d personnes :\n", e->nb_membres);
    for(int i=0; i<e->nb_membres; i++){
        printf("-------------\n");
        if(i==e->indice_cpt){
            printf("Capitaine !\n");
        }
        print_etu(e->membres[i]);
        
    }
}

//Fonction pour libérer la mémoire d'un étudiant
void free_etu(etu_t* e){
    free(e);
}

//Fonction pour libérer la mémoire d'un étudiant
void free_equipe(equipe_t* e){
    free(e->membres);
    free(e);
}

//Fonction pour agrandir une equipe, rajoute les membres de l'equipe source
//à l'équipe destination
//On rajoute l'equipe src à l'équipe dst et on free l'equipe src
void agrandir_equipe(equipe_t* dst, equipe_t* src){
    int tailledst = dst->nb_membres;
    int taillesrc = src->nb_membres;
    
    if(tailledst<=taillesrc){
        dst->indice_cpt = tailledst + src->indice_cpt; //Le capitaine de la plus grande equipe devient le capitaine
    }
    for(int i=0; i<taillesrc;i++){
        dst->membres[i+tailledst] = src->membres[i];
    }
    dst->nb_membres = tailledst + taillesrc;
    free_equipe(src);
}

int main(){
    etu_t* cam= malloc(sizeof(etu_t));
    cam->prenom = "Camille";
    cam->age=23;

    etu_t* lei = malloc(sizeof(etu_t));
    lei->prenom = "Leila";
    lei->age = 20;

    etu_t* thi = malloc(sizeof(etu_t));
    thi->prenom = "Thibault";
	thi->age = 22;

    etu_t* Marco = malloc(sizeof(etu_t));
    Marco->prenom = "Marco";
	Marco->age = 25;

    etu_t* Corentin = malloc(sizeof(etu_t));
    Corentin->prenom = "Corentin";
	Corentin->age = 182;

    etu_t* Calixte = malloc(sizeof(etu_t));
    Calixte->prenom = "Calixte";
	Calixte->age = 94;

    etu_t* Quentin = malloc(sizeof(etu_t));
    Quentin->prenom = "Quentin";
	Quentin->age = 62;

    equipe_t* e1 = malloc(sizeof(equipe_t));
    e1->nb_membres = 3;
    e1->indice_cpt = 1;
    e1->membres=malloc(7*sizeof(etu_t*));

    equipe_t* e2 = malloc(sizeof(equipe_t));
    e2->nb_membres = 4;
    e2->indice_cpt = 1;
    e2->membres=malloc(7*sizeof(etu_t*));


    e1->membres[0] = cam;
	e1->membres[1] = lei;
	e1->membres[2] = thi;

    e2->membres[0] = Quentin;
	e2->membres[1] = Marco;
	e2->membres[2] = Corentin;
	e2->membres[3] = Calixte;

   

   print_equipe(e1);
   printf("---------------------------------\n");
   print_equipe(e2);
   printf("---------------------------------\n");
   agrandir_equipe(e1, e2);
   print_equipe(e1);
   
   free_etu(cam);
   free_etu(lei);
   free_etu(thi);
   free_etu(Quentin);
   free_etu(Marco);
   free_etu(Calixte);
   free_etu(Corentin);
   free_equipe(e1);
    return 0;
}