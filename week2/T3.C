#include<stdio.h>
#include<stdlib.h>
int main(){

   // int *p =(int *) malloc(5*sizeof(int));
//p = malloc(10*sizeof(int));
//it causes memoery leak we can use realloc to make it bigger and also free at the end to prevent Dangling
        int *p =(int *) malloc(5*sizeof(int));
        p=realloc(p,10*sizeof(int));
        free(p);
        p=NULL;
        return 0;
}
