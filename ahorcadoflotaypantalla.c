#include <stdio.h>
#include <stdlib.h>
#include <locale.h>// esto es para las tildes
#include <time.h>
#include <conio.h>//La funcion getche() lee caracter a caracter y muestra por pantalla el caracter leido.
#include <string.h>
// esta funcion la voy a usar en la flota pero os la dejo aqui para el stop
void wait(int seconds) // Funcion que empieza a contar el tiempo desde que el programa se enciende
{
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while( clock() < endwait )
    {}
}
//__________________________________________________________________________________________________________
// DEFINO FUNCIONES DE LA FLOTA
void imprimir();
void ataques();
//_________________________________________________________________________________________________________
// VARIABLES GENERALES DE LA FLOTA
int i, j, k, jugador[6][10], programa[6][10], opcion1, opcion2, puntajeprograma=0,puntajejugador=0;
time_t start,end;
double dif, tiempototal=0;
//_________________________________________________________________________________________________________
//VARIABLES GENERALES DEL AHORCADO
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
//DEFINIMOS VARIABLES 
int main()
{
setlocale(LC_CTYPE,"Spanish");// esto tambien es para poner las tildes
   char a,r;
int c,b;
//VARIABLES DE LA FLOTA
 int  auxiliar, destruidosprograma=0, destruidosjugador=0;

	printf("MINIJUEGOS\n\n");
	printf("NOTA: CUALQUIERA DE LOS JUEGOS PUEDE PEDIRLE AL USUARIO UN REGISTRO PREVIO.\n\n\n");
	printf("AHORCADO\t\t\tHUNDIR LA FLOTA\t\t\tSTOP\n\n\n");
	
//VARIABLES AHORCADO
//definimos las variables y el cuerpo de la matriz
    char lt;
    int longi,i,n,r,k,j,inicio,correcto=0,temp=0,oportunidades=7;
    int repetido=0,gano=0;
    cuerpo o[] ={{3, 3, 'O'},{4, 3,'|'}, {4, 2,'/'},
{4, 4,'\\'},{5, 3, '|'},{6, 2,'/'},{6, 4,'\\'}};

	typedef struct
{
char nombre[50], pregunta[50], experiencia[10] , ganar[10];
int matricula, edad;
}
ficha;
ficha usuario;
char opcion;
FILE *pf;
pf=fopen("alumnos.txt", "wb");
do
{
fflush(stdin);
printf("\nNombre de usuario: ");
gets(usuario.nombre);
printf("�Has jugado alguna vez?: ");
gets(usuario.pregunta);
printf("\�Te ves capacitado para pasar la mejor experiencia de tu vida?:");
gets(usuario.experiencia);
printf("Ganar�s....? ");
gets(usuario.ganar);
printf("Edad: ");
scanf("%d", &usuario.edad);
printf("Numero de matricula: ");
scanf("%d", &usuario.matricula);
fwrite(&usuario, sizeof(ficha), 1, pf);
fflush(stdin);
printf("\nMas usuarios (s/n)?\n");
scanf("%c", &opcion);
}
while (opcion=='s');
fclose(pf);
do 
{
	b=1;
	printf("\t Escriba 'A' si quiere jugar a AHORCADO\n\t Escriba 'H' si quiere jugar a HUNDIR LA FLOTA\n\t Escriba 'S' si quiere jugar a STOP)\n");
	scanf("%c",&a);
	fflush(stdin);// CHICAS ESTO ES PARA RESETEAR EL TECLADO Y QUE NO SE ME GUARDE EL ENTER EN EL SIGUIENTE SCANF
	system("cls"); // Limpia la pantalla
	switch(a)
	{
		case 'A':
		case 'a':
			printf("Usted ha elegido AHORCADO\n");
			printf("Bienvenido al ahorcado, pulse 'R' si quiere saber las reglas del juego\n");
			scanf("%c",&r);
			if(r=='R')
			{
				printf("El objetivo de este juego es descubrir una palabra adivinando las letras que la componen.\n");
				printf("A cada ronda, los jugadores escoger�n simult�neamente una letra que crean que pueda formar parte de la palabra.");
				printf("Si la palabra contiene la letra escogida, se mostrar� en qu� posici�n/es est�.\n");
				printf("En el caso de que la letra no exista en la palabra, se dibujar� una parte del cuerpo del mu�eco del jugador. \nCuando est�n dibujadas las 6 partes del cuerpo del mu�eco, el jugador se quedar� fuera de la partida.");
		        
	    	}
	    	printf("\n\n\n\t\tPulse 1 para jugar\n\n\n\t\tPulse 2 para salir\n");
		    scanf("%i", &c);
            //Mostramos la matriz por pantalla
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
    //pedimos al usuario una letra hasta que la palabra sea completada correctamente
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
           if(rep[i] == lt) { //este bucle sirve por si la letra introducida ya lo habia sido
            repetido = 1;
            break;
          } 
          else {
           repetido = 0;
         }
        }
        
        if(repetido == 0) {
         for(i=0;i<strlen(palabra);i++) { //en caso de que la letra no haya sido introducida anteriormente y sea correcta el juego se actualiza
                    if(palabra[i] == lt) {
             tmp[i] = lt;
              correcto++;
              temp = 1;
            } 
          }
        }
        
        if(repetido == 0) {
         if(temp == 0) {
           matriz[o[7-oportunidades].pos][o[7-oportunidades].j] = o[7-oportunidades].c; //si la letra no esta repetida pero es incorrecta se resta una oportunidad
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
        
        if (oportunidades==0) //si las oportunidades han acabado y no se ha completado la palabra el bucle se cierra y aparece el mensaje de game over
        {
           break;
        } 
      	for(i=0;i<9;i++){
		printf("%s\n",matriz[i]);
		}
        printf("Introduzca una letra:");
        scanf("\n%c",&lt);
       
    }while(oportunidades != 0); //si las oportunidades no se han acabado y has acertado la palabra saldra en pantalla que has ganado
    
    
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
		break;
		case 'H':
		case 'h':
			printf("Usted ha elegido HUNDIR LA FLOTA\n");
			printf("Bienvenido a hundir la flota, pulse 'R' si quiere saber las reglas del juego\n");
			scanf("%c",&r);
			if(r=='R')
			{
			 printf("El  juego  consiste  en  hundir  la  flota  del contrincante(el programa).\n Para  ello,  debe  colocar  su propia flota de forma estrat�gica y encontrar y hundir con los disparos la flota contraria\n");
			 printf("Cada jugador  debe  colocar  en uno  de  los cuadros los  barcos \n");
			 printf("Cada jugador pone de un turno de disparo que se ir� alternando.\n Para hacerlo dir� las coordenadas.  Por  ejemplo �B3�, significa que su disparo corresponde a la casilla que se encuentra en esa coordenada. ");
		    } 
		    printf("\n\n\n\t\tPulse 1 para jugar\n\n\n\t\tPulse 2 para salir");
		    scanf("%i", &c);
		    fflush(stdin);
		        switch(c)
                  { 
                     case 1:
                     {
                     	ataques(); // Llama a la funcion iniciar
                        printf("\n\n\n\t\t Preparado?\n\n");
                        wait(3);
                             
                          do
                          {
                             time(&start);
                             system("cls"); // Limpia la pantalla
                               
                             imprimir();
                               
                             printf(" Es tu turno! Dame la posicion que deseas atacar~\n\n");
                             printf("\tX = ");
                             scanf("%d", &opcion2);
                                 while(opcion2<1 || opcion2>9)
                                 {
                                   printf("\n    Escoje un valor valido ( 1 a 9 )\n\n\tX = ");
                                  scanf("%d", &opcion2);
                                 }
                               
                             printf("\tY = ");
                             scanf("%d", &opcion1);
                                 while(opcion1<1 || opcion1>5)
                                 {
                                   printf("\n    Escoje un valor valido ( 1 a 5 )\n\n\tY = ");
                                   scanf("%d", &opcion1);
                                 }
                             auxiliar=programa[opcion1][opcion2];
                             programa[opcion1][opcion2]=3;
                             imprimir();
                             programa[opcion1][opcion2]=auxiliar;                          
                               
                                 if(programa[opcion1][opcion2]==1)
					               {
					                   programa[opcion1][opcion2]=2;// has destruido uno de los barcos del programa
					                   destruidosprograma=destruidosprograma+1;// sumamos un barco destruido del programa
					                   puntajejugador=puntajejugador+200;// sumamos tu puntuacion
					                   printf("\n Haz acertado!!\n\n");
					               }
						         else
						            {
						               printf("\n Haz fallado...\n\n");
						            }
						                               
				               system("PAUSE");
				               system("cls");
				               if(destruidosprograma==5)// si destruyes todos los barcos del oponente has ganado
				               {
				                   fflush (stdin);// vuelvo a borrar porque sino no me aparece el printf
				                   printf("\n\n\n\n\t\t\tHAZ GANADO!!");
				                   getche();
				               }                                                                
				               imprimir();
				                               
				               printf(" Turno del oponente!~\n\n");
				               wait(2);
				               
				               jugador[i][j]=3;
				               opcion1=i;
				               opcion2=j;
				               imprimir();
				               jugador[opcion1][opcion2]=auxiliar;
				             
				               if(jugador[opcion1][opcion2]==1)
				               {
				                   printf("\n El oponente ha acertado!!\n\n");
				                   jugador[opcion1][opcion2]=2;
				                   destruidosjugador=destruidosjugador+1;
				                   puntajeprograma=puntajeprograma+200;
				               }
				               else
				               {
				                   printf("\n El oponente ha fallado...\n\n");
				               }
				               if(destruidosjugador==5)
				               {    
							       fflush(stdin);// vuelvo a borrar porque sino no me aparece el printf                                        
				                   printf("\n\nHAS PERDIDO!!");
				                   printf("\nM�S SUERTE LA PR�XIMA VEZ\n");
				                   
				               }
				               system("PAUSE");
				               time(&end);
                             }
                         while(destruidosprograma<5 || destruidosjugador<5);       	
                    break;
                     }
                     case 2:
                     	return 0;
                    break;
		           }
		    
			break;
		case 'S':
		case 's':
			printf("Usted ha elegido STOP");
				printf("Usted ha elegido STOP\n");
			printf("Bienvenido a stop, pulse 'R' si quiere saber las reglas del juego\n");
			scanf("%c",&r);
			if(r=='R')
			{
			 printf("El objetivo del juego ser� obtener la mayor puntuaci�n posible.\n Aparecer� una letra aleatoria y el jugador deber� escribir una palabra de cada categor�a\n");
			 printf("La palabra introducida por el jugador ser� puntuada si el prograa la considera apta");
			}
			break;
		default: 
		    printf("Error. pulse de nuevo la tecla\n");
		    b=0;
	}
}
	
	while (b==0);


	return 0;
}
//______________________________________________________________________________________________________________________
//FUNCIONES DE LA FLOTA
void imprimir() // Funcion que imprime el tablero de juego
{  
    printf("Tiempo transcurrido= %.1f segundos\n\n", tiempototal);
     
    for(i=1;i<=5;i++) // Imprime tablero del programa
    {
        printf("\n\t");
        for(j=1;j<=9;j++)
        {
            if(programa[i][j]==3)// donde ha disparado 
            {
                printf("  #");
            }
            else
            {
                if(programa[i][j]==2) // barco destruido
                {
                    printf("  X");
                }
                else
                {
                    printf("  -");// pintar el espacio vacio
                }
            }                                    
        }
        if(i==3)
        {
            printf("\tTablero del programa"); 
        }
        else
         {
            if(i==1)
            {
                printf("\t\t\tPuntos del programa: %d", puntajeprograma);
            }
        }
       
    }
     
    printf("\n\n\n\n");
     
    for(i=1;i<=5;i++) // Imprime el tablero del jugador
    {
        printf("\n\t");
        for(j=1;j<=9;j++)
        {
            if(jugador[i][j]==3)// donde has disparado
            {
                printf("  #");
            }
            else
            {
                if(jugador[i][j]==2) //barco destruido 
                {
                    printf("  X");
                }
                else
                {
                    if(jugador[i][j]==1)
                    {
                        printf("  O");// imprime tu barco
                    }
                    else
                    {
                        printf("  -");// pinta el espacio vacio
                    }
                }
            }                                    
        }
        if(i==3)
        {
            printf("\tTablero del jugador");
        }
        else
        {
            if(i==1)
            {
                printf("\t\t\tPuntos del jugador: %d", puntajejugador);
            }
        }
    }
 
    printf("\n\n");  
}

