#include <stdio.h>
int main()
{
char nombre[16];
char primero[9]="ahorcado";
char segundo[16]="hundir la flota";
char tercero[5]="stop";
char a,r;
int i=0,b;

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
			break;
		case 'H':
		case 'h':
			printf("Usted ha elegido HUNDIR LA FLOTA\n");
			printf("Bienvenido a hundir la flota, pulse 'R' si quiere saber las reglas del juego\n");
			scanf("%c",&r);
			if(r=='R')
			{
			printf("El  juego  consiste  en  hundir  la  flota  del contrincante(el programa).\n Para  ello,  debe  colocar  su propia flota de forma estratégica y encontrar y hundir con los disparos la flota contraria\n");
			printf("Cada  uno  de  los  jugadores  dispone  de  dos  cuadrículas : en una debe colocar sus barcos y en la otra irá anotando los resultados de los disparos que realiza en cada turno\n");
			printf("Cada jugador  debe  colocar  en uno  de  los cuadros los  siguientes  barcos en  posición horizontal o vertical\n");
			printf(" 1 barco que ocupa 4 cuadrados.\n 1 barcos de tres cuadros.\n 2 barcos de 2 cuadros.\n 2 barcos que ocupe 1 cuadro ");
			printf("Cada jugador spone de un turno de disparo que se irá alternando\n. Para hacerlo dirá las coordenadas.  Por  ejemplo “B3”, significa que su disparo corresponde a la casilla que se encuentra en esa coordenada. ");
		    }
		    
			break;
		case 'S':
		case 's':
			printf("Usted ha elegido STOP");
			break;
		default: 
		    printf("Error. pulse de nuevo la tecla\n");
		    b=0;
	}
	}
	while (b==0);


	return 0;
}
