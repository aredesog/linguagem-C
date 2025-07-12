#include <stdio.h>
#include <time.h>


int main(){
    
    printf("----------------------------------------\n");
    printf("Bem-vindo ao jogo de adivinhacao!\n");
    printf("-----------------------------------------\n");

    int segundo = time(0);
    srand(segundo); //criacao de numeros aleatorios a partir do horario do computador0
    int numerogrande = rand(); 
   

    int nivel;
printf("\nQual o nivel de dificuldade voce quer jogar? ");
printf("\n(1)Facil (2)Medio (3)Dificil ");
printf(" Escolha: ");
scanf("%d", &nivel);

int numerotenta;
if (nivel == 1){
    numerotenta = 15;
} else if(nivel == 2){
    numerotenta = 10;
} else if(nivel == 3){
    numerotenta = 5;
}

    int numeros = numerogrande % 100; // O % e ultilizado para caucular o resto da operacao grande, sempre retornando umk numeor entre 0 e 99 
    int tentativa = 1, ganhou = 0, acertou = 0, chute;      
    double pontosperdidos, pontos = 1000;             // double funciona como um float, fazendo a declaracao de numeros decimais
     

   for (int i = 1; i <= numerotenta; i++){            //while(1) tambem funcionaria, ficaria um lopping infinito !
        printf("\nTentaiva %d : ", tentativa);
        printf(" Qual seu chute ? ");
        scanf("%d", &chute);

        if(chute < 0){
        printf("\nNao e possivel avaliar numeros negativos!");
        continue;
        }
        acertou = (chute == numeros);
        int maior = chute > numeros;

        if(acertou){
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

if(acertou) {
    printf("\nVoce ganhou!");
    printf("\nSua pontuacao foi : %.2f", pontos);
    printf("\nFim de Jogo!");
} else {
    printf("\nQue pena, voce perdeu!");
}

    return 0;
}