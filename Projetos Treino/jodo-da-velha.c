#include <stdio.h>

int main(){

    int opcaoMenu, vidaJogadorUm = 1, vidaJogadorDois =1, jogadaLinha, jogadaColuna, anula = 0; 
    char umUm = '-', umDois = '-', umTres = '-', doisUm = '-', doisDois = '-', doisTres = '-', tresUm = '-', tresDois = '-', tresTres = '-';


    printf("\nSEJA BEM VINDO(A) AO JOGO DA VELHA\n\n");
    printf("Digite 0 para ler as instrucoes de jogo ou 1 para jogar\n"); // o jogo inicia em um menu, onde 0 exibe as instruções de jogo e 1 inicia o jogo
    scanf("%d", &opcaoMenu);

    switch (opcaoMenu)
    {
    case 0: // imprimindo instruções do jogo
        printf("\n1) Primeiramente para jogar o jogo da velha e preciso de um jogador 1 e um jogador 2\n\n");
        printf("2) Serao ao todo nove jogadas, sendo que em cada uma delas jogara apenas o jogador indicado\n\n");
        printf("3) Em cada jogada o jogador da vez devera indicar respectivamente a linha e a coluna desejada\n\n");
        printf("4) O jogador 1 e representado pelo X e o jogador 2 e representado pelo O\n\n");
        printf("5) O jogador 1 sempre inicia a partida\n\n");
        printf("6) Cuidado com as jogadas invalidas, pois elas anulam a partida e fecham o programa!\n\n");
        printf("PARA JOGAR INICIE O PROGRAMA NOVAMENTE E DIGITE 1\n\n");
        break;
    case 1: // iniciando o jogo
        // jogada 1
        if(anula == 0 && vidaJogadorUm != 0 && vidaJogadorDois != 0){ // se ambos estiverem vivos a jogada acontece
            printf("\nVEZ DO JOGADOR 1\n\n"); // jogador 1 joga
            
            printf("     "); // imprimindo o quadro
            printf("  1  ");
            printf("  2  ");
            printf("  3  \n");
            printf("  1  ");
            printf("  %c  ", umUm);
            printf("  %c  ", umDois);
            printf("  %c  \n", umTres);
            printf("  2  ");
            printf("  %c  ", doisUm);
            printf("  %c  ", doisDois);
            printf("  %c  \n", doisTres);
            printf("  3  ");
            printf("  %c  ", tresUm);
            printf("  %c  ", tresDois);
            printf("  %c  \n", tresTres);
            
            printf("\nDigite a linha da sua jogada:\n"); // cordenada da jogada
            scanf("%d", &jogadaLinha);
            printf("\nDigite respectivamente a coluna da sua jogada:\n");
            scanf("%d", &jogadaColuna);

            switch (jogadaLinha) // se a cordenada indicada ainda possui '-' a jogada é possível, senão a partida é anulada
            {
                case 1: 
                    if(jogadaColuna == 1 && umUm == '-'){
                        umUm = 'X';
                    }
                    else if(jogadaColuna == 2 && umDois == '-'){
                        umDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && umTres == '-'){
                        umTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 2: 
                    if(jogadaColuna == 1 && doisUm == '-'){
                        doisUm = 'X';
                    }
                    else if(jogadaColuna == 2 && doisDois == '-'){
                        doisDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && doisTres == '-'){
                        doisTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 3: 
                    if(jogadaColuna == 1 && tresUm == '-'){
                        tresUm = 'X';
                    }
                    else if(jogadaColuna == 2 && tresDois == '-'){
                        tresDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && tresTres == '-'){
                        tresTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                default: 
                    anula = 1;
                    break;
            }

            if(umUm == umDois && umDois == umTres && umUm != '-' && umDois != '-' && umTres != '-'){ // se alguma das condições forem atendidas, então jogador da partida ganhou
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(doisUm == doisDois && doisDois == doisTres && doisUm != '-' && doisDois != '-' && doisTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(tresUm == tresDois && tresDois == tresTres && tresUm != '-' && tresDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisUm && doisUm == tresUm && umUm != '-' && doisUm != '-' && tresUm != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umDois == doisDois && doisDois == tresDois && umDois != '-' && doisDois != '-' && tresDois != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umTres == doisTres && doisTres == tresTres && umTres != '-' && doisTres != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisDois && doisDois == tresTres && umUm != '-' && doisDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois -  1;
            }
            else if(tresUm == doisDois && doisDois == umTres && tresUm != '-' && doisDois != '-' && umTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            } // se nenhuma das condções forem atendidas o jogador da partida ainda não venceu
        }

        // jogada 2
        if(anula == 0 && vidaJogadorUm != 0 && vidaJogadorDois != 0){ // se ambos estiverem vivos a jogada acontece
            printf("\nVEZ DO JOGADOR 2\n\n"); // jogador 2 joga
            
            printf("     "); // imprimindo o quadro
            printf("  1  ");
            printf("  2  ");
            printf("  3  \n");
            printf("  1  ");
            printf("  %c  ", umUm);
            printf("  %c  ", umDois);
            printf("  %c  \n", umTres);
            printf("  2  ");
            printf("  %c  ", doisUm);
            printf("  %c  ", doisDois);
            printf("  %c  \n", doisTres);
            printf("  3  ");
            printf("  %c  ", tresUm);
            printf("  %c  ", tresDois);
            printf("  %c  \n", tresTres);
            
            printf("\nDigite a linha da sua jogada:\n"); // cordenada da jogada
            scanf("%d", &jogadaLinha);
            printf("\nDigite respectivamente a coluna da sua jogada:\n");
            scanf("%d", &jogadaColuna);

            switch (jogadaLinha) // se a cordenada indicada ainda possui '-' a jogada é possível, senão a partida é anulada
            {
                case 1: 
                    if(jogadaColuna == 1 && umUm == '-'){
                        umUm = 'O';
                    }
                    else if(jogadaColuna == 2 && umDois == '-'){
                        umDois = 'O';
                    } 
                    else if(jogadaColuna == 3 && umTres == '-'){
                        umTres = 'O';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 2: 
                    if(jogadaColuna == 1 && doisUm == '-'){
                        doisUm = 'O';
                    }
                    else if(jogadaColuna == 2 && doisDois == '-'){
                        doisDois = 'O';
                    } 
                    else if(jogadaColuna == 3 && doisTres == '-'){
                        doisTres = 'O';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 3: 
                    if(jogadaColuna == 1 && tresUm == '-'){
                        tresUm = 'O';
                    }
                    else if(jogadaColuna == 2 && tresDois == '-'){
                        tresDois = 'O';
                    } 
                    else if(jogadaColuna == 3 && tresTres == '-'){
                        tresTres = 'O';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                default: 
                    anula = 1;
                    break;
            }

            if(umUm == umDois && umDois == umTres && umUm != '-' && umDois != '-' && umTres != '-'){ // se alguma das condições forem atendidas, então jogador da partida ganhou
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(doisUm == doisDois && doisDois == doisTres && doisUm != '-' && doisDois != '-' && doisTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(tresUm == tresDois && tresDois == tresTres && tresUm != '-' && tresDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisUm && doisUm == tresUm && umUm != '-' && doisUm != '-' && tresUm != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umDois == doisDois && doisDois == tresDois && umDois != '-' && doisDois != '-' && tresDois != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umTres == doisTres && doisTres == tresTres && umTres != '-' && doisTres != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisDois && doisDois == tresTres && umUm != '-' && doisDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois -  1;
            }
            else if(tresUm == doisDois && doisDois == umTres && tresUm != '-' && doisDois != '-' && umTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            } // se nenhuma das condções forem atendidas o jogador da partida ainda não venceu
        }

        // jogada 3
        if(anula == 0 && vidaJogadorUm != 0 && vidaJogadorDois != 0){ // se ambos estiverem vivos a jogada acontece
            printf("\nVEZ DO JOGADOR 1\n\n"); // jogador 1 joga
            
            printf("     "); // imprimindo o quadro
            printf("  1  ");
            printf("  2  ");
            printf("  3  \n");
            printf("  1  ");
            printf("  %c  ", umUm);
            printf("  %c  ", umDois);
            printf("  %c  \n", umTres);
            printf("  2  ");
            printf("  %c  ", doisUm);
            printf("  %c  ", doisDois);
            printf("  %c  \n", doisTres);
            printf("  3  ");
            printf("  %c  ", tresUm);
            printf("  %c  ", tresDois);
            printf("  %c  \n", tresTres);
            
            printf("\nDigite a linha da sua jogada:\n"); // cordenada da jogada
            scanf("%d", &jogadaLinha);
            printf("\nDigite respectivamente a coluna da sua jogada:\n");
            scanf("%d", &jogadaColuna);

            switch (jogadaLinha) // se a cordenada indicada ainda possui '-' a jogada é possível, senão a partida é anulada
            {
                case 1: 
                    if(jogadaColuna == 1 && umUm == '-'){
                        umUm = 'X';
                    }
                    else if(jogadaColuna == 2 && umDois == '-'){
                        umDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && umTres == '-'){
                        umTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 2: 
                    if(jogadaColuna == 1 && doisUm == '-'){
                        doisUm = 'X';
                    }
                    else if(jogadaColuna == 2 && doisDois == '-'){
                        doisDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && doisTres == '-'){
                        doisTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 3: 
                    if(jogadaColuna == 1 && tresUm == '-'){
                        tresUm = 'X';
                    }
                    else if(jogadaColuna == 2 && tresDois == '-'){
                        tresDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && tresTres == '-'){
                        tresTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                default: 
                    anula = 1;
                    break;
            }

            if(umUm == umDois && umDois == umTres && umUm != '-' && umDois != '-' && umTres != '-'){ // se alguma das condições forem atendidas, então jogador da partida ganhou
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(doisUm == doisDois && doisDois == doisTres && doisUm != '-' && doisDois != '-' && doisTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(tresUm == tresDois && tresDois == tresTres && tresUm != '-' && tresDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisUm && doisUm == tresUm && umUm != '-' && doisUm != '-' && tresUm != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umDois == doisDois && doisDois == tresDois && umDois != '-' && doisDois != '-' && tresDois != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umTres == doisTres && doisTres == tresTres && umTres != '-' && doisTres != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisDois && doisDois == tresTres && umUm != '-' && doisDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois -  1;
            }
            else if(tresUm == doisDois && doisDois == umTres && tresUm != '-' && doisDois != '-' && umTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            } // se nenhuma das condções forem atendidas o jogador da partida ainda não venceu
        }

        // jogada 4
        if(anula == 0 && vidaJogadorUm != 0 && vidaJogadorDois != 0){ // se ambos estiverem vivos a jogada acontece
            printf("\nVEZ DO JOGADOR 2\n\n"); // jogador 2 joga
            
            printf("     "); // imprimindo o quadro
            printf("  1  ");
            printf("  2  ");
            printf("  3  \n");
            printf("  1  ");
            printf("  %c  ", umUm);
            printf("  %c  ", umDois);
            printf("  %c  \n", umTres);
            printf("  2  ");
            printf("  %c  ", doisUm);
            printf("  %c  ", doisDois);
            printf("  %c  \n", doisTres);
            printf("  3  ");
            printf("  %c  ", tresUm);
            printf("  %c  ", tresDois);
            printf("  %c  \n", tresTres);
            
            printf("\nDigite a linha da sua jogada:\n"); // cordenada da jogada
            scanf("%d", &jogadaLinha);
            printf("\nDigite respectivamente a coluna da sua jogada:\n");
            scanf("%d", &jogadaColuna);

            switch (jogadaLinha) // se a cordenada indicada ainda possui '-' a jogada é possível, senão a partida é anulada
            {
                case 1: 
                    if(jogadaColuna == 1 && umUm == '-'){
                        umUm = 'O';
                    }
                    else if(jogadaColuna == 2 && umDois == '-'){
                        umDois = 'O';
                    } 
                    else if(jogadaColuna == 3 && umTres == '-'){
                        umTres = 'O';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 2: 
                    if(jogadaColuna == 1 && doisUm == '-'){
                        doisUm = 'O';
                    }
                    else if(jogadaColuna == 2 && doisDois == '-'){
                        doisDois = 'O';
                    } 
                    else if(jogadaColuna == 3 && doisTres == '-'){
                        doisTres = 'O';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 3: 
                    if(jogadaColuna == 1 && tresUm == '-'){
                        tresUm = 'O';
                    }
                    else if(jogadaColuna == 2 && tresDois == '-'){
                        tresDois = 'O';
                    } 
                    else if(jogadaColuna == 3 && tresTres == '-'){
                        tresTres = 'O';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                default: 
                    anula = 1;
                    break;
            }

            if(umUm == umDois && umDois == umTres && umUm != '-' && umDois != '-' && umTres != '-'){ // se alguma das condições forem atendidas, então jogador da partida ganhou
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(doisUm == doisDois && doisDois == doisTres && doisUm != '-' && doisDois != '-' && doisTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(tresUm == tresDois && tresDois == tresTres && tresUm != '-' && tresDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisUm && doisUm == tresUm && umUm != '-' && doisUm != '-' && tresUm != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umDois == doisDois && doisDois == tresDois && umDois != '-' && doisDois != '-' && tresDois != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umTres == doisTres && doisTres == tresTres && umTres != '-' && doisTres != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisDois && doisDois == tresTres && umUm != '-' && doisDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois -  1;
            }
            else if(tresUm == doisDois && doisDois == umTres && tresUm != '-' && doisDois != '-' && umTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            } // se nenhuma das condções forem atendidas o jogador da partida ainda não venceu
        
        }

        // jogada 5
        if(anula == 0 && vidaJogadorUm != 0 && vidaJogadorDois != 0){ // se ambos estiverem vivos a jogada acontece
            printf("\nVEZ DO JOGADOR 1\n\n"); // jogador 1 joga
            
            printf("     "); // imprimindo o quadro
            printf("  1  ");
            printf("  2  ");
            printf("  3  \n");
            printf("  1  ");
            printf("  %c  ", umUm);
            printf("  %c  ", umDois);
            printf("  %c  \n", umTres);
            printf("  2  ");
            printf("  %c  ", doisUm);
            printf("  %c  ", doisDois);
            printf("  %c  \n", doisTres);
            printf("  3  ");
            printf("  %c  ", tresUm);
            printf("  %c  ", tresDois);
            printf("  %c  \n", tresTres);
            
            printf("\nDigite a linha da sua jogada:\n"); // cordenada da jogada
            scanf("%d", &jogadaLinha);
            printf("\nDigite respectivamente a coluna da sua jogada:\n");
            scanf("%d", &jogadaColuna);

            switch (jogadaLinha) // se a cordenada indicada ainda possui '-' a jogada é possível, senão a partida é anulada
            {
                case 1: 
                    if(jogadaColuna == 1 && umUm == '-'){
                        umUm = 'X';
                    }
                    else if(jogadaColuna == 2 && umDois == '-'){
                        umDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && umTres == '-'){
                        umTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 2: 
                    if(jogadaColuna == 1 && doisUm == '-'){
                        doisUm = 'X';
                    }
                    else if(jogadaColuna == 2 && doisDois == '-'){
                        doisDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && doisTres == '-'){
                        doisTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 3: 
                    if(jogadaColuna == 1 && tresUm == '-'){
                        tresUm = 'X';
                    }
                    else if(jogadaColuna == 2 && tresDois == '-'){
                        tresDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && tresTres == '-'){
                        tresTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                default: 
                    anula = 1;
                    break;
            }

            if(umUm == umDois && umDois == umTres && umUm != '-' && umDois != '-' && umTres != '-'){ // se alguma das condições forem atendidas, então jogador da partida ganhou
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(doisUm == doisDois && doisDois == doisTres && doisUm != '-' && doisDois != '-' && doisTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(tresUm == tresDois && tresDois == tresTres && tresUm != '-' && tresDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisUm && doisUm == tresUm && umUm != '-' && doisUm != '-' && tresUm != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umDois == doisDois && doisDois == tresDois && umDois != '-' && doisDois != '-' && tresDois != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umTres == doisTres && doisTres == tresTres && umTres != '-' && doisTres != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisDois && doisDois == tresTres && umUm != '-' && doisDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois -  1;
            }
            else if(tresUm == doisDois && doisDois == umTres && tresUm != '-' && doisDois != '-' && umTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            } // se nenhuma das condções forem atendidas o jogador da partida ainda não venceu
        }

        // jogada 6
        if(anula == 0 && vidaJogadorUm != 0 && vidaJogadorDois != 0){ // se ambos estiverem vivos a jogada acontece
            printf("\nVEZ DO JOGADOR 2\n\n"); // jogador 2 joga
            
            printf("     "); // imprimindo o quadro
            printf("  1  ");
            printf("  2  ");
            printf("  3  \n");
            printf("  1  ");
            printf("  %c  ", umUm);
            printf("  %c  ", umDois);
            printf("  %c  \n", umTres);
            printf("  2  ");
            printf("  %c  ", doisUm);
            printf("  %c  ", doisDois);
            printf("  %c  \n", doisTres);
            printf("  3  ");
            printf("  %c  ", tresUm);
            printf("  %c  ", tresDois);
            printf("  %c  \n", tresTres);
            
            printf("\nDigite a linha da sua jogada:\n"); // cordenada da jogada
            scanf("%d", &jogadaLinha);
            printf("\nDigite respectivamente a coluna da sua jogada:\n");
            scanf("%d", &jogadaColuna);

            switch (jogadaLinha) // se a cordenada indicada ainda possui '-' a jogada é possível, senão a partida é anulada
            {
                case 1: 
                    if(jogadaColuna == 1 && umUm == '-'){
                        umUm = 'O';
                    }
                    else if(jogadaColuna == 2 && umDois == '-'){
                        umDois = 'O';
                    } 
                    else if(jogadaColuna == 3 && umTres == '-'){
                        umTres = 'O';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 2: 
                    if(jogadaColuna == 1 && doisUm == '-'){
                        doisUm = 'O';
                    }
                    else if(jogadaColuna == 2 && doisDois == '-'){
                        doisDois = 'O';
                    } 
                    else if(jogadaColuna == 3 && doisTres == '-'){
                        doisTres = 'O';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 3: 
                    if(jogadaColuna == 1 && tresUm == '-'){
                        tresUm = 'O';
                    }
                    else if(jogadaColuna == 2 && tresDois == '-'){
                        tresDois = 'O';
                    } 
                    else if(jogadaColuna == 3 && tresTres == '-'){
                        tresTres = 'O';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                default: 
                    anula = 1;
                    break;
            }

            if(umUm == umDois && umDois == umTres && umUm != '-' && umDois != '-' && umTres != '-'){ // se alguma das condições forem atendidas, então jogador da partida ganhou
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(doisUm == doisDois && doisDois == doisTres && doisUm != '-' && doisDois != '-' && doisTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(tresUm == tresDois && tresDois == tresTres && tresUm != '-' && tresDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisUm && doisUm == tresUm && umUm != '-' && doisUm != '-' && tresUm != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umDois == doisDois && doisDois == tresDois && umDois != '-' && doisDois != '-' && tresDois != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umTres == doisTres && doisTres == tresTres && umTres != '-' && doisTres != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisDois && doisDois == tresTres && umUm != '-' && doisDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois -  1;
            }
            else if(tresUm == doisDois && doisDois == umTres && tresUm != '-' && doisDois != '-' && umTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            } // se nenhuma das condções forem atendidas o jogador da partida ainda não venceu
        }

        // jogada 7
        if(anula == 0 && vidaJogadorUm != 0 && vidaJogadorDois != 0){ // se ambos estiverem vivos a jogada acontece
            printf("\nVEZ DO JOGADOR 1\n\n"); // jogador 1 joga
            
            printf("     "); // imprimindo o quadro
            printf("  1  ");
            printf("  2  ");
            printf("  3  \n");
            printf("  1  ");
            printf("  %c  ", umUm);
            printf("  %c  ", umDois);
            printf("  %c  \n", umTres);
            printf("  2  ");
            printf("  %c  ", doisUm);
            printf("  %c  ", doisDois);
            printf("  %c  \n", doisTres);
            printf("  3  ");
            printf("  %c  ", tresUm);
            printf("  %c  ", tresDois);
            printf("  %c  \n", tresTres);
            
            printf("\nDigite a linha da sua jogada:\n"); // cordenada da jogada
            scanf("%d", &jogadaLinha);
            printf("\nDigite respectivamente a coluna da sua jogada:\n");
            scanf("%d", &jogadaColuna);

            switch (jogadaLinha) // se a cordenada indicada ainda possui '-' a jogada é possível, senão a partida é anulada
            {
                case 1: 
                    if(jogadaColuna == 1 && umUm == '-'){
                        umUm = 'X';
                    }
                    else if(jogadaColuna == 2 && umDois == '-'){
                        umDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && umTres == '-'){
                        umTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 2: 
                    if(jogadaColuna == 1 && doisUm == '-'){
                        doisUm = 'X';
                    }
                    else if(jogadaColuna == 2 && doisDois == '-'){
                        doisDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && doisTres == '-'){
                        doisTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 3: 
                    if(jogadaColuna == 1 && tresUm == '-'){
                        tresUm = 'X';
                    }
                    else if(jogadaColuna == 2 && tresDois == '-'){
                        tresDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && tresTres == '-'){
                        tresTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                default: 
                    anula = 1;
                    break;
            }

            if(umUm == umDois && umDois == umTres && umUm != '-' && umDois != '-' && umTres != '-'){ // se alguma das condições forem atendidas, então jogador da partida ganhou
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(doisUm == doisDois && doisDois == doisTres && doisUm != '-' && doisDois != '-' && doisTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(tresUm == tresDois && tresDois == tresTres && tresUm != '-' && tresDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisUm && doisUm == tresUm && umUm != '-' && doisUm != '-' && tresUm != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umDois == doisDois && doisDois == tresDois && umDois != '-' && doisDois != '-' && tresDois != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umTres == doisTres && doisTres == tresTres && umTres != '-' && doisTres != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisDois && doisDois == tresTres && umUm != '-' && doisDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois -  1;
            }
            else if(tresUm == doisDois && doisDois == umTres && tresUm != '-' && doisDois != '-' && umTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            } // se nenhuma das condções forem atendidas o jogador da partida ainda não venceu
        }

        // jogada 8
        if(anula == 0 && vidaJogadorUm != 0 && vidaJogadorDois != 0){ // se ambos estiverem vivos a jogada acontece
            printf("\nVEZ DO JOGADOR 2\n\n"); // jogador 2 joga
            
            printf("     "); // imprimindo o quadro
            printf("  1  ");
            printf("  2  ");
            printf("  3  \n");
            printf("  1  ");
            printf("  %c  ", umUm);
            printf("  %c  ", umDois);
            printf("  %c  \n", umTres);
            printf("  2  ");
            printf("  %c  ", doisUm);
            printf("  %c  ", doisDois);
            printf("  %c  \n", doisTres);
            printf("  3  ");
            printf("  %c  ", tresUm);
            printf("  %c  ", tresDois);
            printf("  %c  \n", tresTres);
            
            printf("\nDigite a linha da sua jogada:\n"); // cordenada da jogada
            scanf("%d", &jogadaLinha);
            printf("\nDigite respectivamente a coluna da sua jogada:\n");
            scanf("%d", &jogadaColuna);

            switch (jogadaLinha) // se a cordenada indicada ainda possui '-' a jogada é possível, senão a partida é anulada
            {
                case 1: 
                    if(jogadaColuna == 1 && umUm == '-'){
                        umUm = 'O';
                    }
                    else if(jogadaColuna == 2 && umDois == '-'){
                        umDois = 'O';
                    } 
                    else if(jogadaColuna == 3 && umTres == '-'){
                        umTres = 'O';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 2: 
                    if(jogadaColuna == 1 && doisUm == '-'){
                        doisUm = 'O';
                    }
                    else if(jogadaColuna == 2 && doisDois == '-'){
                        doisDois = 'O';
                    } 
                    else if(jogadaColuna == 3 && doisTres == '-'){
                        doisTres = 'O';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 3: 
                    if(jogadaColuna == 1 && tresUm == '-'){
                        tresUm = 'O';
                    }
                    else if(jogadaColuna == 2 && tresDois == '-'){
                        tresDois = 'O';
                    } 
                    else if(jogadaColuna == 3 && tresTres == '-'){
                        tresTres = 'O';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                default: 
                    anula = 1;
                    break;
            }

            if(umUm == umDois && umDois == umTres && umUm != '-' && umDois != '-' && umTres != '-'){ // se alguma das condições forem atendidas, então jogador da partida ganhou
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(doisUm == doisDois && doisDois == doisTres && doisUm != '-' && doisDois != '-' && doisTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(tresUm == tresDois && tresDois == tresTres && tresUm != '-' && tresDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisUm && doisUm == tresUm && umUm != '-' && doisUm != '-' && tresUm != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umDois == doisDois && doisDois == tresDois && umDois != '-' && doisDois != '-' && tresDois != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umTres == doisTres && doisTres == tresTres && umTres != '-' && doisTres != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisDois && doisDois == tresTres && umUm != '-' && doisDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois -  1;
            }
            else if(tresUm == doisDois && doisDois == umTres && tresUm != '-' && doisDois != '-' && umTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            } // se nenhuma das condções forem atendidas o jogador da partida ainda não venceu
        }

        // jogada 9
        if(anula == 0 && vidaJogadorUm != 0 && vidaJogadorDois != 0){ // se ambos estiverem vivos a jogada acontece
            printf("\nVEZ DO JOGADOR 1\n\n"); // jogador 1 joga
            
            printf("     "); // imprimindo o quadro
            printf("  1  ");
            printf("  2  ");
            printf("  3  \n");
            printf("  1  ");
            printf("  %c  ", umUm);
            printf("  %c  ", umDois);
            printf("  %c  \n", umTres);
            printf("  2  ");
            printf("  %c  ", doisUm);
            printf("  %c  ", doisDois);
            printf("  %c  \n", doisTres);
            printf("  3  ");
            printf("  %c  ", tresUm);
            printf("  %c  ", tresDois);
            printf("  %c  \n", tresTres);
            
            printf("\nDigite a linha da sua jogada:\n"); // cordenada da jogada
            scanf("%d", &jogadaLinha);
            printf("\nDigite respectivamente a coluna da sua jogada:\n");
            scanf("%d", &jogadaColuna);

            switch (jogadaLinha) // se a cordenada indicada ainda possui '-' a jogada é possível, senão a partida é anulada
            {
                case 1: 
                    if(jogadaColuna == 1 && umUm == '-'){
                        umUm = 'X';
                    }
                    else if(jogadaColuna == 2 && umDois == '-'){
                        umDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && umTres == '-'){
                        umTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 2: 
                    if(jogadaColuna == 1 && doisUm == '-'){
                        doisUm = 'X';
                    }
                    else if(jogadaColuna == 2 && doisDois == '-'){
                        doisDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && doisTres == '-'){
                        doisTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                case 3: 
                    if(jogadaColuna == 1 && tresUm == '-'){
                        tresUm = 'X';
                    }
                    else if(jogadaColuna == 2 && tresDois == '-'){
                        tresDois = 'X';
                    } 
                    else if(jogadaColuna == 3 && tresTres == '-'){
                        tresTres = 'X';
                    } 
                    else {
                        anula = 1;
                    }
                break;
                default: 
                    anula = 1;
                    break;
            }

            if(umUm == umDois && umDois == umTres && umUm != '-' && umDois != '-' && umTres != '-'){ // se alguma das condições forem atendidas, então jogador da partida ganhou
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(doisUm == doisDois && doisDois == doisTres && doisUm != '-' && doisDois != '-' && doisTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(tresUm == tresDois && tresDois == tresTres && tresUm != '-' && tresDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisUm && doisUm == tresUm && umUm != '-' && doisUm != '-' && tresUm != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umDois == doisDois && doisDois == tresDois && umDois != '-' && doisDois != '-' && tresDois != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umTres == doisTres && doisTres == tresTres && umTres != '-' && doisTres != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            }
            else if(umUm == doisDois && doisDois == tresTres && umUm != '-' && doisDois != '-' && tresTres != '-'){
                vidaJogadorDois = vidaJogadorDois -  1;
            }
            else if(tresUm == doisDois && doisDois == umTres && tresUm != '-' && doisDois != '-' && umTres != '-'){
                vidaJogadorDois = vidaJogadorDois - 1;
            } // se nenhuma das condções forem atendidas o jogador da partida ainda não venceu
        }
    

        // finalização da partida
        if (anula == 1){
            printf("\nJOGADA INVALIDA, PARTIDA ANULADA!\n\n"); 
        }
        else if(vidaJogadorUm == 0){
            printf("\nJOGADOR 2 VENCEU!\n\n"); 
            
            printf("     "); 
            printf("  1  ");
            printf("  2  ");
            printf("  3  \n");
            printf("  1  ");
            printf("  %c  ", umUm);
            printf("  %c  ", umDois);
            printf("  %c  \n", umTres);
            printf("  2  ");
            printf("  %c  ", doisUm);
            printf("  %c  ", doisDois);
            printf("  %c  \n", doisTres);
            printf("  3  ");
            printf("  %c  ", tresUm);
            printf("  %c  ", tresDois);
            printf("  %c  \n\n", tresTres);
        }
        else if(vidaJogadorDois == 0){
            printf("\nJOGADOR 1 VENCEU!\n\n"); 
            
            printf("     "); 
            printf("  1  ");
            printf("  2  ");
            printf("  3  \n");
            printf("  1  ");
            printf("  %c  ", umUm);
            printf("  %c  ", umDois);
            printf("  %c  \n", umTres);
            printf("  2  ");
            printf("  %c  ", doisUm);
            printf("  %c  ", doisDois);
            printf("  %c  \n", doisTres);
            printf("  3  ");
            printf("  %c  ", tresUm);
            printf("  %c  ", tresDois);
            printf("  %c  \n\n", tresTres);
        }
        else if(vidaJogadorUm == 1 && vidaJogadorDois == 1){
            printf("\nDEU VELHA!\n\n"); 
            
            printf("     "); 
            printf("  1  ");
            printf("  2  ");
            printf("  3  \n");
            printf("  1  ");
            printf("  %c  ", umUm);
            printf("  %c  ", umDois);
            printf("  %c  \n", umTres);
            printf("  2  ");
            printf("  %c  ", doisUm);
            printf("  %c  ", doisDois);
            printf("  %c  \n", doisTres);
            printf("  3  ");
            printf("  %c  ", tresUm);
            printf("  %c  ", tresDois);
            printf("  %c  \n\n", tresTres);
        }
        break;
    default: // caso digite algo diferente de 0 e 1 no inicio do programa
        printf("Escolha invalida\n"); 
        break;
    }

    system("pause");

}