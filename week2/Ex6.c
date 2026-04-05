#include<stdio.h>
void f(int n){
    if(n==0) return;
    f(n-1);
    printf("%d ", n);
}
int main()
{

    f(4);
    return 0;
}