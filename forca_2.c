#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// #include "forca.h" header file

void abertura();
void chuta();
void desenhaforca();
void escolhepalavra();  // declaracao das funcoes, mais usual declarar no .h
int acertou();
int enforcou();
int jachutou(char letra);

char palavrasecreta[20];  //Declarada variaveis globais
char chutes[26];
int chutesdados = 0;

void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");     //cabecario do jogo
    printf("/****************/\n\n");
}

void chuta() {       //faz aleitura das letras que seram chutadas
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra) {          //Faz a aleitura das letras que ja foram chutadas para nao ocorrer conflitos
    int achou = 0;
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca() {       

    printf("Voce ja deu %d chutes\n", chutesdados);

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

void escolhepalavra() {         //Escolhe a palavra a ser adivinhada
    FILE* f;

       f = fopen("palavras.txt", "r"); //abre um arquivo externo e devolve um ponteiro de arquivo, r e para declarar read no arquivo
        
       int qntdpalavras;
       fscanf(f, "%d", & qntdpalavras);  // fscanf faz a leitura do arquivo externo
       
       srand(time(0));
        int randomico = rand() % qntdpalavras;
            for(int i = 0;i <= randomico; i++){
                fscanf( f, "%s", palavrasecreta);
            }

        fclose(f); // fecha o arquivo
    }

int acertou (){
    for(int i = 0; i < strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }
    return 1;
}

int enforcou(){
    
int erros = 0;

    for(int i = 0; i < chutesdados; i ++){
        int existe = 0;

        for(int j = 0; j < strlen(palavrasecreta); j++){
            if(chutes[i] == chutes[j]){
                existe = 1;
                break;
            }
        }    
        
        if(!existe) erros++;

    }
    return erros >= 5 ;
}

int main() {        


    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());

    return 0;
}