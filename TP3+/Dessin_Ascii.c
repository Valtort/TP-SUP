/* Le but de ce programme est de dessiné dans une grille de taille n*m
directement dans le terminal, chaques cases contiendra un caractère ASCII,
on pourra tracer diverses formes sur cette grille.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 24 // Nombre de lignes
#define M 30 // Nombre de colonnes de la grille

char grille[N][M];

// Affiche la grille
void print_grille(){
    for(int i=0; i<N; i++){
        if(i==0){
            printf("y\n");
            printf("^");
        }else{
            printf("|");
        }
        // Le bout de code ci-dessus sert à afficher l'axe y
        for (int j=0; j<M;j++){
            printf("%c", grille[j][i]);
        }
        printf("%d\n", N-1-i);
    }
    for(int i=0; i<M; i++){
        printf("-");
    }
    printf("> x\n");
}


/*Prend une coordonnée (x,y) et stocke le couple (i,j)
Par exemple pour (x,y)=(0,0), on aura le couple (i,j) = (0, M-1)
Sert a passé des coordonnées d'une matrice aux coordonnées cartésiennes
*/
void xy_to_ij(int x, int y, int* i, int* j){
    *i = x;
    *j = N-1-y;
}

//Dessine le caractère c aux coordonnées (x,y)
void draw_char(int x, int y, char c){
    int i;
    int j;
    xy_to_ij( x,  y, &i, &j);
    grille[i][j] = c;
}

//Determine le caractère à utiliser pour tracer une ligne
//entre (x1,y1) et (x2,y2)
char slope(int x1, int y1, int x2, int y2){
    int dx = x2-x1;
    int dy = y2-y1;
    float rapport;
    if(dx!=0){
        rapport = dy/dx;
    }
    
    if (dx==0 && dy==0){
        return ' ';
    }
    else if(dx==0){
        return '|';
    }
    else if(rapport < 0.5 && rapport >-0.5){
        return '-';
    }
    else if(rapport >=0.5 && rapport <=2){
        return '/';
    }
    else if(rapport >= -2 && rapport <= -0.5){
        return '\\'; // Afin de renvoyer '\'
    }
    else{
        return '|';
    }
}

//Trace une ligne entre (x1,y1) et (x2,y2)
void draw_line(int x1, int y1, int x2, int y2){
    int dx = x2-x1;
    int dy = y2-y1;
    char pente = slope(x1,y1,x2,y2);
    draw_char(x1,y1, pente);
    //On distingue 4 cas
    if(pente == '-'){
        if(dx >=0){ // ça veut dire que x2 est à droite de x1
            draw_line(x1+1, y1, x2, y2);
        }
        else{
            draw_line(x1-1, y1, x2, y2);
        }
    }
    else if(pente == '|'){
        if(dy>=0){ // ça veut dire que y2 est au dessus de y1
            draw_line(x1, y1+1, x2, y2);
        }
        else{
            draw_line(x1, y1-1, x2, y2);
        }
    }
    else if(pente == '/'){
        if(dy>=0 && dx>=0){ // ça veut dire que (x2,y2) est en haut à droite de (x1,y1)
            draw_line(x1+1, y1+1, x2, y2);
        }
        if(dy<0 && dx<0){// ça veut dire que (x2,y2) est en bas à gauche de (x1,y1)
            draw_line(x1-1, y1-1, x2, y2);
        }
    }
    else if(pente == '\\'){
        if(dy>=0 && dx<=0){ // ça veut dire que (x2,y2) est en haut à gauche de (x1,y1)
            draw_line(x1-1, y1+1, x2, y2);
        }
        if(dy<0 && dx>0){ // ça veut dire que (x2,y2) est en bas à droite de (x1,y1)
            draw_line(x1+1, y1-1, x2, y2);
        }
    }
    
}

// Dessine un rectangle, prend (x1,y1) les coordonnées du coin supérieur gauche et
// (x2,y2) les coordonées du coin inférieur droit
void draw_rectangle(int x1, int y1, int x2, int y2){
    draw_char(x1,y1, '.');
    draw_char(x1,y2, '.');
    draw_char(x2,y2, '.');
    draw_char(x2,y1, '.');
    draw_line(x1+1,y1,x2,y1);
    draw_line(x1,y1-1,x1,y2);
    draw_line(x2,y1-1,x2,y2);
    draw_line(x1+1,y2,x2,y2);
}

//Bonus ! Algo de Bresenham
void draw_Bresenham(int x1, int y1, int x2, int y2){
    int x,y,dx,dy;
    int e,e10,e01; //Valeur d'érreur et incréments
    dy = y2-y1;
    dx=x2-x1;
    y=y1;
    e = -dx;
    e10 = dy*2;
    e01 = -dx*2;

    for(int i=x1; i<=x2; i++){
        draw_char(i,y, slope(i,y,x2,y2));
        e= e + e10;
        if(e >= 0){
            y++;
            e=e+e01;
        }
    }
}

int main(){
    for(int i=0; i<N; i++){ // Initialise toute les cases à '.'
        for (int j=0; j<M;j++){
            grille[j][i] = ' ';
        }
    }
    bool dessin_en_cours = true;
    while(dessin_en_cours){
        char choix[7]; 
        
        printf("Que voulez vous faire ?\n");
        printf("- 'draw' pour dessiner\n");
        printf("- 'quit', pour quitter\n");
        scanf("%s", choix);
        if(strcmp(choix, "draw") == 0){
            printf("Que voulez vous dessiner ?\n");
            printf("'char' pour un caractère\n");
            printf("'line' pour une ligne\n");
            printf("'rect' pour un rectangle\n");
            printf("'Bres' pour une ligne avec l'algo de Bresenham\n");
            scanf("%s", choix);
            if(strcmp(choix, "char")==0){
                int x1,y1;
                char c;
                printf("Veuillez entrez les coordonnées x1, y1 ainsi qu'un caractère c: ");
                scanf("%d %d %c", &x1, &y1, &c);
                draw_char(x1,y1,c);
                print_grille();
            }
            if(strcmp(choix, "line")==0){
                int x1,x2,y1,y2;
                printf("Veuillez entrez les coordonnées x1, y1, x2 et y2 : ");
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                draw_line(x1,y1,x2,y2);
                print_grille();
            }
            if(strcmp(choix, "rect")==0){
                int x1,x2,y1,y2;
                printf("Veuillez entrez les coordonnées x1, y1 (coin supérieur gauche), x2 et y2 (coin inférieur droit) : ");
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                draw_rectangle(x1,y1,x2,y2);
                print_grille();
            }
            if(strcmp(choix, "Bres")==0){
                int x1,x2,y1,y2;
                printf("Veuillez entrez les coordonnées x1, y1, x2 et y2 : ");
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                draw_Bresenham(x1,y1,x2,y2);
                print_grille();
            }



        }
        if(strcmp(choix, "quit") == 0){
            printf("Au revoir !\n");
            dessin_en_cours=false;
        }
    }
    
    return 0;
}