#include <stdio.h>

int main(){
    int p,q;
    scanf("%d %d",&p,&q);

    if((p+q)%2 == 0 && (p-q)%2 == 0 && p>=q)
        printf("%d %d\n",(p+q)/2,(p-q)/2);
    else
        printf("-1\n");
}
