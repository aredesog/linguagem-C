#include <stdio.h>
#include <time.h>


int main(){
    
    printf("----------------------------------------\n");
    printf("Bem-vindo ao jogo de adivinhação!\n");
    printf("-----------------------------------------\n");

    int segundo = time(0);
    srand(segundo); //criacao de numeros aleatorios a partir do horario do computador0
    int numerogrande = rand(); 
   
    int numeros = numerogrande % 100; // O % e ultilizado para caucular o resto da operacao grande, sempre retornando umk numeor entre 0 e 99 
    int tentativa = 1, ganhou = 0;
    int chute;              
    double pontosperdidos, pontos = 1000;             // double funciona como um float, fazendo a declaracao de numeros decimais
     

    while (ganhou == 0){            //while(1) tambem funcionaria, ficaria um lopping infinito !
        printf("\nTentaiva %d : ", tentativa);
        printf(" Qual seu chute ? ");
        scanf("%d", &chute);

        if(chute < 0){
        printf("\nNao e possivel avaliar numeros negativos!");
        continue;
        }

        int acertou = (chute == numeros);
        int maior = chute > numeros;

        if(acertou){
            printf("\nParabens! Voce acertou!");
            printf("\nO numero de tenativas para acertar o numero foi de : %d ", tentativa);
            break; // colocar o ganhou = 1 aqui resultaria na mesa funcao do break ja que pararia o lopping do while!
        }

        else if(maior){
            printf("\nO chute foi maior");
        } else {
            printf("\nO chute foi menor");
    }
    tentativa = tentativa + 1; //tentaivas++
   
    pontosperdidos = (chute - numeros) /2.0; // A leitura e feita da direita para a esquerda, o 2.0 antecipa uma conta de ponto flutuante
        if (pontosperdidos < 0){
        pontosperdidos = pontosperdidos * -1; //Mais facil ultilizar o abs com o <stdlib.h>

    }
    pontos = pontos - pontosperdidos;
}


printf("\nSua pontuacao foi : %.2f", pontos);
printf("\nFim de Jogo!");

    return 0;
}