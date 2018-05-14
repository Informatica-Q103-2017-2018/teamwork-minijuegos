#include <stdio.h>
#include <stdlib.h>
#include <locale.h>// esto es para las tildes
#include <time.h>
#include <conio.h>//La funcion getche() lee caracter a caracter y muestra por pantalla el caracter leido.
#include <string.h>

int main()
{
setlocale(LC_CTYPE,"Spanish");// esto tambien es para poner las tildes
   char a,r;
int c,b;

	printf("MINIJUEGOS\n");
	printf("NOTA: CUALQUIERA DE LOS JUEGOS PUEDE PEDIRLE AL USUARIO UN REGISTRO PREVIO.\n");
	printf("AHORCADO\t\t\tHUNDIR LA FLOTA\t\t\tSTOP\n");
	
do 
{
	b=1;
	printf("Escriba 'A' si quiere jugar a AHORCADO\n escriba 'H' si quiere jugar a HUNDIR LA FLOTA\n escriba 'S' si quiere jugar a STOP)\n");
	scanf("%c",&a);
	fflush(stdin);// CHICAS ESTO ES PARA RESETEAR EL TECLADO Y QUE NO SE ME GUARDE EL ENTER EN EL SIGUIENTE SCANF
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
				printf("A cada ronda, los jugadores escogerán simultáneamente una letra que crean que pueda formar parte de la palabra.");
				printf("Si la palabra contiene la letra escogida, se mostrará en qué posición/es está.\n");
				printf("En el caso de que la letra no exista en la palabra, se dibujará una parte del cuerpo del muñeco del jugador. \nCuando estén dibujadas las 6 partes del cuerpo del muñeco, el jugador se quedará fuera de la partida.");
			}
			// Posiciones: '0'=desocupado | '1'=Hay barco | '2'=Barco destruido

			break;
		case 'H':
		case 'h':
			printf("Usted ha elegido HUNDIR LA FLOTA\n");
			printf("Bienvenido a hundir la flota, pulse 'R' si quiere saber las reglas del juego\n");
			scanf("%c",&r);
			if(r=='R')
			{
			 printf("El  juego  consiste  en  hundir  la  flota  del contrincante(el programa).\n Para  ello,  debe  colocar  su propia flota de forma estratégica y encontrar y hundir con los disparos la flota contraria\n");
			 printf("Cada jugador  debe  colocar  en uno  de  los cuadros los  barcos \n");
			 printf("Cada jugador pone de un turno de disparo que se irá alternando\n. Para hacerlo dirá las coordenadas.  Por  ejemplo “B3”, significa que su disparo corresponde a la casilla que se encuentra en esa coordenada. ");
		    }
		    printf("\nPulse 1 para jugar\nPulse 2 para salir");
		    scanf("%i", &c);
		    fflush(stdin);
		        switch(c)
                  { 
                     case 1:
                     {
                     	
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
			 printf("El objetivo del juego será obtener la mayor puntuación posible.\n Aparecerá una letra aleatoria y el jugador deberá escribir una palabra de cada categoría\n");
			 printf("La palabra introducida por el jugador será puntuada si el prograa la considera apta");
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