void ataques() 
{
         
    for(i=1;i<=5;i++) 
    {
        for(j=1;j<=9;j++)
        {
            jugador[i][j]=0;
            programa[i][j]=0;
        }
    }
     
    printf("\n\nIntroduzca las coordenadas de sus barcos\n\n");
     
    srand(time(NULL));// inicia el generador de n�meros aleatorios
    for(k=1;k<=5;k++) // Distribuye los barcos
    {
        imprimir();
                       
        i=1+rand()%5; //da las coordenadas del programa de manera aleatoria
        j=1+rand()%9;
        while(programa[i][j]==1)
        {
            i=1+rand()%5; j=1+rand()%9;
        }
        programa[i][j]=1; //las coordenadas tendran un barco del oponente
                       
        printf("\n\tX%d = ", k);
        scanf("%d", &opcion2);
        while(opcion2<1 || opcion2>9) //le vuelvo a pedir la coordenada x porque se ha salido del tablero
        {
            printf("Escoja un valor valido ( 1 a 9 )\n\n\tX%d = ", k);
            scanf("%d", &opcion2);
        }
                         
        printf("\n\tY%d = ", k);
        scanf("%d", &opcion1);
        while(opcion1<1 || opcion1>5)//le vuelvo a pedir la coordenada y porque se ha salido del tablero
        {
            printf("\nEscoja un valor valido( 1 a 5 )\n\n\tY%d = ", k);
            scanf("%d", &opcion1);
        }
                         
        if(jugador[opcion1][opcion2]==1)
        {
        	fflush(stdin);// vuelvo a borrar porque sino no me aparece el printf
            printf("\n Ya hay un barco en esa posicion\n");
            getchar();
            k=k-1;//para que vuelva a pedirme el valor repetido
        }
        jugador[opcion1][opcion2]=1;
                       
        system("cls");//borro la pantalla
                                                         
    }  
}
