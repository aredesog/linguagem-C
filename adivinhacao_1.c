#include <stdio.h>

int main() { // O int main funciona como um bloco de código principal
    //Imprime o cabeçalho do jogo
    printf("----------------------------------------\n");
    printf("Bem-vindo ao jogo de adivinhação!\n");
    printf("-----------------------------------------\n");
    
int NumeroS = 42;
int chute;
int const T = 5;                    // #define NUMERO_DE_TENATIVAS 5 , tambem funciona para declarar uma constante.
                                    // Se fosse declarada um variavel acertou = chute, (int acertou = (chute == NumeroS)) 
                                    //o chute passaria aser acertou e portanto facilitaria na compreesao do codigo
for (int i = 1; i <= T; i++){        /* O for funciona em tres blocos diferentes, o primeiro de inicializacao, 
                                        o segunbdo de condicao, e o terceiro o incremento*/
    printf("\nTentaiva %d de %d ", i, T);
    printf("Qual é o seu chute ? ");
    scanf("%d", &chute);         //scanf tem que vir com o E comercial antes da variavel.
    printf("Seu chute foi %d : " , chute);
    
    if(chute < 0){
    printf("Nao e liberado chutar numeros negativos!");
    i--;
    continue; //Para a execucao do bloco, mas faz o for continuar a rodar, acelera o i++ !
}

int acertou = (chute == NumeroS);
int maior = chute > NumeroS;
int menor = chute < NumeroS;


    if (acertou){                  //== simboliza a comparacao entre duas variaveis.
        printf("Parabens! Voce acertou!\n");
        break; // Para o programa do for! 
    }
       
    else if (maior) { 
            printf("Seu chute foi maior que o nuemro secreto!\n");
            } 
     else if (menor) {
                    printf("Seu chute foi menor que o Nuemro Secreto!\n");
            }  
}
    printf("Fim de Jogo!");
    return 0;
}
