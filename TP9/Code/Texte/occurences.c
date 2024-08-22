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
    KEY k = malloc(100*sizeof(char*));//On part du principe qu'aucune clé ne dépassera 99 caractères
    VAL max = 0;//Comme on ne travaille qu'avec des entiers >=0, le max est zéro au début
    for(int i=0; i<(d->m); i++){
        argmax_tab(d->t[i], &k, &max);
    }
    return k;
}

hashtable_t* occurences(char* filename, int K){
    FILE* f = fopen(filename, "r");
    hashtable_t* h = hash_create();
    char* lecture = malloc(100*sizeof(char));
    VAL v;
    while(fscanf(f, "%s", lecture) != EOF){
        v=-1;
        
        if(strlen(lecture) >= K){
            int i = hash(lecture)%(h->m);
            maillon_t* m = h->t[i]->head;
            //On récupère la valuer de lecture, si elle existe déjà
            while(m!=NULL){
                if(strcmp(m->key, lecture)==0){
                    v = m->val;
                    m= m->next;
                }
            }
            free(m); //On ne s'en sert plus.

            if( v != -1){   
                v++;
                hash_set(h, lecture, v);
            }
            else{
                hash_set(h, lecture, 0);
            }
              

        }
    }
    free(lecture);
    fclose(f);
    return h;
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
    hash_print(h);
    printf("-----\n");
    KEY k = argmax(h);
    printf("La clé de la plus grande valeur est : %s\n", k);
    hash_free(h);
    /*FIN TEST argmax*/
    printf("----------------------\n");
    /*DEBUT TEST occurences*/
    hashtable_t* d = occurences("test.txt", 4);
    hash_print(d);
    hash_free(d);
    /*FIN TEST occurences*/
}

int main(){
    test();
    return 0;
}