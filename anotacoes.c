#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
// #include "forca.h" header file -> usado para guardar as declaracoes das funcoes(como ultilizado no jogo da forca)

/*      PONTEIRO 
// (*c) faz apontar para o valor dentro do enderco sem distinguir ele dnetro das funcoes para a main peganndoi apenas o valor absuoluto e continuando a executar o que e necessario
void caucula(int* c){
printf("caucula %d %d\n", (*c), c);
    (*c)++;
printf("caucula %d %d\n", (*c), c);
}
int main(){
 
    int c = 10;

printf("main %d %d\n", c, &c);
caucula(&c);        // o & faz referencia ao endereco de memoria
printf("main %d %d\n", c, &c);
}
*/

/* //CRIACAO DE NUMEROS ALETORIOS
int main(){
int segundos =  time(0);
srand(segundos);
    int n1 = rand();
    int n2 = rand();

printf("%d %d", n1,n2);
}
*/

/*   ABS
int main(){

int a = 3 ,b = -3;
printf("%d %d", a, b);

int c = abs(3),d = abs(-3);
printf(" %d %d", c,d);

}
*/

/*ANOTACOES
char -> guarda apenas um caracter char letra1 = 'M';
sprintf -> faz a leitura de um array em palavras
srand(segundo); ->criacao de numeros aleatorios a partir do horario do computador
strlen -> faz a leitura de uma string ate achar um \0 no arquivo, e o caulculo de quantas letras tem certa palavra
fopen("palavras.txt, , "r"); -> faz a abertura do arquivo externo
fclose(f) -> fecha o arquivo externo
fscanf -> faz a leitura igual o scnaf entretanto do arquivo externo
fseek(f, 0, SEEK_SET); -> faz o apontamento para qual local do arquivo externo vai ser reescrito alguma coisa
feof() ->  verifica se o ponteiro atual do arquivo está apontando para o fim.
fgetc() -> lê apenas o próximo
*/

/*   MATRIZ
  mapa[0][0] = '-';
  mapa[4][9] = '@';
    int* v = malloc(4);   -> pede um espaco de memoria(memory alocation)
    free(v); -> igual abrir e fecha um arquivo, ele armazena e libera a memoria
    sizeof(int) -> delvolve quantos bites um inteiro precisa
    sizeof(int) * 50 -> multiplica em 50 vezes os possiveis bites de um inteiro no caso 4 x 50 = 200bits
    int** v -> delcara um ponteiro de ponteiro no qual aponta de um enderco apra o outro e assim sucessivamente
    struct mapa x; // realiza a declarcao de variaveis globasi adicionadas ao .h e as implementa sem precisar de repeticao
    Com  o struct e permitido a realizacao de x.linhas = 10; x.colunas = 10; que facilita a vizualizacao e aprimora a declracao de variaveiz
*/

/* FUNCOES NOVAS COM MATRIZ
    int** v = malloc(sizeof (int*) * 5); //pede um espaco de memoria(memory alocation) sizeof(int) delvolve quantos bites um inteiro precisa
    for (int i = 0; i < 5; i++) {
        v[i] = malloc(sizeof (int) * 10);
    }

    v[0][0] = 10;
    v[1][2] = 12;
    printf("inteiro alocado %d %d\n", v[0][0], v[1][2]);

    for (int i = 0; i < 5; i++) {
        free(v);
    }
    free(v); // igual abrir e fecha um arquivo, ele armazena e libera a memoria
    ((*m).matriz[i]) = m->matriz[i]
    strcpy -> ele copia duas string ou dois arrays de char, e para quando encontra o \0.
*/