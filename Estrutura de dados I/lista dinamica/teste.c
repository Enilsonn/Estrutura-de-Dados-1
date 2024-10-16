#include <stdlib.h>
int main(){
    int** p;
    p = (int**)malloc(10*sizeof(int*));
    for(int i = 0; i <10; i++)
        p[i] = (int*)malloc(10*sizeof(int));
    return 0;
}