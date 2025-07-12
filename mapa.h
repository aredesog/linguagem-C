#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'

struct mapa{    //facilita a declarcao de variaveis globais caso elas sejam ultilizadas pra masid e um caso no programa
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA; // cria um apelido para o struct

void alocamapa();
void lemapa();
void liberamapa();
void imprimemapa();

struct posicao{
    int x;
    int y;
};

typedef struct posicao POSICAO;

int encontramapa(MAPA* m, POSICAO* p, char c);
int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA* m, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);
int podeandar(MAPA*m, int x, int y, char pesonagem);
int ehparede(MAPA*m, int x, int y);
int ehpersonagem(MAPA* m, int x, int y, char personagem);



