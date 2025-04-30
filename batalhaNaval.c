/*fiz no vs code e joguei aqui!
obs. ainda tentando implementar a logica dos outros efeitos*/




#include <stdio.h>


#define linha 10
#define coluna 10

int iniciaTabuleiro(int tabuleiro[linha][coluna]){ //iniciando tabuleiro
    for(int i = 0; i<linha; i++){
        for(int j = 0 ; j < coluna; j++){
            tabuleiro[i][j] = 0; // o "0" representa a agua no tabuleiro
        }
    }
}

void imprimeTabuleiro(int tabuleiro [linha][coluna]){
    printf("   ");
    for(int i = 0; i < linha; i++){ //estrutura para adcionar as colunas de 'A' a 'J'
        printf(" %c ", 'A' + i);
    }
    printf("\n");
        for(int i = 0  ; i < linha; i++){ //estrutura para criar as linhas de 0 a 9
            printf(" %d ", i);
            for(int j= 0; j < coluna; j++){
                printf(" %d ", tabuleiro[i][j]); //imprime o tabuleiro completo
            }
            printf("\n");
        }     
       
}


void PosicionarNavio(int tabuleiro[linha][coluna]){
    for(int i = 5; i <= 7; i++){ //adciona um navio na vertical que na coluna 'i' que ocupa a linha 5, 6, 7.
        tabuleiro[i][8] =  3;
        }

    for(int j = 5; j <= 7 ; j++){  //adciona um navio na horizontal  na linha 9 que ocupa as colunas 'F' 'H' 'G'
        tabuleiro[9][j] = 3;
    }
   
    for(int i = 4; i <=6; i++){ // adciona navio na diagonal nas linhas 4, 5, 6 e ocupa colunas 'C' 'D' 'E'
        for(int j=i; j<=i; j++){
            tabuleiro[i][j-2] = 3;
        }
    }

    for(int i = 2; i<=4; i++){ // adciona um navio na diagonal nas linhas 2, 3, 4 e ocupa as colunas 'H' I' 'J'
        tabuleiro[i][1-i] = 3 ;      
    }   
    
} 

void posicionarPoder(int tabuleiro[10][10]){
     for (int i = 0; i < 4; i++) {
        for (int j = 5 - 1 - i; j <= 3 - 1 + i; j++) { // posiciona a habilidade em formato de cone 
            tabuleiro[i][j] = 5;
        }
    }
 

}


int main(){

    printf("     _____ BATALHA NAVAL _____\n");
    int tabuleiro[linha][coluna];
    iniciaTabuleiro(tabuleiro);
    PosicionarNavio(tabuleiro);
    posicionarPoder(tabuleiro);
    imprimeTabuleiro(tabuleiro);
    return 0 ;
}