#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "forca.h"    //biblioteca de delcaracao das funcoes

char palavrasecreta[20];
char chutes[26];        //declaracao das variaveis globais
int chutesdados = 0;

int enforcou() {        // funcao para verificar se existe ou nao aquela letra, e sujeito a 5 erros

    int erros = 0;

    for(int i = 0; i < chutesdados; i++) {

        int existe = 0;

        for(int j = 0; j < strlen(palavrasecreta); j++) {       //strlen e ultilizado para uma vetor como uma string ate achar o \0
            if(chutes[i] == palavrasecreta[j]) {
                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
    }

    return erros >= 5;
}

int ganhou() {      //funcao para verificar se o usuario ganhou
    for(int i = 0; i < strlen(palavrasecreta); i++) {   //faz a leitura da palavra secreta
        if(!jachutou(palavrasecreta[i])) {      //verifica se uma letra ja foi chutada
            return 0;
        }
    }

    return 1;
}


void abertura() {               // funcao de abrtura estetica
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() {      //funcao para permitir realizar o chute da Letra
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;        // guarda todos os chutes como um array de x numeros
    chutesdados++;                      //soma um ao valor dos chutes dados para subir uma posicao no array
}

int jachutou(char letra) {      // funcao para verificar quais letras ja foram chutadas
    int achou = 0;
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;       //retorna para a funcao achou caso uma das letras corresponda a um devido local
}

void desenhaforca() {           //faz o desenho da forca com a quantidade certa de letras correspondentes a palavra

    printf("Você já deu %d chutes\n", chutesdados);

    for(int i = 0; i < strlen(palavrasecreta); i++) {       //imprime a quantidade de letras da palavra

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);       //impime a letra que foi chutada corretamente
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

void escolhepalavra() {
    FILE* f;        //aponta para um arquivo externo

    f = fopen("palavras.txt", "r");     //abre o arquivo externo
    if(f == 0) {        
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);        //caso nao exista palavras no arquivo externo ele fecha
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);        //le a quantidade de palavras do que exite no arquiv eterno(uma por linha)

    srand(time(0));                     //seleciona um alinha aletoriamente no arquivo externo
    int randomico = rand() % qtddepalavras; //faz a divisao do numero randomico e pega o retso para escolher sua palavra

    for(int i = 0; i <= randomico; i++) {         
        fscanf(f, "%s", palavrasecreta);  //faz a a leitura da apalvra secreta
    }

    fclose(f);      //fecha o arquivo externo
}


void adicionapalavra() {        //funcao para adicionar uma nova palavra
    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer);        //%c faz a aleitura de uma letra

    if(quer == 'S') {
        char novapalavra[20];

        printf("Digite a nova palavra, em letras maiúsculas: ");
        scanf("%s", novapalavra);       //faz a leitura de um vetor por completo UMA PALAVRA

        FILE* f;        //aponta para um arquivo externo

        f = fopen("palavras.txt", "r+");        //abre o arquivo externo, permitge leitura e ereescrita dentro do arquivo externo("r+")
        if(f == 0) {
            printf("Banco de dados de palavras não disponível\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);      //faz a leitura do aquivo externo, adicona +1 a primeira linha
        qtd++;
        fseek(f, 0, SEEK_SET);      //posiciona uma cabeca de leitura no inio do arquivo
        fprintf(f, "%d", qtd);      //imprime a palavra em cima do arquivo

        fseek(f, 0, SEEK_END);      //posiciona para o fim do arquivo
        fprintf(f, "\n%s", novapalavra);        //faz a leitura da nova palavra

        fclose(f);      //fecha o arquivo externo

    }

}

int main() {

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

    } while (!ganhou() && !enforcou());

    if(acertou()) {
        printf("Parabens, voce ganhou!");
    } else {
        printf("Que pena, Voce perdeu!");
    }

    adicionapalavra();
}