// Caracteres
// E/S: Caractere -> Vogal ou Consoante ou Outro
// Ex.: a -> Vogal

#include <stdio.h>

int main(){
    
    char caractere;

    printf("Digite um caractere:\n");
    scanf("%c", &caractere);

    if(caractere == 'a' || caractere == 'A' || caractere == 'e' || caractere == 'E' || caractere == 'i' || caractere == 'I' || caractere == 'o' || caractere == 'O' || caractere == 'u' || caractere == 'U'){
        printf("Vogal!\n");
    }
    if (caractere == 'b' || caractere == 'B' || caractere == 'c' || caractere == 'C' || caractere == 'd' || caractere == 'D' || caractere == 'f' || caractere == 'F' || caractere == 'g' || caractere == 'G' || caractere == 'h' || caractere == 'H' || caractere == 'j' || caractere == 'J' || caractere == 'k' || caractere == 'K' || caractere == 'l' || caractere == 'L' || caractere == 'm' || caractere == 'M' || caractere == 'n' || caractere == 'N' || caractere == 'p' || caractere == 'P' || caractere == 'q' || caractere == 'Q' || caractere == 'r' || caractere == 'R' || caractere == 's' || caractere == 'S' || caractere == 't' || caractere == 'T' || caractere == 'v' || caractere == 'V' || caractere == 'w' || caractere == 'W' || caractere == 'x' || caractere == 'X' || caractere == 'y' || caractere == 'Y' || caractere == 'z' || caractere == 'Z'){
        printf("Consoante!\n");
    }
    if (!((caractere == 'a' || caractere == 'A' || caractere == 'e' || caractere == 'E' || caractere == 'i' || caractere == 'I' || caractere == 'o' || caractere == 'O' || caractere == 'u' || caractere == 'U')||(caractere == 'b' || caractere == 'B' || caractere == 'c' || caractere == 'C' || caractere == 'd' || caractere == 'D' || caractere == 'f' || caractere == 'F' || caractere == 'g' || caractere == 'G' || caractere == 'h' || caractere == 'H' || caractere == 'j' || caractere == 'J' || caractere == 'k' || caractere == 'K' || caractere == 'l' || caractere == 'L' || caractere == 'm' || caractere == 'M' || caractere == 'n' || caractere == 'N' || caractere == 'p' || caractere == 'P' || caractere == 'q' || caractere == 'Q' || caractere == 'r' || caractere == 'R' || caractere == 's' || caractere == 'S' || caractere == 't' || caractere == 'T' || caractere == 'v' || caractere == 'V' || caractere == 'w' || caractere == 'W' || caractere == 'x' || caractere == 'X' || caractere == 'y' || caractere == 'Y' || caractere == 'z' || caractere == 'Z'))){
        printf("Nem vogal nem consoante!\n");
    }

    return 0;
}
