// MEU CODIGO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** mapa[5][10]; //matriz de i x j
int linhas, colunas;

void liberamapa() {
    for (int i = 0; i < linhas; i++) {
        free(mapa[i]); //libera valor na memoria anteriormente ocupada pelo mallooc
    }
    free(mapa);
}

void alocamapa() {
    mapa = malloc(sizeof (char*) * linhas); //pede um espaco de memoria para alocar(TAMANHO) -> sizeof pega o valor de bytes de uma declaracao e pode ser multiplicada para acrescentar hno tamanho
    for (int i = 0; i < linhas; i++) {
        mapa[i] = malloc(sizeof (char) * (colunas + 1));
    }
}

void lemapa() {
    FILE* f;
    f = fopen("mapa.txt", "r"); //abre o aqui e le 
    if (f == NULL) {
        printf("Erro ao abrir o arquivo mapa.txt\n");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas); //acessa o enderco de memoria de linhas e colunas e o le
    printf("linhas %d colunas %d\n", linhas, colunas);

    alocamapa();


    for (int i = 0; i < 5; i++) {
        fscanf(f, "%s", mapa[i]);
    }
    fclose(f); //fecha o arquivo
}

void imprimemapa() {
    for (int i = 0; i < 5; i++) {
        printf("%s\n", mapa[i]);
    }

    void move(char direcao) {
        int x;
        int y;
        
        //acaha a posicao do pacman 
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (mapa[i][j] == '@') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        
        switch(direcao){
            case 'a':
                mapa[x][y-1] = '@';
                break;
            case 'w':
                mapa[x-1][j] = '@';
                break;
            case 's':
                mapa[x+1][j] = '@';
                break;
            case 'd':
                mapa[x][j+1] = '@';
                break;
        }
        
        //2 pacmans no mapa
        
        mapa[x][y] = '.';
        
    }


    int acabou() {
        return 0;
    }

    int main() {

        lemapa();

        do {
            imprimemapa();
            char comando;
            scanf(" %c", &comando);
            move(comando);

        } while (!acabou());


    }

    liberamapa();
}
