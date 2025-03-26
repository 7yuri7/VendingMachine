#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//#ifdef _WIN32
//#include<windows.h>
//#else

//#endif

typedef struct
{
    char nome[20];
    float preco;
    int estoque;
}Produto;

void load();
void exibirProd(const int Max_prod, Produto *maquina[]);

int main(){
   Produto itens[] = {
        {"coca-cola",10.5,35},
        {"miojo",2,32},
        {"pimenta",2,34},
        {"Carne de jacaré",35.5,23},
        {"panela de pressão",56, 35}
   };
   load();
   const int Max_prod = sizeof(itens) / sizeof(Produto);
   Produto *maquina[Max_prod];
   for (int i=0;i < Max_prod;i++){
        maquina[i] = &itens[i];
   }
   exibirProd(Max_prod, maquina);
   
   return 0;
}

void load() {
    int load = 0;
   //printf("\033[H\033[J"); 
    system("clear");
    printf("   Loading\n");
    printf("(");
    do {
        printf("0");
        fflush(stdout);     
        load++;
        sleep(1); 
    } while (load <= 10);
    printf(")\n");
}

void exibirProd(const int Max_prod, Produto *maquina[]){
    for(int i=0;i < Max_prod;i++){
        printf("%d. %s |%d|\n", i+1, maquina[i]->nome, maquina[i]->estoque);
    }
}
