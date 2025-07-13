#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>//biblioteca pra mexer com cores

struct tabuleiro{
int status;//Se 1 a peça está lá.
int cor;// Se 0 a peça é vermelha, e se 1 a peça é azul.
int tipo; // Se 0 é peça normal se 1 é dama
char show;//Caractere a ser mostrado: 'o' para peça que existe e '.' para representar a ausência de peça.
};

void setColor(int textColor, int bgColor) {//tava tentando fazer com cores mas abandonei a ideia por enquanto
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void inicializarTabuleiro(struct tabuleiro x[8][8]){

int i, j;
int textColor = 7;
int bgColor = 0;

setColor(textColor, bgColor);

    // Inicializa as posicoes com espa os vazios
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            x[i][j].show = '.';
            x[i][j].status = 0;
        }
    }

    // Coloca as pecas vermelhas e azuis nas posicoes iniciais
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((i % 2 != j % 2) && (i < 3)) {
                x[i][j].show = 'v'; // Peças vermelhas
                x[i][j].status = 1;
                x[i][j].cor = 0;
                x[i][j].tipo = 0;
            } else if ((i % 2 != j % 2) && (i > 4)) {
                x[i][j].show = 'a'; // Peças azuis
                x[i][j].status = 1;
                x[i][j].cor = 1;
                x[i][j].tipo = 0;
            }
        }
    }
}

void imprimirTabuleiro(struct tabuleiro x[8][8]) {
    int i, j;


    printf("    0 1 2 3 4 5 6 7\n");
    printf("  +-----------------+\n");
    for (i = 0; i < 8; i++) {
        printf("%d |", i);
        for (j = 0; j < 8; j++) {
            if ((i % 2 != j % 2) && (i < 3)) {

                printf(" %c", x[i][j].show);
            } else if ((i % 2 != j % 2) && (i > 4)) {

                printf(" %c", x[i][j].show);
            }
            else {

                printf(" %c", x[i][j].show);
            }


        }
        printf(" |\n");
    }
    printf("  +-----------------+\n\n");
}

void moverPeca(struct tabuleiro x[8][8], int color, int cd1, int cd2){
int cdm1, cdm2;
int loop = 1;


printf("MOVER PECA\n\n");


while(loop != 0){
printf("Digite a coordenada para mover a peca:\n");
printf("Linha: ");
scanf("%d", &cdm1);
printf("\n");
printf("Coluna: ");
scanf("%d", &cdm2);
printf("\n");


if(color == 0){//vermelho


    if(cdm1 - cd1 == 1 && (cdm2 - cd2 == 1 || cdm2 - cd2 == -1) && x[cdm1][cdm2].status == 0){
        x[cd1][cd2].show = '.';
        x[cd1][cd2].status = 0;
        x[cdm1][cdm2].show = 'v';
        x[cdm1][cdm2].status = 1;
        x[cdm1][cdm2].cor = 0;

        imprimirTabuleiro(x);
        loop = 0;
    }

    else if(cdm1 - cd1 == 2 && (cdm2 - cd2 == 2 || cdm2 - cd2 == -2) && (x[cdm1][cdm2].status == 0 && (x[cdm1-1][cdm2-1].status == 1 || x[cdm1-1][cdm2+1].status == 1))){
        x[cd1][cd2].show = '.';
        x[cd1][cd2].status = 0;
        x[cdm1][cdm2].show = 'v';
        x[cdm1][cdm2].status = 1;
        x[cdm1][cdm2].cor = 0;

        if(cdm2 - cd2 == -2){
            x[cdm1-1][cdm2+1].show = '.';
            x[cdm1-1][cdm2+1].status = 0;
        }
        else{
            x[cdm1-1][cdm2-1].show = '.';
            x[cdm1-1][cdm2-1].status = 0;
        }

        imprimirTabuleiro(x);
        loop = 0;
    }

    else{
        printf("Movimento invalido!\n\n");
    }

}

else{//azul
    if(cdm1 - cd1 == -1 && (cdm2 - cd2 == 1 || cdm2 - cd2 == -1) && x[cdm1][cdm2].status == 0){
        x[cd1][cd2].show = '.';
        x[cd1][cd2].status = 0;
        x[cdm1][cdm2].show = 'a';
        x[cdm1][cdm2].status = 1;
        x[cdm1][cdm2].cor = 1;

        imprimirTabuleiro(x);
        loop = 0;
    }

    else if(cdm1 - cd1 == -2 && (cdm2 - cd2 == 2 || cdm2 - cd2 == -2) && (x[cdm1][cdm2].status == 0 && (x[cdm1+1][cdm2+1].status == 1 || x[cdm1+1][cdm2-1].status == 1))){
        x[cd1][cd2].show = '.';
        x[cd1][cd2].status = 0;
        x[cdm1][cdm2].show = 'a';
        x[cdm1][cdm2].status = 1;
        x[cdm1][cdm2].cor = 1;

        if(cdm2 - cd2 == -2){
            x[cdm1+1][cdm2+1].show = '.';
            x[cdm1+1][cdm2+1].status = 0;
        }
        else{
            x[cdm1+1][cdm2-1].show = '.';
            x[cdm1+1][cdm2-1].status = 0;
        }

        imprimirTabuleiro(x);
        loop = 0;
    }

    else{
        printf("Movimento invalido!\n\n");
    }
}

}//fim de loop

}



void jogadorVermelho(struct tabuleiro x[8][8]){
int coordenada1, coordenada2;
int color = 0;//indicar a cor vermelha
int loop = 1;

while(loop != 0){

printf("JOGADOR VERMELHO\n\n");

printf("Digite a coordenada da peca:\n");
printf("Linha: ");
scanf("%d", &coordenada1);
printf("\n");
printf("Coluna: ");
scanf("%d", &coordenada2);
printf("\n");

if(x[coordenada1][coordenada2].status == 1 && x[coordenada1][coordenada2].cor == color){
    printf("[%d][%d]cd\n\n", coordenada1, coordenada2);
    moverPeca(x, color, coordenada1, coordenada2);
    loop = 0;
}
else{
    printf("Peca nao encontrada!\n");
    printf("[%d][%d]cd\n\n", coordenada1, coordenada2);
}

}//fim do loop

}

void jogadorAzul(struct tabuleiro x[8][8]){
int coordenada1, coordenada2;
int color = 1;//indicar a cor azul
int loop = 1;

while(loop != 0){

printf("JOGADOR AZUL\n\n");

printf("Digite a coordenada da peca:\n");
printf("Linha: ");
scanf("%d", &coordenada1);
printf("\n");
printf("Coluna: ");
scanf("%d", &coordenada2);
printf("\n");

if(x[coordenada1][coordenada2].status == 1 && x[coordenada1][coordenada2].cor == color){
    printf("[%d][%d]cd\n\n", coordenada1, coordenada2);
    moverPeca(x, color, coordenada1, coordenada2);
    loop = 0;
}
else{
    printf("Peca nao encontrada!\n");
    printf("[%d][%d]cd\n\n", coordenada1, coordenada2);
}

}//fim do loop

}

int main (){

int continuar = 1;

struct tabuleiro x[8][8];

inicializarTabuleiro(x);
imprimirTabuleiro(x);

while(continuar != 0){
    jogadorVermelho(x);
    jogadorAzul(x);
}

return 0;
}

