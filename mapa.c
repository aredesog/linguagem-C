#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mapa.h"

MAPA* m;
POSICAO* p;

void lemapa(MAPA* m) {
    FILE* f;
    f = fopen("mapa.txt", "r"); //abre o aqui e le 
    if (f == 0) {
        printf("Erro ao abrir o arquivo mapa.txt\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas)); //acessa o enderco de memoria de linhas e colunas e o le

    alocamapa(m);
    
    for (int i = 0; i < 5; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f); //fecha o arquivo
}

void alocamapa(MAPA* m) {
    m->matriz = malloc(sizeof (char*) * m->linhas); //pede um espaco de memoria para alocar(TAMANHO) -> sizeof pega o valor de bytes de uma declaracao e pode ser multiplicada para acrescentar hno tamanho
    for (int i = 0; i < m->linhas; i++) {
        m->matriz[i] = malloc(sizeof (char) * (m->colunas + 1));
    }
}

void copiamapa(MAPA* destino, MAPA* origem){  // para evitar o loop do fantasma andar poara a direita ate o fim do mapa com loop infinito
    destino->linhas == origem->linhas;
    destino->colunas == origem->colunas;
    
    alocamapa(destino);
    for(int int i = 0; i , origem->linhas; i++){
        strcpy(destino->matriz[i], origem->matriz[i]);   //recebe dois arrays de char, e copia de uma para a outra
    }
}

// isola a responsabilidade esse arquivo so tema aver com o mapa
void liberamapa(MAPA* m) {
    for (int i = 0; i < (*m).linhas; i++) {
        free((*m).matriz[i]); //libera valor na memoria anteriormente ocupada pelo mallooc
    }
    free((*m).matriz);
}

void imprimemapa(MAPA* m) {
    for (int i = 0; i < m->linhas; i++) {
        printf("%s\n", m->matriz[i]);
    }
}

int encontramapa(MAPA* m, POSICAO* p, char c){
      for(int i = 0; i < m->linhas; i++) {
            for(int j = 0; j < m->colunas; j++) {
                if (m->matriz[i][j] == c) {
                    p->x = i;
                    p->y = j;
                    return 1;
                }
            }
        }
      return 0;
}

int podeandar(MAPA*m, int x, int y, char personagem){
    return
            ehvalida(m, x, y) &&
            !ehvazia(m, x, y) &&
            !ehpersonagem(m, personagem,x ,y);
}

int ehvalida(MAPA* m, int x, int y){
    if(x >= m->linhas)        // BATA NA PAREDE
            return 0;
    if(y >= m->colunas)       //BATA NA PAREDE
            return 0;
    return 1;
}

int ehpersonagem(MAPA* m, int x, int y, char personagem){

    return m->matriz[x][y] == personagem;
}

int ehparede(MAPA*m, int x, int y){
    return m->matriz[x][y] == PAREDE_VERTICAL ||
            m->matriz[x][y] == PAREDE_HORIZONTAL;
}

void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino){
    
    char personagem = m->matriz[xorigem][yorigem];
    m->matriz[xdestino][ydestino];
    m->matriz[xorigem][yorigem] = VAZIO;
}


int ehvazia(MAPA* m, int x, int y ){
        return m.matriz[x][y] != VAZIO;     //ULTRAPASSE O NUEMRO DA MATRIZ 
            return;
}

