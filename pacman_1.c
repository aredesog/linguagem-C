// CODIGO DO GEMINAI
#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

// Variável global para o mapa
MAPA m; 

// Declarações das funções para que main possa "enxergá-las" antes de serem definidas
void liberamapa();
void alocamapa();
void lemapa();
void imprimemapa();
void move(char direcao);
int acabou();

// Definição das funções
void liberamapa() {
    for (int i = 0; i < m.linhas; i++) {
        free(m.matriz[i]);
    }
    free(m.matriz);
}

void alocamapa() {
    m.matriz = malloc(sizeof(char*) * m.linhas);
    for (int i = 0; i < m.linhas; i++) {
        // Aloca colunas + 1 para o caractere nulo '\0' no final da string
        m.matriz[i] = malloc(sizeof(char) * (m.colunas + 1));
    }
}

void lemapa() {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo mapa.txt\n");
        exit(1);
    }

    fscanf(f, "%d %d", &m.linhas, &m.colunas);
    alocamapa();
    
    // CORRIGIDO: Loop usa m.linhas
    for (int i = 0; i < m.linhas; i++) {
        fscanf(f, "%s", m.matriz[i]);
    }
    
    fclose(f);
}

void imprimemapa() {
    // CORRIGIDO: Loop usa m.linhas
    for (int i = 0; i < m.linhas; i++) {
        printf("%s\n", m.matriz[i]);
    }
}

// CORRIGIDO: A função foi movida para fora de imprimemapa()
int acabou() {
    // Lógica temporária: o jogo ainda não acaba sozinho
    return 0; 
}

// CORRIGIDO: A função foi movida para fora de imprimemapa()
void move(char direcao) {
    int x_atual = -1;
    int y_atual = -1;

    // Encontra a posição atual do Pac-Man ('@')
    for (int i = 0; i < m.linhas; i++) {
        for (int j = 0; j < m.colunas; j++) {
            if (m.matriz[i][j] == '@') {
                x_atual = i; // linha
                y_atual = j; // coluna
                break;
            }
        }
        if(x_atual != -1) break; // Otimização: se já achou, para de procurar
    }

    // Se não encontrou o Pac-Man, não faz nada
    if(x_atual == -1) return;

    // Define as novas coordenadas com base na direção
    int x_novo = x_atual;
    int y_novo = y_atual;

    switch (direcao) {
        case 'a': // Esquerda
            y_novo--;
            break;
        case 'w': // Cima
            x_novo--;
            break;
        case 's': // Baixo
            x_novo++;
            break;
        case 'd': // Direita
            y_novo++;
            break;
        default: // Tecla inválida
            return;
    }

    // CORRIGIDO: Verifica se a nova posição é válida (dentro do mapa e não é parede)
    if(x_novo < 0 || x_novo >= m.linhas || y_novo < 0 || y_novo >= m.colunas) {
        return; // Fora do mapa, não move
    }
    if(m.matriz[x_novo][y_novo] == '|' || m.matriz[x_novo][y_novo] == '-') {
        return; // É uma parede, não move
    }

    // Move o Pac-Man para a nova posição
    m.matriz[x_novo][y_novo] = '@';
    // Deixa um ponto no lugar antigo
    m.matriz[x_atual][y_atual] = '.';
}


int main() {
    lemapa();

    char comando;
    do {
        printf("\n");
        imprimemapa();
        
        printf("Comando (w,a,s,d): ");
        scanf(" %c", &comando);

        if(comando == 'q') break; // Condição de saída para não ter loop infinito

        move(comando);

    } while (!acabou());

    liberamapa();
    return 0;
}