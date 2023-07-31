#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char palavra[100000];
    int i, j, flag=0;

    scanf("%s", palavra);

    i = 0;
    while(palavra[i] != '\0'){
        i++;
    }


    j = 0;
    while(palavra[j] != '\0'){
        if(j + 4 <= i){
            if((palavra[j] == 'z' || palavra[j] == 'Z') && (palavra[j+1] == 'e' || palavra[j+1] == 'E') && (palavra[j+2] == 'l' || palavra[j+2] == 'L')  && (palavra[j+3] == 'd' || palavra[j+3] == 'D')  && (palavra[j+4] == 'a' || palavra[j+4] == 'A')){
                flag=1;
            }
        }
        j++;
    }

    if(flag==1){
        printf("Link Bolado\n");
    } else {
        printf("Link Tranquilo\n");
    }
    return 0;
}