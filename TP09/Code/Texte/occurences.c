#ifndef KVGUARD
#include "dico_chaine.h"
#endif
#ifndef KEY_H
#include "keyval.h"
#endif
#ifndef HASH_H
#include "dico_hash.h"
#endif
#ifndef occ_H
#include "occurences.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

/*Ce programme a pour but de trouver le nombre d'occurences dans un texte*/

void argmax_tab(chain_t* t, KEY* k, VAL* max){
    maillon_t* m = t->head;
    while(m!=NULL){
        if(m->val >= *max){

            *max = m->val;
            *k = m->key;
        }
        m=m->next;
    }
}


KEY argmax(hashtable_t* d){
    KEY k;//On part du principe qu'aucune clé ne dépassera 99 caractères
    VAL max = 0;//Comme on ne travaille qu'avec des entiers >=0, le max est zéro au début
    for(int i=0; i<(d->m); i++){
        argmax_tab(d->t[i], &k, &max);
    }
    return k;
}

hashtable_t* occurences(char* filename, int K){
    FILE* f = fopen(filename, "r");
    hashtable_t* h = hash_create();

    int taille_max = 100; //taille max d'un mot

    int nb_alloc = 1; //Servira pour realloc

    KEY* lecture = malloc(nb_alloc*sizeof(KEY)); //On utilise un tableau pour pouvoir associer les valeurs dans la table de hashe avec des pointeurs
    lecture[0] = malloc(taille_max*sizeof(char));
    VAL v;
    int compteur=1;
    while(fscanf(f, "%s", lecture[compteur-1]) != EOF){

        //Si on dépasse nb_alloc, on va le multiplier par deux et realloc
        if(compteur>=nb_alloc-1){
            int sauv = nb_alloc;
            nb_alloc = nb_alloc*2;
            lecture = realloc(lecture, nb_alloc*sizeof(char*));
            for(int i=sauv; i<nb_alloc; i++){
                lecture[i]=malloc(taille_max*sizeof(char));
            }
        }

        //Une valeur négative nous permet de savoir si on a rencontré la valeur ou non
        v=-1;
        if(strlen(lecture[compteur-1]) >= K){
            int i = hash(lecture[compteur-1])%(h->m);
            maillon_t* m = h->t[i]->head;
            //On récupère la valeur de la clé lecture, si elle existe déjà
            
            while(m!=NULL){
                
                if(strcmp(m->key, lecture[compteur-1])==0){
                    v = m->val; 
                }
                m= m->next;
            }

            if( v != -1){   
                v++;
                hash_set(h, lecture[compteur-1], v);
                free(lecture[compteur-1]);
            }
            else{
                hash_set(h, lecture[compteur-1], 1);
            }
              
            compteur++;
        }
        
    }
    for(int i=compteur-1; i<nb_alloc;i++){
        //On free ce qui n'est pas utilisé
        free(lecture[i]);
    }
    free(lecture);
    fclose(f);
    return h;
}

void mot_plus_frequent(char* filename, int K){
    hashtable_t* h = occurences(filename, K);
    KEY k = argmax(h);
    VAL v;
    hash_get(h, k , &v);
    printf("Le mot le plus fréquent est : %s, il a été compté %d fois.\n",k ,v);
    for(int i=0; i<h->m; i++){
        maillon_t* m = h->t[i]->head;
        while(m!=NULL){
            free(m->key);
            m= m->next;
        }
    }
   
    hash_free(h); 
}

void test(){
    /*DEBUT TEST argmax*/
    int n=0;
    hashtable_t* h = hash_create();
    assert(hash_get(h, "Salut", &n) ==false);
    //Classement de mes animaux préférés
    hash_set(h, "Chat", 1);
    hash_set(h, "Chien", 2);
    hash_set(h, "Ecureuil", 3);
    hash_set(h, "Rouge-Gorge", 4);
    hash_set(h, "Vache", 5);
    hash_set(h, "Poule", 6);
    hash_set(h, "Cacatoes", 4);
    hash_set(h, "Oie", 8);
    hash_print(h);
    printf("-----\n");
    KEY k = argmax(h);
    printf("La clé de la plus grande valeur est : %s\n", k);
    hash_free(h);
    /*FIN TEST argmax*/
    printf("----------------------\n");
    /*DEBUT TEST occurences*/
    hashtable_t* d = occurences("test.txt", 1);
    hash_print(d);
    hash_free(d);
    
    /*FIN TEST occurences*/
    printf("Tout les tests ont réussi !!!\n\n\n");
}

int main(){
    // test();
    mot_plus_frequent("vingt_mille_lieues.txt", 1);
    return 0;
}