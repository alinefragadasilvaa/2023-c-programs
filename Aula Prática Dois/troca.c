#include <stdio.h>

int main(){
    int n[20], i, j, k, aux;

    for(i=0;i<20;i++){
        scanf("%d", &n[i]);
    }

    for(j=0;j<10;j++){
        aux = n[j];
        n[j] = n[19-j];
        n[19-j] = aux;
    }

    
    for(k=0;k<20;k++){
        printf("N [%d] = %d\n", k, n[k]);
    }
}