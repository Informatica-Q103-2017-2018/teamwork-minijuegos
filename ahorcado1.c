#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char palabra[15],rep[60],tmp[100];
char matriz[9][7]={
 "____",
 "|  |",
 "|  |",
 "|   ",
 "|   ",
 "|   ",
 "|   ",
 "|   ",
 "----",
};
	typedef struct
	{
int pos;
int j;
char c;
} cuerpo;

int main() {

    char lt;
    int longi,i,n,r,k,j,inicio,correcto=0,temp=0,oportunidades=7;
    int repetido=0,gano=0;
    cuerpo o[] ={
				{3, 3, 'O'},
				{4, 3,'|'}, 
				{4, 2,'/'},
				{4, 4,'\\'},
				{5, 3, '|'},
				{6, 2,'/'},
				{6, 4,'\\'}
				};

    printf("\tEl Ahorcado\n");
    printf("Introduzca la palabra que quiere adivinar: \n");
    for(i=0;i<9;i++){
		printf("%s\n",matriz[i]);
	}

	gets(palabra);
    
    longi = 0;
    inicio = 0;
    k = 0;
    
    rep[0] = ' ';
    rep[1] = '\0';
    
    printf("Introduzca una letra:");
    scanf("\n%c",&lt);
    do {
        temp = 0;
        tmp[0]=0;
    
        if(inicio == 0) 
		{
         for(i=0;i<strlen(palabra);i++) 
		 {
          if(palabra[i] == ' ') {
            palabra[i] = ' ';
             longi++;
          }
          else {
             tmp[i] = '_';        
             longi++;
          }
         }
        }
    
        inicio = 1;
        
        tmp[longi] = '\0';
        
        for(i=0;i<strlen(rep);i++) {
           if(rep[i] == lt) {
            repetido = 1;
            break;
          } 
          else {
           repetido = 0;
         }
        }
        
        if(repetido == 0) {
         for(i=0;i<strlen(palabra);i++) {
                    if(palabra[i] == lt) {
             tmp[i] = lt;
              correcto++;
              temp = 1;
            } 
          }
        }
        
        if(repetido == 0) {
         if(temp == 0) {
           matriz[o[7-oportunidades].pos][o[7-oportunidades].j] = o[7-oportunidades].c;
           oportunidades = oportunidades - 1;
         }
        }
        else {
         printf("este caracter esta repetido");
         printf("\n\n");
        }
        
        printf("\n");
        
        for(i=0;i<strlen(tmp);i++) {
         printf(" %c ",tmp[i]);
        }
        
        printf("\n");
        
        if(strcmp(palabra,tmp) == 0) {
            gano = 1;
            break;
        }
        
        printf("\n");
        printf("Letras Acertadas: %d",correcto);
        printf("\n");
        printf("Oportunidades Restantes: %d",oportunidades);
        printf("\n");
    
        rep[j] = lt;
        k++;
        
        if (oportunidades==0)
        {
           break;
        } 
      	for(i=0;i<9;i++){
		printf("%s\n",matriz[i]);
		}
        printf("Introduzca una letra:");
        scanf("\n%c",&lt);
       
    }while(oportunidades != 0); 
    
    
    if(gano) {
                printf("\n\n");
        printf("Te has pasado el juego");
    }
    else {
                printf("\n\n");
        for(i=0;i<9;i++){
		printf("%s\n",matriz[i]);
		}
        printf("Game over");
    }
    
    printf("\n\n");
    return 0;

}  
