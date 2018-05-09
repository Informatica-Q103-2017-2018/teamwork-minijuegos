#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char palabra[15],rep[60],tmp[100];
char matriz[9][7]={
 "____",
 "|  |",
 "|  |",
 "|",
 "|",
 "|",
 "|",
 "|",
 "----",
};
	struct cuerpo
	{
 int s;
 char part[5];
}
cuerpo[7]={{3,"O"},{4,"/"},{4,"|"},
{4,"\\"},{5,"|"},{6,"/"},{6,"\\"}};

int main() {

    char lt;
    int longi,i,n,r,k,j,inicio,correcto=0,temp=0,oportunidades=7;
    int repetido=0,gano=0;
    
    printf("\tEl Ahorcado\n");
    printf("Introduzca la palabra que quiere adivinar: ");
    printf(" %d", matriz[9][7]);
   
for(i=0;i<9;i++)
{
for(j=0;j<7;j++)
{
printf("%s",matriz[j]);
}
printf("\n");
}
	gets(palabra);
    
    
    longi = 0;
    inicio = 0;
    k = 0;
    
    rep[0] = ' ';
    rep[1] = '\0';
    
    
    do {
                
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
              tmp[i]=1;
            } 
          }
        }
        
        if(repetido == 0) {
         if(tmp == 0) {
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
      
        printf("Introduzca una letra:");
        scanf("\n%c",&lt);
       
    }while(oportunidades != 0);
    
    
    if(gano) {
                printf("\n\n");
        printf("Te has pasado el juego");
    }
    else {
                printf("\n\n");
        printf("Game over");
    }
    
    printf("\n\n");
    return 0;

}  
