#include <stdio.h>
#include <string.h> // para o uso do strlen

    char palavrasecreta[20];
    char chutes[26];
    int chutesdados = 0;

void abertura() {

    printf("****************************\n");
    printf("*       Jogo de Forca      *\n");
    printf("****************************\n\n");

}

void chuta(){
    char chute;          //captura um novo chute
    printf("Qual letra? ");
    scanf(" %c", &chute); //%c e usado para fazer a laietura de char, e tem que vir com um espaco antes do %c para nao fazer a leitura errada

    chutes[chutesdados] = chute;
    chutesdados++;
}

void desenhaforca(){
    
    for(int i = 0; i < strlen(palavrasecreta); i ++){  //imprime caracteres da palavra secreta
    int achou = jachutou(palavrasecreta[i]);
    if(achou) {
                printf("%c ", palavrasecreta[i]);       //escreve a letra correta em seu respectivo local
        }   else {
                printf(" _ ");          //continua o jogo da forca
        }
   }
    printf("\n");

}

void escolhepalavra(){
    sprintf(palavrasecreta, "MELANCIA"); //sprintf imprime um array de char s vem de string.
}

int jachutou(char letra){

    int achou = 0;      //uso de operacoes booleanas

        for(int j  = 0; j < chutesdados; j++){    
            if(chutes[j] == letra){
                achou = 1;
                break;
            }
        }
        return achou;
}


int acertou(){
    for(int i = 0; i < strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}

int enforcou(){
    return chutesdados >= 5;
}

int main(){

    int ganhou = 0, perdeu = 0; 
   

abertura();  
escolhepalavra();

 do {
   
    desenhaforca();
    chuta(); 
    
    ganhou = acertou();
    perdeu = enforcou();

 } while (!ganhou && !perdeu); //se fosse usado !acertou && !enforcou tambem funcionaria

 if(ganhou) {
     printf("Parabéns, você ganhou!\n");
 } else {
     printf("Puxa, você foi enforcado!\n");
     printf("A palavra era **%s**\n", palavrasecreta);
 }

 return 0;
}