#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int x= 10 + rand()%10;
    int y= 10 + rand()%10;
    int z= 10 + rand()%10;
    printf("x: %d, y: %d, z: %d\n", x, y, z);

    return 0;
}
