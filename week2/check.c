#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p = (int*)calloc(3, sizeof(int));
printf("%d %d %d", p[0], p[1], p[2]);
free(p);
  return 0;
}